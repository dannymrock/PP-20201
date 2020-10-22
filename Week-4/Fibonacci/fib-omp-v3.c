#include <stdio.h>
#include <omp.h>

int fib(int);
int seq_fib (int);

int main(int argc, char *argv[])
{
  double time = omp_get_wtime();
  int res;

  #pragma omp parallel
  {
    #pragma omp single
    {
      res = fib(48);
    }
  }
  time = omp_get_wtime() - time;
  
  printf("result %d   time %.2f\n", res, time );
  return 0;
}

int fib (int n){
  if (n < 2) return n;
  if (n < 30) return seq_fib(n);
  int x, y;

#pragma omp task shared(x) 
  {
    x = fib(n - 1);
  }
  
#pragma omp task shared(y) 
  {
    y = fib(n - 2);
  }

  #pragma omp taskwait
  return x + y;
}

int seq_fib (int n){
  if (n < 2) return n;
  int x, y;
  x = seq_fib(n - 1);
  y = seq_fib(n - 2);
  return x + y;
}
