#ifndef SOLVER_H
#define SOLVER_H

#include "node.h"
#define NO_SOLUTION -1

class Solver
{
	public:
		Solver();
		virtual bool run(State initial_state) = 0;
		void set_goal(State goal) {this->goal = goal;}
		void set_num_of_cols(uint num_of_cols) {this->num_of_columns = num_of_cols;}
		void print_stats(unsigned long int execution_time);

	protected:
		unsigned long int expanded_nodes;
		uint8_t init_state_heuristic;
		uint heuristic_avg;
		uint heuristic_count;
		uint final_cost;

		State goal;
		uint num_of_columns;
		uint board_size;

		uint8_t heuristic(State state);

};

#endif /* SOLVER_H */
