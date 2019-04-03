
CC=g++
CFLAGS=-Iinclude -g
SRCDIR=src

all: instance.o solver.o bfs_solver.o
	$(CC) -o main main.cpp instance.o solver.o bfs_solver.o $(CFLAGS)

instance.o:
	$(CC) -c $(SRCDIR)/instance.cpp $(CFLAGS)


solver.o:
	$(CC) -c $(SRCDIR)/solver.cpp $(CFLAGS)


bfs_solver.o: 
	$(CC) -c $(SRCDIR)/bfs_solver.cpp $(CFLAGS)

clean:
	rm *.o