#include<iostream>
#include "solver.h"

using namespace std;

Solver::Solver()
{
    this->goal = goal;
	explored_nodes = 0;
	heuristic_avg = 0;
	this->num_of_columns = num_of_columns;
};

/*
void Solver::finish_simulation(Instance& final_node, unsigned long execution_time)
{
	/// aqui a ideia é setar as variáveis de print_stats para depois imprimir elas com print_status
	/// pode ser que esse método nem seja preciso, sei lá
	closed.clear();
	cout    << explored_nodes << ","
            << final_node.cost << ","
            << execution_time << ","
            << heuristic_avg << ","
            << init_state_heuristic << endl;
};
*/