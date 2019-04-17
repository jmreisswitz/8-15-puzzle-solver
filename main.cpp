
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <chrono>

#include "solver.h"
#include "bfs_solver.h"
#include "astar_solver.h"
//#include "tests.h"
using namespace std;
using namespace chrono;

Solver *init(string mode)
{
	cout << "Mode: " << mode << endl;
	if (mode.find("-bfs") != std::string::npos){
		return new BfsSolver();
	}
	else if(mode.find("-astar") != std::string::npos){
		return new AStarSolver();
	}
	/*
	else if(mode.compare("-idfs")){
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
	cout << "State readed: " << pos[0];
	for (int i = 1; i < pos.size(); i++)
		cout << "," << pos[i];
	cout << endl;
    uint board_size = pos.size();
    uint num_col = board_size == 9 ? 3 : 4;
    State state = vec_to_state(pos);
    
    Node initial(state);
	initial.print_table(num_col);

	auto t1 = high_resolution_clock::now();
	cout << "board_size: " << board_size << endl;
	solver->set_goal(board_size == 9 ? 0x0000000087654321 : 0x0FEDCBA987654321);
	solver->set_num_of_cols(num_col);
	solver->run(initial);
	auto t2 = high_resolution_clock::now();
	solver->print_stats(duration_cast<milliseconds> (t2 - t1).count());
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
