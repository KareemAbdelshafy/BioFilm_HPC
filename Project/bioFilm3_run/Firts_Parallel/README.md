To run the program in parallel.

1- you don't need to compile the solver again, which you should have done before in the sequential version as mentioned in /project/bioFilm3_solver/Sequential/README.  If you did, you will find an executable file called bioFilm3 inside your bin folder.

2- ask for 16 processors inside one node by typing (bsub -Is -n 16 -q ht-10g /bin/bash
)

3- inside bioFilm3_run/Firts_Parallel type decomposePar, for example 
[abdelshafy.k@compute-0-005 Firts_Parallel]$ decomposePar 

5- type mpirun -np 16 bioFilm3 -parallel > log & , for example
[abdelshafy.k@compute-0-005 Firts_Parallel]$ mpirun -np 16 bioFilm3 -parallel > log &

6- wait for the simulation to finish which may take 64 min. 

7- log out of the interactive session by typing exit in the terminal

8- check if the job is finished by typing bjobs

9- (optional) you don't have to wait for full simulation time. you can quit the running anytime and you will get partial results.

10- after the job is finished, to gather the results of each processor to one mesh, type reconstructPar. For example
[abdelshafy.k@compute-0-005 Firts_Parallel]$ reconstructPar

11- (optional) to see the results, type paraFoam, inside X11 forward shell
