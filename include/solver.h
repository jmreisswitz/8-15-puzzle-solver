#ifndef SOLVER_H
#define SOLVER_H
#include <set>
#include "instance.h"

class Solver
{
	public:
		Solver();
		virtual bool run(Instance initial_state) = 0;

	protected:
		unsigned long int explored_nodes;
		double heuristic_avg;
		unsigned short int init_state_heuristic;
		State goal;
		std::set<Instance> closed;

		void finish_simulation(Instance& node);

};

#endif /* SOLVER_H */
