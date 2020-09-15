SRCS = matrix_access.c
TARG = matrix_access.out
OBJS = $(SRCS:.c=.o)

CC = gcc
OPTS = -Wall

DEBUG ?= 1
ifeq ($(DEBUG), 1)
    OPTS += -g -O0
else
    OPTS += -O3
endif

$(TARG): $(OBJS)
	$(CC) -o $(TARG) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(OPTS) -c $< -o $@ 

clean:
	rm -f $(OBJS) $(TARG) *~
