#include <iostream>
#include <queue>
#include <unordered_set>
#include "astar_solver.h"
#define set std::unordered_set

#include <climits>
uint astar_counter = 0;

class AStarNode : public Node {
public:
	uint tie_breaker;
	AStarNode(State state, uint g, uint8_t h) : Node(state, g + h) {
		tie_breaker = h * H_WEIGHT + astar_counter;
		astar_counter++;
	}
};

struct Comp {
    inline bool operator()(const AStarNode &a, const AStarNode &b) const {
    	if (a.get_cost() != b.get_cost())
    		return a.get_cost() > b.get_cost();
    	return a.tie_breaker > b.tie_breaker;
    }
};

typedef std::priority_queue<AStarNode, std::vector<AStarNode>, Comp> pqueue;

bool AStarSolver::run(State initial_state) {	
	// Stats
	init_state_heuristic = heuristic(initial_state);
	astar_counter = 0;
	// Open set
	pqueue open;
	open.push(AStarNode(initial_state, 0, init_state_heuristic));
	// Closed set
	set<State> closed;
	while(!open.empty()) {
		AStarNode current = open.top();
		// Check if it's goal
		if(current.get_state() == goal) {
			final_cost = current.get_cost() - heuristic(current.get_state());
			return true;
		}
		open.pop();
		if (closed.count(current.get_state()) > 0)
			continue;
		closed.insert(current.get_state());
		uint g = current.get_cost() - heuristic(current.get_state());
		// Expand neighbors
		expanded_nodes++;
		for (int i = FIRST; i <= LAST; i++) { // For each direction
			State neighbor = current.move_blank(i, num_of_columns);		
			if (neighbor == 0 || closed.count(neighbor) > 0)
				continue; // Ignore if can't move in that direction
			uint8_t h = heuristic(neighbor);
            open.push(AStarNode(neighbor, g + 1, h));
		}
	}
	return false;
};
