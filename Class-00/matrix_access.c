#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>

#define MAX 1000

int main(void){
  double A[MAX][MAX], x[MAX], y[MAX], elapsedTime, r;
  int i, j;

  struct timeval t1, t2;
  
  // initialization
  srand(time(NULL));

  for(i = 0; i < MAX; i++){
    for(j = 0; j < MAX; j++){
      r = rand();
      A[i][j] = r;
    }
    r = rand();
    x[i] = r;
    y[i] = 0;
  }  
  printf("Initialized \n");
  // Loops
  // First case
  gettimeofday(&t1, NULL);
  for(i = 0; i < MAX; i++){
    for(j = 0; j < MAX; j++){
      y[i] += A[i][j]*x[j];
    }
  }
  gettimeofday(&t2, NULL);
  elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
  elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
  printf("First case %f\n", elapsedTime);

  // Second case
  gettimeofday(&t1, NULL);
  for(j = 0; j < MAX; j++){
    for(i = 0; i < MAX; i++){
      y[i] += A[i][j]*x[j];
    }
  }
  gettimeofday(&t2, NULL);
  elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
  elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
  printf("Second case %f\n", elapsedTime);
}
