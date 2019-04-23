#include <iostream>
#include <queue>
#include <climits>
#include <unordered_set>
#include "gbfs_solver.h"
#define set std::unordered_set

typedef std::pair<uint8_t, Node> GBFSNode;

struct Comp {
    inline bool operator()(const GBFSNode &a, const GBFSNode &b) const {
    	return a.first > b.first;
    }
};

typedef std::priority_queue<GBFSNode, std::vector<GBFSNode>, Comp> pqueue;

GbfsSolver::GbfsSolver():Solver() {};

bool GbfsSolver::run(State initial_state) {
	// Stats
	init_state_heuristic = heuristic(initial_state);
	// Open set
	pqueue open;
	open.push(GBFSNode(init_state_heuristic, Node(initial_state, 0)));
	// Closed set
	set<State> closed;
	while(!open.empty()) {
		uint8_t h = open.top().first;
		Node current = open.top().second;
		open.pop();
		// Check if it's goal
		if(h == 0) {
			final_cost = current.get_cost();
			return true;
		}
		if (closed.count(current.get_state()) > 0)
			continue;
		closed.insert(current.get_state());
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