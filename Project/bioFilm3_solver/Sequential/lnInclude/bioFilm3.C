/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | foam-extend: Open Source CFD
   \\    /   O peration     | Version:     3.2
    \\  /    A nd           | Web:         http://www.foam-extend.org
     \\/     M anipulation  | For copyright notice see file Copyright
-------------------------------------------------------------------------------
License
    This file is part of foam-extend.

    foam-extend is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation, either version 3 of the License, or (at your
    option) any later version.

    foam-extend is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with foam-extend.  If not, see <http://www.gnu.org/licenses/>.

Application
    bioFilm3

Description
    my first try to solve biofilm model without navier-stokes equations.

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{

#   include "setRootCase.H"

#   include "createTime.H"
#   include "createMesh.H"
#   include "createFields.H"


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

    Info<< "\nCalculating scalar transport\n" << endl;

//#   include "CourantNo.H"

    while (runTime.loop())
    {
        Info<< "Time = " << runTime.timeName() << nl << endl;

#       include "readSIMPLEControls.H"

#	include "extraVariables.H"

        for (int nonOrth=0; nonOrth<=nNonOrthCorr; nonOrth++)
        {

	 Info<< "solving phin\n" << endl;
            solve
            (
                fvm::ddt(dim3,phin) ==
                fvm::div(dim1*phi, phin)
	      + fvm::Sp(volgn,phin)
              + fvm::laplacian(dim2*surftemp1,phin)
              + fvm::laplacian(dim2*surftemp2,phin)
	      - fvc::laplacian(dim2*Lambda*phin,fvc::laplacian(dim2*Gamma_1,phin))
            );

volScalarField phis("phis", scalar(1)-phin);
//////////////  gc=A*phin*c/(K_1+c) ///////////////
volScalarField volgc("volgc", A*phin/(K_1+c));
//////////////////////////////

	 Info<< "solving c\n" << endl;

             solve
            (
                fvm::ddt(dim3*phis,c)
              + fvm::div(dim1*phi, c) ==
                fvm::laplacian(dim2*D_s*phis,c)
	      - fvm::Sp(volgc,c)

            );
        }

        runTime.write();
 	Info<< "ExecutionTime = " << runTime.elapsedCpuTime() << " s"
            << "  ClockTime = " << runTime.elapsedClockTime() << " s"
            << nl << endl;
    }
    
   
    Info<< "End\n" << endl;


    return 0;
}


// ************************************************************************* //
