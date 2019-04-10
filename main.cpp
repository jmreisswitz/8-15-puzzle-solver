
#include <iostream>
#include <string>
#include <cstdlib>
//#include "instance.h"
#include "solver.h"
#include "bfs_solver.h"
//#include "tests.h"
using namespace std;


Solver *init(string mode)
{
	cout << "Mode: " << mode << endl;
	if (mode.compare(" -bfs")){
		return new BfsSolver();
	}
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
	cout << "should not come here" << endl;
	return nullptr;

}


int main(int argc, char *argv[])
{
	
	if(argc < 11){
		cout << "Where are the parameters, mate?" << endl;
		return -1;
	}
	Instance initial(2, 8, argv);
	initial.print_table();
	Solver* s = init(argv[1]);
	s->run(initial);
	delete s;
	return 0;
}
