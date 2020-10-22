#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

double f(double x);
double trap_f (double a, double b, int n);

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
  
  t1 = omp_get_wtime();
  result = trap_f(a, b, n);
  t2 = omp_get_wtime();
  
  printf("El area aproximada es: %.6f \n", result);
  printf("Tiempo: %.2f segundos\n", t2 - t1);
  return 0;
}

double trap_f (double a, double b, int n){
  double h, approx, x_i;
  int i;
  h = (b - a)/n;
  approx = (f(a) + f(b))/2;
  
  #pragma omp parallel for default(none) reduction(+: approx) private(i, x_i) shared(n, a, h)
  for (i = 1; i <= n - 1; i++){
    x_i = a + i * h;
    approx += f(x_i);  
  }
  approx = h * approx;
  return approx;
}

double f(double x){
  return x * x * x;
}
  