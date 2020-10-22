*Fibonacci Example*

Compile in debug mode:
´´´
make clean
make
´´´

Compile in production mode:
´´´
make clean
make DEBUG=0
´´´

Execute fibonacci in sequential:
´´´
./fib.out
´´´

Execute parallel fibonacci:
´´´
OMP_NUM_THREADS=4 ./fib-omp-v3.out
´´´
