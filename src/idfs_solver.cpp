#include <iostream>
#include "idfs_solver.h"

// Recursive DFS.
uint IdfsSolver::dfs(uint depth, State state, State parent) {
	if (depth == 0)
		return NO_SOLUTION;
	expanded_nodes++;
	Node current(state, 0);
	for(int i = FIRST; i <= LAST; i++) {
		State neighbor = current.move_blank(i, num_of_columns);			
		if (neighbor == 0 || neighbor == parent) 
			continue;
		if (neighbor == goal)
			return 1;
		int solution = dfs(depth - 1, neighbor, state);
		if (solution != NO_SOLUTION) {
			return solution + 1;
		}
	}
	return NO_SOLUTION;
}

bool IdfsSolver::run(State initial_state) {	
	init_state_heuristic = heuristic(initial_state);
	heuristic_avg = 0;
	if (initial_state == goal) {
		final_cost = 0;
		return true;
	}
	uint depth = 1;
	do {
		final_cost = dfs(depth++, initial_state, initial_state);
	} while (final_cost == NO_SOLUTION);
	return true;
}