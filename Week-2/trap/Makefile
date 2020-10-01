SRCS = trap.c
TARG = trap.out
OBJS = $(SRCS:.c=.o)

CC = gcc-9	
OPTS = -Wall
LIBS = -fopenmp	

DEBUG ?= 1
ifeq ($(DEBUG), 1)
    OPTS += -g -O0
else
    OPTS += -O3
endif

$(TARG): $(OBJS)
	$(CC) -o $(TARG) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(OPTS) -c $< -o $@ $(LIBS)

clean:
	rm -f $(OBJS) $(TARG) *~
