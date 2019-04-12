#ifndef SOLVER_H
#define SOLVER_H
#include <map>
#include "instance.h"

class Solver
{
	public:
		Solver(State goal);
		virtual bool run(Instance initial_state) = 0;

	protected:
		unsigned long int explored_nodes;
		double heuristic_avg;
		unsigned short int init_state_heuristic;
		State goal;
		std::set<State> closed;

		void finish_simulation(Instance& node); /// ver os parâmetros depois

};

#endif /* SOLVER_H */
