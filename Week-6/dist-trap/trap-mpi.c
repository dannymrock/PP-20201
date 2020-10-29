#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <assert.h>


double f(double x);
double trap_f (double a, double b, int n);

int main(int argc, char* argv[]){
  double a, b, local_result, local_a, local_b;
  int n, local_n;
  int comm_sz;
  int rank;
  double global_result;

  double local_start, local_finish, local_elapsed, elapsed;


  MPI_Init(NULL, NULL);

  // SPMD: rank , comm_sz
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  // printf("rank %d, comm size %d\n", rank, comm_sz);

  // MPI I/O 1 solo procesos haga I/O
  if(rank == 0){
    printf("_Ingrese valores de a, b y n (separados por coma):\n");
    scanf("%lf,%lf,%d", &a, &b, &n);
  }

  MPI_Bcast(&a, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
  MPI_Bcast(&b, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
  MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

  MPI_Barrier(MPI_COMM_WORLD);
  local_start = MPI_Wtime();

  //a = 0.0;
  //b = 3.0;
  //n = 1024;
  //printf("a %f, b %f y n %d\n", a, b, n);
  double h = (b - a) / n;
  local_n = n / comm_sz;
  assert(n % comm_sz == 0);

  local_a = a + rank * local_n * h; 
  local_b = local_a + local_n * h;


  local_result = trap_f(local_a, local_b, local_n);
  
  MPI_Reduce(&local_result, &global_result, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

  local_finish = MPI_Wtime();
  // Cada proceso toma un tiempo local
  local_elapsed = local_finish - local_start;
  // Tomamos el tiempo del proceso más lento
  MPI_Reduce(&local_elapsed, &elapsed, 1, MPI_DOUBLE, \
       MPI_MAX, 0, MPI_COMM_WORLD);

  if(rank == 0){
    printf("rank %d: El area aproximada es: %6.3f \n", rank, global_result);
    printf("Tiempo de ejecución = %5.2f segundos \n", elapsed);
  }
  MPI_Finalize();

  return 0;
}

double trap_f (double a, double b, int n){
  double h, approx, x_i;
  int i;
  h = (b - a) / n;
  approx = (f(a)+f(b))/2;
  for (i = 1; i <= n-1; i++){
    x_i = a + i * h;
    approx += f(x_i); 
  }
  approx = h * approx;
  return approx;
}

double f(double x){
  return x*x*x;
}
