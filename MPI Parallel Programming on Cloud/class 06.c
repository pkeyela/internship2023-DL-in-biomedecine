#include <stdio.h>
#include <mpi.h>
#define comm MPI_COMM_WORLD

int main(int argc, char* argv[]){
int rank, a[7];
int i;

MPI_Init(&argc, &argv);
MPI_Comm_rank(comm, &rank);
if (rank==1)
for(i=0;i<7;i++)
a[i] =  i+1;
MPI_Bcast(&a,7,MPI_INT,1,comm);


printf("Receiver id: %d   Array a: ",rank);

for (i=0; i<7; i++)
printf("%d ",a[i]);

printf("\n");

MPI_Finalize();
}
