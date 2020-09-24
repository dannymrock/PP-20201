/*****************************************************************************/
/* Estimación del número Pi usando el método de Montecarlo                   */
/* Versión secuencial                                                        */
/* Autor: Danny Múnera                                                       */
/* Curso de programación paralela con OpenMP                                 */
/* 21/07/2020                                                                */
/*****************************************************************************/
#include "functions.h"

double montecarlo_seq (int p) {  
  int i, counter = 0;
  double x, y, z, pi;

  // Computation of pi
  for(i = 0; i < p; ++i) {
    x = (double)rand() / RAND_MAX;
    y = (double)rand() / RAND_MAX;
    z = x * x + y * y;
    if( z <= 1 ) counter++;
  }
  pi = (double) counter / p * 4;

  return pi;
}

double montecarlo_par (int p, int n_threads, unsigned int seed) {  
  int i, counter = 0;
  double x, y, z, pi;

  // TODO: Modify this function to compute pi in parallel using n threads 
  for(i = 0; i < p; ++i) {
    x = (double)rand() / RAND_MAX;
    y = (double)rand() / RAND_MAX;
    z = x * x + y * y;
    if( z <= 1 ) counter++;
  }
  pi = (double) counter / p * 4;

  return pi;
}
