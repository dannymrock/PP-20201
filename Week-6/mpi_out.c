#include<stdio.h>
#include<mpi.h>

int main(){
  int my_rank, comm_sz;

  MPI_Init(NULL, NULL);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

  printf("Process %d of %d \n", my_rank, comm_sz);

  MPI_Finalize();
  return 0;
}
