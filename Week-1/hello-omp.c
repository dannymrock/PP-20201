#include <stdio.h>
#include <omp.h>

int main(void){
	int num_threads;
	int my_rank;
#pragma omp parallel num_threads(5)
	{
		num_threads = omp_get_num_threads();
		my_rank = omp_get_thread_num();
		printf("Hello from thread %d of %d.\n", my_rank, num_threads);
 	}
  	return 0;
}