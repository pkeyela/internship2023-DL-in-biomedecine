#include <stdio.h>
#include <mpi.h>
#define comm MPI_COMM_WORLD

int main(int argc, char* argv[]){
int rank, N = 13, np;
int A[N], B[N], C[N], D[N];
int imin, imax, delta, ost, i;

for(i=0; i<N; i++){
A[i] = i+1;
B[i] = i*i + 2;
C[i] = 0;
}


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
C[i] = A[i] + B[i];
printf("Process id: %d, C[%d] = %d\n",rank,i,C[i]);
}

MPI_Reduce(&C[0],&D[0],N,MPI_INT,MPI_SUM,0,comm);

if (rank==0){
printf("Array D: ");
for(i=0; i<N; i++){
printf("%d ",D[i]);
}
printf("\n");
}

MPI_Finalize();

return 0;
}
