# Makefile

CC = gcc -fsanitize=address
CPPFLAGS = -MMD
CFLAGS = -Wall -Wextra -std=c99 -O0 -g
LDFLAGS =
LDLIBS =

OBJ = matrix.o matrix_test.o
DEP = ${OBJ:.o=.d}

all: matrix_test

matrix_test: ${OBJ}

.PHONY: clean

clean:
	${RM} ${OBJ} ${DEP} matrix_test

-include ${DEP}

# END
