/*****************************************************************************/
/* Estimación del número Pi usando el método de Montecarlo                   */
/* Versión secuencial                                                        */
/* Autor: Danny Múnera                                                       */
/* Curso de programación paralela con OpenMP                                 */
/* 21/07/2020                                                                */
/*****************************************************************************/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <omp.h>

double montecarlo_seq (int p);

double montecarlo_par (int p, int n, unsigned int seed);

#endif
