# Makefile

CC=gcc -pthread -fsanitize=address
CPPFLAGS=
CFLAGS= -Wall -Wextra -std=c99 -Og
LDFLAGS=
LDLIBS=

SRC= shared_queue.c test.c
OBJ= ${SRC:.c=.o}
DEP= ${SRC:.c=.d}

all: test

test: ${OBJ}

clean:
	rm -f ${OBJ}
	rm -f ${DEP}
	rm -f test

-include ${DEP}

# END
