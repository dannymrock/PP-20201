CC = mpicc	
OPTS = -Wall

DEBUG ?= 1
ifeq ($(DEBUG), 1)
    OPTS += -g -O0
else
    OPTS += -O3
endif

all: mpi_out.out take_time.out

mpi_out.out: mpi_out.o
	$(CC) -o $@ $< $(LIBS)

take_time.out: take_time.o
	$(CC) -o $@ $< $(LIBS)
	
%.o: %.c
	$(CC) $(OPTS) -c $< -o $@ $(LIBS)

clean:
	rm -f *.o *.out *~

run:
	mpirun --oversubscribe -np 4 ./mpi_out.out
	mpirun --oversubscribe -np 4 ./take_time.out

run-dist:
	mpirun --oversubscribe -np 8 -host localhost,worker1,worker3 -mca pml ob1 -mca btl tcp,self -mca btl_tcp_if_include br0,lo ./take_time.out
