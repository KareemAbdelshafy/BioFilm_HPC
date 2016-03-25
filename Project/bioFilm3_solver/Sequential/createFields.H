 Info<< "Reading field phin\n" << endl;

    volScalarField phin
    (
        IOobject
        (
            "phin",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );


    Info<< "Reading field c\n" << endl;

    volScalarField c
    (
        IOobject
        (
            "c",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

   Info<< "Reading field U\n" << endl;

    volVectorField U
    (
        IOobject
        (
            "U",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );  

//////////////////////////////
Info<< "Reading/calculating face flux field phi\n" << endl;

surfaceScalarField phi
(
    IOobject
    (
        "phi",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    linearInterpolate(U) & mesh.Sf()
);
//////////////////////////////

    Info<< "Reading transportProperties\n" << endl;

    IOdictionary transportProperties
    (
        IOobject
        (
            "transportProperties",
            runTime.constant(),
            mesh,
            IOobject::MUST_READ,
            IOobject::NO_WRITE
        )
    );



    Info<< "Reading diffusivity DT\n" << endl;

    dimensionedScalar Lambda
    (
        transportProperties.lookup("Lambda")
    );

    Info<< "Reading Gamma_1 \n" << endl;

    dimensionedScalar Gamma_1
    (
        transportProperties.lookup("Gamma_1")
    );

   Info<< "Reading Gamma_2 \n" << endl;

    dimensionedScalar Gamma_2
    (
        transportProperties.lookup("Gamma_2")
    );

   Info<< "Reading chi \n" << endl;

    dimensionedScalar chi
    (
        transportProperties.lookup("chi")
    );

   Info<< "Reading N \n" << endl;

    dimensionedScalar N
    (
        transportProperties.lookup("N")
    );

    Info<< "Reading D_s \n" << endl;

    dimensionedScalar D_s
    (
        transportProperties.lookup("D_s")
    );

    Info<< "Reading A \n" << endl;

    dimensionedScalar A
    (
        transportProperties.lookup("A")
    );

   Info<< "Reading mu \n" << endl;

    dimensionedScalar mu
    (
        transportProperties.lookup("mu")
    );

   Info<< "Reading K_1 \n" << endl;

    dimensionedScalar K_1
    (
        transportProperties.lookup("K_1")
    );

  Info<< "Reading K_c \n" << endl;

    dimensionedScalar K_c
    (
        transportProperties.lookup("K_c")
    );

  Info<< "Reading deltaphin \n" << endl;

    dimensionedScalar deltaphin
    (
        transportProperties.lookup("deltaphin")
    );

 Info<< "Reading dim1 \n" << endl;

    dimensionedScalar dim1
    (
        transportProperties.lookup("dim1")
    );

 Info<< "Reading dim2 \n" << endl;

    dimensionedScalar dim2
    (
        transportProperties.lookup("dim2")
    );
Info<< "Reading dim3 \n" << endl;

    dimensionedScalar dim3
    (
        transportProperties.lookup("dim3")
    );
