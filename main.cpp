
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
//#include "instance.h"
#include "solver.h"
#include "bfs_solver.h"
//#include "tests.h"
using namespace std;

int num_col, board_size;

Solver *init(string mode)
{
	cout << "Mode: " << mode << endl;
	if (mode.find("-bfs")){
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

void run(vector<int>& pos, Solver* solver)
{
    board_size = pos.size();
    num_col = board_size == 16 ? 4 : 3;
    State state;
    // TODO: traduzir o vector pos para State (unsigned long)
    Instance initial(state);
	initial.print_table();

	// t2 = now();
	s->run(initial);
	// t1 = now();
	// cout << (t1 - t2)
}

int main(int argc, char *argv[])
{
	if(argc < 11){
		cout << "Where are the parameters, mate?" << endl;
		return -1;
	}
    Solver* s = init(argv[1]);
	vector<int> state;
	for (int i = 2; i < argc; i++) {
        string pos(argv[i]);
        if (pos.back() == ',') {
            pos.pop_back();
            state.push_back(stoi(pos));
            run(state, s);
            state.clear();
            continue;
        }
        state.push_back(stoi(pos));
	}
    run(state, s);
	return 0;
}
