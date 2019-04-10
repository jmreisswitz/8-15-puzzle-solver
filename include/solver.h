#ifndef SOLVER_H
#define SOLVER_H
#include <map>
#include "instance.h"

class Solver
{
	public:
		Solver();
		virtual bool run(Instance initial_state) = 0;
	
	protected:
		unsigned long int explored_nodes;
		unsigned long int solution_lenght;
		double time_to_solution; /// depois tem que ver direitinho qual o tipo de dado que a biblioteca de time espera
		double heuristic_avg;
		unsigned short int init_state_heuristic;
		std::map<unsigned long int, Instance> closed;

		void insert_into_fifo();
		void insert_into_heap();
		void print_stats();
		void insert_into_closed(Instance t);
		void finish_simulation(); /// ver os parâmetros depois
		bool is_on_closed(Instance* t);


};

#endif /* SOLVER_H */