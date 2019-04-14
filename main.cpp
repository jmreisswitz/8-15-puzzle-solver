
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include "solver.h"
#include "bfs_solver.h"
//#include "tests.h"
using namespace std;

int num_col, board_size;

Solver *init(string mode)
{
	cout << "Mode: " << mode << endl;
	if (mode.find(" -bfs")){
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
	cout << "State readed: ";
	for (int i = 0; i < pos.size(); i++)
		cout << pos[i] << ",";
	cout << endl;
    board_size = pos.size();
    num_col = board_size == 16 ? 4 : 3;
    State state = vec_to_state(pos);
    
    Node initial(state);
	initial.print_table(num_col);

	// t2 = now();
	cout << "board_size: " << board_size << endl;
	solver->set_goal(board_size == 9 ? 0x0000000087654321 : 0x0FEDCBA987654321);
	solver->set_num_of_cols(num_col);
	solver->run(initial);
	// t1 = now();
	// cout << (t1 - t2)
	delete solver;
}




int main(int argc, char *argv[])
{
	//test_Node();
	
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
	run(state, s); // roda o ultimo state

	
	return 0;
}
