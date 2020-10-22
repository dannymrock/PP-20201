#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
  int thread_count = 4;
  long n = 100L, i;
  double t1, t2;
  
  if (argc == 3){
    thread_count = strtol(argv[1], NULL, 10);
    n = strtol(argv[2], NULL, 10);
  }
  
  double res_v[thread_count][8];
  double res_global;


  t1 = omp_get_wtime();

#pragma omp parallel num_threads(thread_count) default(none)	\
  private(i) shared(res_v, n)
  {
    int my_rank = omp_get_thread_num();
    res_v[my_rank][0] = 0.0;
#pragma omp for schedule(static,1)
    for (i = 0; i < n; i++){
      res_v[my_rank][0] += i / 4.0;
    }
  }

  for (i = 0; i < thread_count; i++)
    res_global += res_v[i][0];
  
  t2 = omp_get_wtime();
  
  printf("Time %6.4f s\n", (t2-t1));  
  
  return 0;
}
  