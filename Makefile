
CC=g++
CFLAGS=-Iinclude
SRCDIR=src
BINDIR=bin

all: $(BINDIR)/node.o $(BINDIR)/solver.o $(BINDIR)/bfs_solver.o $(BINDIR)/gbfs_solver.o $(BINDIR)/astar_solver.o
	$(CC) -o main main.cpp $(BINDIR)/node.o $(BINDIR)/solver.o $(BINDIR)/bfs_solver.o $(BINDIR)/gbfs_solver.o $(BINDIR)/astar_solver.o $(CFLAGS)

$(BINDIR)/node.o:
	$(CC) -c $(SRCDIR)/node.cpp -o $(BINDIR)/node.o $(CFLAGS)

$(BINDIR)/solver.o:
	$(CC) -c $(SRCDIR)/solver.cpp -o $(BINDIR)/solver.o $(CFLAGS)

$(BINDIR)/bfs_solver.o: $(BINDIR)/solver.o
	$(CC) -c $(SRCDIR)/bfs_solver.cpp -o $(BINDIR)/bfs_solver.o $(CFLAGS)

$(BINDIR)/gbfs_solver.o: $(BINDIR)/solver.o
	$(CC) -c $(SRCDIR)/gbfs_solver.cpp -o $(BINDIR)/gbfs_solver.o $(CFLAGS)

$(BINDIR)/astar_solver.o: $(BINDIR)/solver.o
	$(CC) -c $(SRCDIR)/astar_solver.cpp -o $(BINDIR)/astar_solver.o $(CFLAGS)

clean:
	rm $(BINDIR)/*.o