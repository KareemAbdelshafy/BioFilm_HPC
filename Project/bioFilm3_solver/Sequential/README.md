Instructions for compiling the squential solver

1- make a bin folder in your home directory. Note, you will need to provide the path of this folder in the export command inside your .bashrc as shown below.

2- add the following lines in your .bashrc 

source /shared/apps/openfoam/openfoam-2.3.1/OpenFOAM-2.3.1/etc/bashrc
module load gnu-4.4-compilers
module load gnu-4.8.1-compilers
module load fftw-3.3.3-single
module load fftw-3.3.3
module load mpich-3.0.4
module load platform-mpi
module load paraview-4.3.1
module load openfoam-2.3.1
export PATH=~/bin:$PATH

3- move folder project into your discovery account.

4- inside bioFilm3_solver/Sequential directory, type wmake to compile the solver. For example
	[abdelshafy.k@discovery4 Sequential]$ wmake

5- you should be an executable called bioFilm3 inside your ~/bin directory

6- Go to project/bioFilm3_run/Sequential and read README file to execute the solver.

