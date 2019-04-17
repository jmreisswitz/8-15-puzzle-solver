#include<iostream>
#include "solver.h"

using namespace std;

Solver::Solver()
{
	explored_nodes = 0;
	heuristic_avg = 0;
};

void Solver::print_stats(unsigned long execution_time)
{
	/// aqui a ideia é setar as variáveis de print_stats para depois imprimir elas com print_status
	/// pode ser que esse método nem seja preciso, sei lá
	cout<< explored_nodes << ", "
        << final_cost << ", "
        << execution_time << ", "
        << heuristic_avg << ", "
        << init_state_heuristic << endl;
};
