CC = gcc-9	
OPTS = -Wall
LIBS = -fopenmp	

DEBUG ?= 1
ifeq ($(DEBUG), 1)
    OPTS += -g -O0
else
    OPTS += -O3
endif

all: trap_sol.out trap_spmd.out

trap_sol.out: trap_sol.o
	$(CC) -o $@ $< $(LIBS)

trap_spmd.out: trap_spmd.o
	$(CC) -o $@ $< $(LIBS)

%.o: %.c
	$(CC) $(OPTS) -c $< -o $@ $(LIBS)

clean:
	rm -f *.out *.o *~
