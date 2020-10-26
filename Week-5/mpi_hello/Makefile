CC = mpicc	
OPTS = -Wall

DEBUG ?= 1
ifeq ($(DEBUG), 1)
    OPTS += -g -O0
else
    OPTS += -O3
endif

all: mpi_hello.out mpi_hello_ack.out

mpi_hello.out: mpi_hello.o
	$(CC) -o $@ $< $(LIBS)

mpi_hello_ack.out: mpi_hello_ack.o
	$(CC) -o $@ $< $(LIBS)
	
%.o: %.c
	$(CC) $(OPTS) -c $< -o $@ $(LIBS)

clean:
	rm -f *.o *.out *~

run:
	mpirun --oversubscribe -np 4 ./mpi_hello.out
	mpirun --oversubscribe -np 4 ./mpi_hello_ack.out

