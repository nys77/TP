# Makefile for malloc
 
CC=gcc
CFLAGS= -Wall -Wextra -std=c99 -fno-builtin -O0 -g -fPIC
LDFLAGS=
LDLIBS=
 
libmalloc.so: malloc.o
	${CC} -shared -o libmalloc.so malloc.o
 
clean:
	rm -f *~ *.o
	rm -f libmalloc.so
 
# end
