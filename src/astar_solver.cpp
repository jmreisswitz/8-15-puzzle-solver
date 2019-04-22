#include <iostream>
#include <queue>
#include <set>
#include "astar_solver.h"

typedef std::pair<uint8_t, Node> AStarNode;

struct Comp {
    inline bool operator()(const AStarNode &a, const AStarNode &b) const {
    	int af = a.second.get_cost() + a.first;
    	int bf = b.second.get_cost() + b.first;
    	if (af == bf)
    		return a.first > b.first;
    	return af > bf;
    }
};

typedef std::priority_queue<AStarNode, std::vector<AStarNode>, Comp> pqueue;

bool AStarSolver::run(State initial_state) {	
	// Stats
	init_state_heuristic = heuristic(initial_state);
	// Open set
	pqueue open;
	open.push(AStarNode(init_state_heuristic, Node(initial_state, 0)));
	// Closed set
	std::set<State> closed;
	closed.insert(initial_state);
	while(!open.empty()) {
		uint8_t h = open.top().first;
		Node current = open.top().second;
		open.pop();
		closed.insert(current.get_state());
		// Check if it's goal
		if(h == 0) {
			final_cost = current.get_cost();
			return true;
		}
		// Expand neighbors
		expanded_nodes++;
		for (int i = FIRST; i <= LAST; i++) { // For each direction
			State neighbor = current.move_blank(i, num_of_columns);			
			if (neighbor == 0 || closed.count(neighbor) > 0)
				continue; // Ignore if can't move in that direction
			h = heuristic(neighbor);
			Node child_node(neighbor, current.get_cost() + 1);
            open.push(AStarNode(h, child_node));
		}
	}
	return false;
};
