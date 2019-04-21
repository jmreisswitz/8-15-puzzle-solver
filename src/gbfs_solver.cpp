#include <iostream>
#include <queue>
#include <map>
#include <climits>
#include "gbfs_solver.h"

// https://www.cs.cmu.edu/afs/cs/project/jair/pub/volume28/coles07a-html/node11.html

typedef std::pair<unsigned short int, Node> GBFSNode;

struct Comp {
    inline bool operator()(const GBFSNode &a, const GBFSNode &b) const {
    	a.first > b.first;
    }
};

typedef std::priority_queue<GBFSNode, std::vector<GBFSNode>, Comp> pqueue;

GbfsSolver::GbfsSolver():Solver() {};

bool GbfsSolver::run(Node initial_node) {
	// Stats
	init_state_heuristic = heuristic(initial_node.get_state());
	final_cost = -1;
	// Open set
	pqueue open;
	open.push(GBFSNode(init_state_heuristic, initial_node));
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
            open.push(GBFSNode(h, child_node));
		}
	}
	return false;
};