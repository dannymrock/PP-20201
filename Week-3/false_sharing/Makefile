CC = gcc-9	
OPTS = -Wall
LIBS = -fopenmp	

DEBUG ?= 1
ifeq ($(DEBUG), 1)
    OPTS += -g -O0
else
    OPTS += -O3
endif

all: false-sharing.out false-sharing-sol.out

false-sharing.out: false-sharing.o
	$(CC) -o $@ $< $(LIBS)

false-sharing-sol.out: false-sharing-sol.o
	$(CC) -o $@ $< $(LIBS)

%.o: %.c
	$(CC) $(OPTS) -c $< -o $@ $(LIBS)

clean:
	rm -f *.o *.out *~
