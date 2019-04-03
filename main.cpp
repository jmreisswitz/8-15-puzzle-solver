
#include <iostream>
#include <string>
#include "instance.h"
#include "solver.h"
#include "bfs_solver.h"
#include "nheap.h"
using namespace std;

Solver *init(string mode)
{
	cout << "Mode: " << mode << endl;
	//if (mode.compare("-bfs")){
		return new BfsSolver();
	//}
	/*
	else if(mode.compare("-idfs")){
		Solver s;
		return s;
	}
	else if(mode.compare("-astar")){
		Solver s;
		return s;
	}
	else if(mode.compare("-idastar")){
		Solver s;
		return s;
	}
	else if(mode.compare("-gbfs")){
		Solver s;
		return s;
	}
	*/

}

int main(int argc, char *argv[])
{
	if(argc < 11){
		cout << "Where are the parameters, mate?" << endl;
		return -1;
	}
	
	Solver* s = init(argv[1]);
	s->run();
	
	Instance i(2, 8, argv);
	i.move_blank(DOWN);
	Nheap<Instance> heap;
	heap.insert(i);
	heap.printElements();

	
	return 0;
}