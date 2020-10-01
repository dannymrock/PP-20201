#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

void saxpy(int n,
	   float a,
	   float *x,
	   float *restrict y)
{

#pragma omp parallel for
  for (int i = 0; i < n; ++i)
    y[i] = a * x[i] + y[i];
}

int main(int argc, char **argv)
{
  double ti, te;
  int N = 1000000; 
  
  if (argc > 1)
    N = atoi(argv[1]);
  
  float *x = (float*)malloc(N * sizeof(float));
  float *y = (float*)malloc(N * sizeof(float));
  
  #pragma omp parallel for
  for (int i = 0; i < N; ++i) {
    x[i] = 2.0f;
    y[i] = 1.0f;
  }
  
  ti = omp_get_wtime();
  saxpy(N, 3.0f, x, y);
  te = omp_get_wtime();

  printf("Execution time %f \n", te - ti);

  return 0;
}
