#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double f(double x);
double trap_f (double a, double b, int n);

int main(int argc, char* argv[]){
  double a, b, result, elapsed_time;
  int n;
  struct timeval t1, t2;

  if (argc != 4){
    printf("Error: ingrese solo 3 argumentos: a, b y n\n");
    return 1;
  }

  a = strtod(argv[1],NULL);
  b = strtod(argv[2],NULL);
  n = strtol(argv[3],NULL,10);

  printf("Calcular el area aproximada bajo la curva f(x)= x^3 en el intervalo [%2.1f %2.1f], usando %d trapecios\n\n",a, b, n);
  
  gettimeofday(&t1, NULL);
  
  result = trap_f(a, b, n);
  
  gettimeofday(&t2, NULL);
  
  elapsed_time = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
  elapsed_time += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
  
  printf("El area aproximada es: %.6f \n", result);
  printf("Tiempo: %.2f ms\n", elapsed_time);
  return 0;
}

double trap_f (double a, double b, int n){
  double h, approx, x_i;
  int i;
  h = (b - a)/n;
  approx = (f(a) + f(b))/2;
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
