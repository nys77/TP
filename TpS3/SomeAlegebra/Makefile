# Makefile

CC = gcc -fsanitize=address
CPPFLAGS = -MMD
CFLAGS = -Wall -Wextra -std=c99 -O0 -g
LDFLAGS =
LDLIBS =

OBJ = algebra.o algebra_test.o
DEP = ${OBJ:.o=.d}

all: algebra_test

algebra_test: ${OBJ}

.PHONY: clean

clean:
	${RM} ${OBJ} ${DEP} algebra_test

-include ${DEP}

# END
