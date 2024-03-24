#include <stdio.h>
#include <mpi.h>
#define comm MPI_COMM_WORLD

int main(int argc, char* argv[])
{

int rank, nprocs;
int a = 1,flag;

MPI_Init(&argc,&argv);

MPI_Request request;
MPI_Status status;
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&nprocs);

if (rank==0){
a =10;
MPI_Isend(&a,1,MPI_INT,1,5,comm,&request);
}

if (rank==1){
MPI_Irecv(&a,1,MPI_INT,0,5,comm,&request);

MPI_Test(&request,&flag,&status);
printf("Flag = %d\n",flag);
if(flag==1)
MPI_Wait(&request,&status);

}

printf("Process id: %d Value of a: %d\n",rank,a);
MPI_Finalize();

return 0;
}
