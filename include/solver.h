#ifndef SOLVER_H
#define SOLVER_H
#include <set>
#include "node.h"

class Solver
{
	public:
		Solver();
		virtual bool run(Node initial_state) = 0;
		void set_goal(State goal) {this->goal = goal;};
		void set_num_of_cols(int num_of_cols) {this->num_of_columns = num_of_cols;};

	protected:
		unsigned long int explored_nodes;
		double heuristic_avg;
		unsigned short int init_state_heuristic;
		State goal;
		std::set<State> closed;
		int num_of_columns;

		void finish_simulation(Node& node);

};

#endif /* SOLVER_H */
