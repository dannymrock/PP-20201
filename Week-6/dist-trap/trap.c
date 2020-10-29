#include <stdio.h>
#include <stdlib.h>

double f(double x);
double trap_f (double a, double b, int n);

int main(int argc, char* argv[]){
  double a, b, result, elapsed_time;
  int n;

  a = 0.0;
  b = 10.0;
  n = 1200000000;

  result = trap_f(a, b, n);
  
  printf("El area aproximada es: %6.3f \n", result);
  return 0;
}

double trap_f (double a, double b, int n){
  double h, approx, x_i;
  int i;
  h = (b-a)/n;
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
