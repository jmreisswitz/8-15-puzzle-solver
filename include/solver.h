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
		void set_num_of_cols(uint num_of_cols) {this->num_of_columns = num_of_cols;};
		void print_stats(unsigned long execution_time);

	protected:
		unsigned long int expanded_nodes;
		double heuristic_avg;
		uint heuristic_count;
		unsigned short int init_state_heuristic;
		uint final_cost;

		State goal;
		uint num_of_columns;
		uint board_size;

		unsigned short int heuristic(State state);

};

#endif /* SOLVER_H */
