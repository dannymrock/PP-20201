CC = gcc-9	
OPTS = -Wall
LIBS = -fopenmp	

DEBUG ?= 1
ifeq ($(DEBUG), 1)
    OPTS += -g -O0
else
    OPTS += -O3
endif

all: fib.out fib-omp-v1.out fib-omp-v2.out fib-omp-v3.out

fib.out: fib.o
	$(CC) -o $@ $< $(LIBS)

fib-omp-v1.out: fib-omp-v1.o
	$(CC) -o $@ $< $(LIBS)
	
fib-omp-v2.out: fib-omp-v2.o
	$(CC) -o $@ $< $(LIBS)

fib-omp-v3.out: fib-omp-v3.o
	$(CC) -o $@ $< $(LIBS)

%.o: %.c
	$(CC) $(OPTS) -c $< -o $@ $(LIBS)

clean:
	rm -f *.o *.out *~
