#include <stdio.h>
#include <mpi.h>
#define comm MPI_COMM_WORLD

int main(int argc, char* argv[])
{

int rank, nprocs, N = 5;
int x[] = {0,0,0,0,0}, y[] = {0,0,0,0,0};
int i ;
MPI_Init(&argc,&argv);

MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&nprocs);

if (rank==0){
for (i=0; i<N; i++){
x[i] = i + 1;
}}

MPI_Send(&x[0],N,MPI_INT,1,5,comm);


if (rank==1){
MPI_Status status;
MPI_Recv(&y[0],N,MPI_INT,0,5,comm,&status);
for (i=0; i<N; i++){
}}


printf("Process id: %d\n",rank);
printf("Array X: ");
for (i=0; i<N; i++){
printf("%d ",x[i]);
}
printf("\n");

printf("Array Y: ");
for (i=0; i<N; i++){
printf("%d ",y[i]);
}
printf("\n");


MPI_Finalize();

return 0;
}
