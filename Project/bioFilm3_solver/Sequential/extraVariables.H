Info<< "\nReading Extra Variables\n" << endl;

/////////////////  temp1=-2*chi*Gamma_1*Lambda*phin  //////////////

volScalarField voltemp1("voltemp1", scalar(-2)*Gamma_2*chi*Lambda*phin.oldTime());

surfaceScalarField surftemp1("surftemp1",fvc::interpolate(voltemp1));
//////////////  gn=mu*phin*c/(K_c+c) ///////////////

volScalarField volgn("volgn", mu*c/(K_c+c));

//surfaceScalarField surfgn("surfgn",fvc::interpolate(volgn));
//////////////  temp2 =    ///////////////////
volScalarField voltemp2("voltemp2", Lambda*Gamma_2*(
        (scalar(1)/N)+
	(phin.oldTime()/(scalar(1)+deltaphin-phin.oldTime()))
));

surfaceScalarField surftemp2("surftemp2",fvc::interpolate(voltemp2));
//////////////  
