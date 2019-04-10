#include<iostream>
#include "solver.h"

using namespace std;

Solver::Solver()
{
	explored_nodes = 0;
	solution_lenght = 0;
	time_to_solution = 0; /// depois tem que ver direitinho qual o tipo de dado que a biblioteca de time espera
};

void Solver::insert_into_closed(Instance t)
{
	closed.insert(std::pair<unsigned long int, Instance>(t.get_identifier(), t));
}

void Solver::print_stats()
{
	cout << explored_nodes << "," << solution_lenght << "," << time_to_solution << "," << heuristic_avg << "," << init_state_heuristic << endl;
};

/*
void clear_map(map<unsigned long int, Instance> closed)
{
	for (auto it = closed.begin(); it != closed.end(); it++){
		delete 
	}
}
*/

void Solver::finish_simulation()
{
	/// aqui a ideia é setar as variáveis de print_stats para depois imprimir elas com print_status
	/// pode ser que esse método nem seja preciso, sei lá
	closed.clear();	
	cout << "TODO finish_simulation" << endl;
	print_stats();

};


bool Solver::is_on_closed(Instance* t)
{
	// find method: Searches the container for an element with a key equivalent to k and returns an iterator to it if found, 
	// otherwise it returns an iterator to map::end.
	auto it = closed.find(t->get_identifier());
	return it != closed.end();
};