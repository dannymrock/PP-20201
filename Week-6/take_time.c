#include<stdio.h>
#include<mpi.h>

#define MAX 1000000000

int main(){
  double local_start, local_finish, local_elapsed, elapsed;
  double sum = 0;
  long i;
  int my_rank;
  MPI_Init(NULL, NULL);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  
  //Nos aseguramos que todos los procesos inicien al "mismo" tiempo
  MPI_Barrier(MPI_COMM_WORLD);
  local_start = MPI_Wtime();

  /*
   *Inicio del código al cual queremos tomarle el tiempo
   */
  for(i = 0; i < MAX; i++){
    sum = sum + 1.0/i;
  }
  /*
   * Fin del código al cual queremos tomarle el tiempo
   */
  
  local_finish = MPI_Wtime();
  // Cada proceso toma un tiempo local
  local_elapsed = local_finish - local_start;
  // Tomamos el tiempo del proceso más lento
  MPI_Reduce(&local_elapsed, &elapsed, 1, MPI_DOUBLE, \
	     MPI_MAX, 0, MPI_COMM_WORLD);

  if(my_rank == 0){
    // Solo el proceso 0 imprime el tiempo transcurrido
    printf("Tiempo de ejecución = %5.2f segundos \n", elapsed);
  }
  
  MPI_Finalize();

  return 0;
}
