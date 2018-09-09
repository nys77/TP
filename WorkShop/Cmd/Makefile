CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=cmd

all: $(EXEC)

cmd: man.o cmd.o
	$(CC) -o $@ $^ $(LDFLAGS)

man.o: man.c
	$(CC) -o $@ -c $< $(CFLAGS)

cmd.o: cmd.c man.h
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
