
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <sstream>

#include "solver.h"
#include "bfs_solver.h"
#include "astar_solver.h"
#include "gbfs_solver.h"
#include "idfs_solver.h"
#include "idastar_solver.h"
//#include "tests.h"
using namespace std;
using namespace chrono;

Solver *init(string& mode)
{
	//cout << "Mode: " << mode << endl;
	if (mode.find("-bfs") != string::npos){
		return new BfsSolver();
	}
	else if(mode.find("-astar") != string::npos){
		return new AStarSolver();
	}
	else if(mode.find("-gbfs") != string::npos){
		return new GbfsSolver();
	}
	else if(mode.find("-idfs") != string::npos){
		return new IdfsSolver();
	}
	else if(mode.find("-idastar") != string::npos){
		return new IdAstarSolver();
	}
	cout << "Solver not found: " << mode << endl;
	return nullptr;
}

void run(vector<int>& pos, string& solverName)
{
	Solver* solver = init(solverName);
	
	/*cout << "State readed: " << pos[0];
	for (int i = 1; i < pos.size(); i++)
		cout << "," << pos[i];
	cout << endl;*/
    uint board_size = pos.size();
    uint num_col = board_size == 9 ? 3 : 4;
    State state = vec_to_state(pos);

	//cout << "board_size: " << board_size << endl;
	solver->set_goal(board_size == 9 ? 0x0000000876543210 : 0xFEDCBA9876543210);
	solver->set_num_of_cols(num_col);
	auto t1 = high_resolution_clock::now();
	solver->run(state);
	auto t2 = high_resolution_clock::now();
	solver->print_stats(duration_cast<microseconds> (t2 - t1).count());
}

void readFile(string& name, string& solverName) {
	ifstream file(name);
	if (!file.is_open())
		cout << "Could not read file: " << name << endl;
	string line;
	while (getline(file,line)) {
		istringstream linestream(line);
		vector<int> state;
		int i;
		while(linestream >> i) state.push_back(i);
		run(state, solverName);
	}
	file.close();
}

int main(int argc, char *argv[])
{
	//test_Node();
	
	if(argc < 4){
		cout << "Where are the parameters, mate?" << endl;
		return -1;
	}
	vector<int> state;
	string solver(argv[1]);

	{
		string fileflag(argv[2]);
		if (fileflag.find("-f") != string::npos) {
			string file(argv[3]);
			readFile(file, solver);
			return 0;
		}
	}

	for (int i = 2; i < argc; i++) {
        string pos(argv[i]);
        if (pos.back() == ',') {
            pos.pop_back();
            state.push_back(stoi(pos));
            run(state, solver);
            state.clear();
            //cout << endl;
            continue;
        }
        state.push_back(stoi(pos));
	}
	run(state, solver); // roda o ultimo state

	return 0;
}
