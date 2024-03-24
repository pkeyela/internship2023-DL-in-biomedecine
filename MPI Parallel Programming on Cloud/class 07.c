#include <stdio.h>
#include <mpi.h>
#define comm MPI_COMM_WORLD

int main(int argc, char* argv[]){
int rank, a, S=0;

MPI_Init(&argc, &argv);
MPI_Comm_rank(comm, &rank);

a =  rank;
MPI_Reduce(&a,&S,1,MPI_INT,MPI_SUM,0,comm);

if (rank==4) printf("The process %d has received S = %d.\n",rank,S);

MPI_Finalize();

return 0;
}
