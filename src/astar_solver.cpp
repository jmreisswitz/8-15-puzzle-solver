#include <iostream>
#include <queue>
#include "astar_solver.h"

typedef std::pair<unsigned short int, Node> AStarNode;

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

bool AStarSolver::run(Node initial_node) {	
	// Stats
	init_state_heuristic = heuristic(initial_node.get_state());
	final_cost = -1;
	// Open set
	pqueue open;
	open.push(AStarNode(init_state_heuristic, initial_node));
	// Closed set
	std::set<State> closed;
	closed.insert(initial_node.get_state());
	while(!open.empty()) {
		unsigned short int h = open.top().first;
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
