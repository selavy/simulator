CC=gcc
CFLAGS=-Wall -pedantic -ansi -g -Wunused-variable

OBJS = Register.o Memory.o SimIO.o Pipeline.o main.o

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o simulator
run: all
	./simulator
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
Pipeline.o: Pipeline.h Pipeline.c
	$(CC) $(CFLAGS) -c Pipeline.c
Register.o: Register.h Register.c
	$(CC) $(CFLAGS) -c Register.c
Memory.o: Memory.h Memory.c
	$(CC) $(CFLAGS) -c Memory.c
SimIO.o: SimIO.h SimIO.c
	$(CC) $(CFLAGS) -c SimIO.c
clean:
	rm -rf *~ *.o simulator

