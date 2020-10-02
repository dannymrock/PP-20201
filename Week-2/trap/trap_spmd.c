#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <assert.h>


double f(double x);
double trap_f (double a, double b, int n, double *  );

int main(int argc, char* argv[]){
  double a, b, result;
  int n;
  double t1, t2;

  if (argc != 4){
    printf("Error: ingrese solo 3 argumentos: a, b y n\n");
    return 1;
  }

  a = strtod(argv[1],NULL);
  b = strtod(argv[2],NULL);
  n = strtol(argv[3],NULL,10);

  printf("Calcular el area aproximada bajo la curva f(x)= x^3 en el intervalo [%2.1f %2.1f], usando %d trapecios\n\n",a, b, n);
  
  double total = 0;

  t1 = omp_get_wtime();

  #pragma omp parallel
  { 
    result = trap_f(a, b, n, &total);
  }
  t2 = omp_get_wtime();
  
  printf("El area aproximada es: %.6f \n", total);
  printf("Tiempo: %.2f segundos\n", t2 - t1);
  return 0;
}

double trap_f (double a, double b, int n, double * total){
  double h, approx, x_i;
  int i;
  double local_a, local_b;
  int local_n;

  int nt = omp_get_num_threads();
  int my_rank = omp_get_thread_num();

  h = (b - a) / n;


  assert(n % nt == 0);


  local_n = n / nt;
  local_a = a + local_n * h * my_rank; 
  local_b = local_a + local_n * h ;



  approx = (f(local_a) + f(local_b))/2;
  for (i = 1; i <= local_n - 1; i++){
    x_i = local_a + i * h;
    approx += f(x_i); 
  }
  approx = h * approx;

  printf("approx= %f \n", approx);

  #pragma omp critical
  *total +=  approx;
  return approx;

}

double f(double x){
  return x * x * x;
}
  