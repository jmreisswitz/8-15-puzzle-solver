#include <iostream>
#include <climits>
#include "idastar_solver.h"

IdAstarSolver::IdAstarSolver() : Solver() {};

pair<uint, uint> IdAstarSolver::dfs(Node current, uint f_limit) {
	expanded_nodes++;
	uint next_limit = UINT_MAX;
	uint neighbor_g = current.get_cost() + 1;
	for(int i = FIRST; i <= LAST; i++) {
		State neighbor = current.move_blank(i, num_of_columns);
		// If can't nove in that direction
		if (neighbor == 0) 
			continue;
		// If reached goal
		if (neighbor == goal)
			return pair<uint, uint>(neighbor_g, f_limit);
		int neighbor_f = heuristic(neighbor) + neighbor_g;
		// If reached limit
		if (neighbor_f > f_limit) {
			if (neighbor_f < next_limit)
				next_limit = neighbor_f;
			continue;
		}
		// Expand child
		Node child(neighbor, neighbor_g);
		pair<uint, uint> solution = dfs(child, f_limit);
		if (solution.second != NO_SOLUTION) {
			return solution;
		}
		if (solution.first < next_limit)
			next_limit = solution.first;
	}
	return pair<uint, uint>(next_limit, NO_SOLUTION);
}

bool IdAstarSolver::run(State initial_state) {	
	init_state_heuristic = heuristic(initial_state);
	if (initial_state == goal) {
		final_cost = 0;
		return true;
	}
	int f_limit = init_state_heuristic;
	Node initial_node(initial_state, 0);
	do {
		pair<uint, uint> solution = dfs(initial_node, f_limit);
		f_limit = solution.first;
		final_cost = solution.second;
	} while (final_cost == NO_SOLUTION);
	return true;
}