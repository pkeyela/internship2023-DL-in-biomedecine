#include <stdio.h>
#include <mpi.h>
#define comm MPI_COMM_WORLD

int main(int argc, char* argv[])
{

int rank, nprocs;
MPI_Init(&argc,&argv);
int a = 1;

MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&nprocs);

if (rank==0){
a =10;
MPI_Send(&a,1,MPI_INT,1,5,comm);
}

if (rank==1){
MPI_Status status;
MPI_Recv(&a,1,MPI_INT,0,5,comm,&status);
}

printf("Process id: %d Value of a: %d\n",rank,a);
MPI_Finalize();

return 0;
}
