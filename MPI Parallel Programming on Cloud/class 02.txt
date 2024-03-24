#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[])
{
int rank, nprocs;
MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&nprocs);
if(rank == 0){
printf("The number of processors in the group  is %d.\n",nprocs);
}
if(rank % 2 == 1){
printf("Processor number %d!\n",rank);
}
else{printf("I am not processor 0 or odd  number, my Id is %d.\n",rank);}
MPI_Finalize();

return 0;
}
