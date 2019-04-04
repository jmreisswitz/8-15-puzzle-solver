
#include <iostream>
#include <string>
#include <cstdlib>
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

void test_heap()
{
	srand(1);
	Nheap<Instance> heap(2);
	for(int i = 0; i < 10000 ; i++ ){
		int rand_number = rand()%5000;
		heap.insert(Instance(rand_number, rand_number));
	}
	//heap.printElements();
	Instance t = heap.pop_min();
	t = heap.pop_min();
	t = heap.pop_min();
	t = heap.pop_min();
	t = heap.pop_min();
	t = heap.pop_min();
	t = heap.pop_min();
	cout << "min: " << t.get_key() << endl;

}


int main(int argc, char *argv[])
{
	test_heap();
	return 0;
	if(argc < 11){
		cout << "Where are the parameters, mate?" << endl;
		return -1;
	}
	Solver* s = init(argv[1]);
	s->run();
	
	Instance i(2, 8, argv);
	i.move_blank(DOWN);
	Nheap<Instance> heap(4);
	heap.insert(i);
	heap.print_elements();

	
	return 0;
}