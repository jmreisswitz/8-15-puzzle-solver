#include <iostream>
#include <queue>
#include <unordered_set>
#include "gbfs_solver.h"
#define set std::unordered_set

uint gbfs_counter = 0;

struct GbfsNode : public Node {
public:
	uint tie_breaker;
	GbfsNode(State state, uint g, uint8_t h) : Node(state, g) {
		tie_breaker = h * H_WEIGHT + gbfs_counter;
		gbfs_counter++;
	}
};

struct Comp {
    inline bool operator()(const GbfsNode &a, const GbfsNode &b) const {
    	return a.tie_breaker > b.tie_breaker;
    }
};

typedef std::priority_queue<GbfsNode, std::vector<GbfsNode>, Comp> pqueue;

GbfsSolver::GbfsSolver():Solver() {};

bool GbfsSolver::run(State initial_state) {
	// Stats
	init_state_heuristic = heuristic(initial_state);
	gbfs_counter = 0;
	// Open set
	pqueue open;
	open.push(GbfsNode(initial_state, 0, init_state_heuristic));
	// Closed set
	set<State> closed;
	while(!open.empty()) {
		GbfsNode current = open.top();
		// Check if it's goal
		if(current.get_state() == goal) {
			final_cost = current.get_cost();
			return true;
		}
		open.pop();
		if (closed.count(current.get_state()) > 0)
			continue;
		closed.insert(current.get_state());
		// Expand neighbors
		expanded_nodes++;
		for (int i = FIRST; i <= LAST; i++) { // For each direction
			State neighbor = current.move_blank(i, num_of_columns);		
			if (neighbor == 0 || closed.count(neighbor) > 0)
				continue; // Ignore if can't move in that direction
			uint8_t h = heuristic(neighbor);
            open.push(GbfsNode(neighbor, current.get_cost() + 1, h));
		}
	}
	return false;
};