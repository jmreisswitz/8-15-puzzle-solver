
CC=g++
CFLAGS=-Iinclude
SRCDIR=src

all: node.o solver.o bfs_solver.o
	$(CC) -o main main.cpp node.o solver.o bfs_solver.o $(CFLAGS)

node.o:
	$(CC) -c $(SRCDIR)/node.cpp $(CFLAGS)


solver.o:
	$(CC) -c $(SRCDIR)/solver.cpp $(CFLAGS)


bfs_solver.o: solver.o
	$(CC) -c $(SRCDIR)/bfs_solver.cpp $(CFLAGS)

clean:
	rm *.o