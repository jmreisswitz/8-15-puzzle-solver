#include <iostream>
#include "idfs_solver.h"

IdfsSolver::IdfsSolver() : Solver() {};

int IdfsSolver::dfs(int depth, State state) {
	if (depth == 0)
		return NO_SOLUTION;
	expanded_nodes++;
	Node current(state, 0);
	for(int i = FIRST; i <= LAST; i++) {
		State neighbor = current.move_blank(i, num_of_columns);			
		if (neighbor == 0) 
			continue;
		if (neighbor == goal)
			return 1;
		int solution = dfs(depth - 1, neighbor);
		if (solution != NO_SOLUTION) {
			return solution + 1;
		}
	}
	return NO_SOLUTION;
}

bool IdfsSolver::run(State initial_state) {	
	init_state_heuristic = heuristic(initial_state);
	if (initial_state == goal) {
		final_cost = 0;
		return true;
	}
	uint depth = init_state_heuristic;
	do {
		final_cost = dfs(depth++, initial_state);
	} while (final_cost == NO_SOLUTION);
	return true;
}