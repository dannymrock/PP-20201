SRCS = functions.c montecarlo_pi.c
TARG = montecarlo_pi.out
OBJS = $(SRCS:.c=.o)

CC = gcc-9
OPTS = -Wall
FLAGS_OPENMP = -fopenmp

DEBUG ?= 1
ifeq ($(DEBUG), 1)
    OPTS += -g -O0
else
    OPTS += -O3
endif

$(TARG): $(OBJS)
	$(CC) -o $(TARG) $(OBJS) $(FLAGS_OPENMP) $(LIBS)

%.o: %.c
	$(CC) $(OPTS) -c $< -o $@ $(FLAGS_OPENMP) 

clean:
	rm -f $(OBJS) $(TARG) *~
