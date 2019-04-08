
#include <iostream>
#include <string>
#include <cstdlib>
//#include "instance.h"
#include "solver.h"
#include "bfs_solver.h"
#include "nheap.h"
#include "tests.h"
using namespace std;


int main(int argc, char *argv[])
{
	/*
	if(argc < 11){
		cout << "Where are the parameters, mate?" << endl;
		return -1;
	}
	*/
	test_instance();
	return 0;
}



/*
Solver *init(string mode)
{
	cout << "Mode: " << mode << endl;
	if (mode.compare("-bfs")){
		return new BfsSolver();
	}
	
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
	

}
*/