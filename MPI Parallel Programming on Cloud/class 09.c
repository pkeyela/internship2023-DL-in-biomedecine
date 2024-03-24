#include <stdio.h>
#include <mpi.h>
#define comm MPI_COMM_WORLD

int main(int argc, char* argv[]){
int rank, A = 0,N = 23, np;
int imin, imax, delta, ost, i;

MPI_Init(&argc, &argv);
MPI_Comm_rank(comm, &rank);
MPI_Comm_size(comm,&np);

delta = N/np;
imin = rank *delta;
imax = (rank + 1)* delta;
ost = N % np;

if (rank == np-1)
imax += ost;

for (i=imin; i<imax; i++){
A += 1;
printf("Process id: %d, iteration: %d, Value of A: %d\n",rank,i,A);
}

MPI_Finalize();

return 0;
}
