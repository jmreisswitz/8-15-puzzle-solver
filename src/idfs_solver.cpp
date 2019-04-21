#include <iostream>
#include "idfs_solver.h"

IdfsSolver::IdfsSolver()
:Solver()
{};

int IdfsSolver::dfs(int depth, State state) {
	if (depth == 0)
		return -1;
	expanded_nodes++;
	Node current(state, 0);
	for(int i = FIRST; i <= LAST; i++) {
		State neighbor = current.move_blank(i, num_of_columns);			
		if (neighbor == 0) 
			continue;
		if (neighbor == goal)
			return 0;
		int solution = dfs(depth - 1, neighbor);
		if (solution != -1)
			return solution + 1;
	}
}

bool IdfsSolver::run(State initial_state) {	
	init_state_heuristic = heuristic(initial_state);
	if (initial_state == goal) {
		final_cost = 0;
		return true;
	}
	int depth = 1;
	do {
		final_cost = dfs(depth++, initial_state);
	} while (final_cost == -1);
	return true;
}