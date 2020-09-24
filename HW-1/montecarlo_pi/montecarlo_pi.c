/*****************************************************************************/
/* Estimación del número Pi usando el método de Montecarlo                   */
/* Versión secuencial                                                        */
/* Autor: Danny Múnera                                                       */
/* Curso de programación paralela con OpenMP                                 */
/* 21/07/2020                                                                */
/*****************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <omp.h>
#include "functions.h"

int main(int argc, char* argv[]) {
  unsigned int seed = 1;
  int p = 100000000, n_threads = 2;
  const double pi25DT = 3.141592653589793238462643;

  double start, end, time_seq, time_par;
  double pi_seq, pi_par, pi_seq_err, pi_par_err;
  

  // Getting input values
  int opt;
  while((opt = getopt(argc, argv, ":p:s:n:")) != -1)  
    {  
      switch(opt)  
        {  
	case 'p':  
	  printf("random points number: %s\n", optarg);
	  p = strtol(optarg, NULL, 10);
	  assert(p > 0 && p <= 2147483647);
	  break;  
	case 's':  
	  printf("seed: %s\n", optarg);
	  seed = strtol(optarg, NULL, 10);
	  break;
	case 'n':  
	  printf("threads number: %s\n", optarg);
	  n_threads = strtol(optarg, NULL, 10);
	  break;  
	case ':':  
	  printf("option -%c needs a value\n", optopt);  
	  break;  
	case '?':  
	  fprintf(stderr, "Usage: %s [-p <points number>] [-s <seed>] [-n <threads number>]\n", argv[0]);
	  exit(EXIT_FAILURE);
        }  
    }  

  srand(seed);

  // Sequential execution
  start = omp_get_wtime();
  pi_seq = montecarlo_seq(p);
  end = omp_get_wtime();
  time_seq = end - start;
  pi_seq_err = fabs(pi_seq - pi25DT);
  
  printf("\nSequential version:\n");
  printf("Estimated value of pi: %1.8f with an error of %.20f\n",
	 pi_seq, pi_seq_err);
  printf("Execution time: %f s\n\n", time_seq);

  // Parallel execution
  start = omp_get_wtime();
  pi_par = montecarlo_par(p, n_threads, seed);
  end = omp_get_wtime();
  time_par = end - start;
  pi_par_err = fabs(pi_par - pi25DT);

  printf("\nParallel version with %d threads:\n", n_threads);
  printf("Estimated value of pi: %1.8f with an error of %.20f\n",
	 pi_par, pi_par_err);
  printf("Execution time: %f s\n\n", time_par);
  
  printf("--- Output for the automatic grading system ---\n");
  printf("exec_time_seq = %f \n", time_seq);
  printf("est_pi_seq = %1.8f\nerror_seq = %.20f\n", pi_seq, pi_seq_err);
  printf("exec_time_par = %f \n", time_par);
  printf("est_pi_par = %1.8f\nerror_par = %.20f\n", pi_par, pi_par_err);
  printf("speedup = %f \n", (time_seq / time_par));
  return(0);
}
