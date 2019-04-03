
#include <iostream>
#include <string>
#include "instance.h"
#include "solver.h"
using namespace std;

Solver init(string mode)
{
	cout << "Mode: " << mode << endl;
	if (mode.compare("-bfs")){
		Solver s;
		return s;
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

int main(int argc, char *argv[])
{

	Solver s = init(argv[1]);
	
	Instance i(2, 8, argv);
	i.move_blank(DOWN);

	//read_cmd_input(argc, argv, instance, &mode);

	//cout << "Mode: " << mode << endl;


	return 0;
}