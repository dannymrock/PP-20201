#include <stdio.h>
#include <omp.h>
int fib(int);

int main(int argc, char *argv[])
{
  double time = omp_get_wtime();
  int res = fib(48);
  time = omp_get_wtime() - time;
  
  printf("result %d   time %.2f\n", res, time );
  return 0;
}

int fib (int n){
  if (n < 2) return n;
  int x, y;

  x = fib(n - 1);
  y = fib(n - 2);

  return x + y;
}
