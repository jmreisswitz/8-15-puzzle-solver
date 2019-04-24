#include <iostream>
#include <queue>
#include <unordered_set>
#include "astar_solver.h"
#define set std::unordered_set

#include <climits>
uint astar_counter = 0;

// A Node that includes a tie-breaker value.
// Stores the f(n) value instead of g(n) as the Node's cost, so the comparator do not need to store/compute h(s).
// The H_WEIGHT is (INT_MAX / 90), as 90 is the maximum manhatan distance.
// It is assumed that astar_counter never reaches H_WEIGHT value (which is very big), 
// so it is only used as a tie-breaker when h(s) is the same.
class AStarNode : public Node {
public:
	uint tie_breaker;
	uint8_t h;
	AStarNode(State state, uint g, uint8_t h) : Node(state, g + h) {
		this->h = h;
		tie_breaker = (h + 1) * H_WEIGHT - astar_counter;
		astar_counter++;
	}
};

// Comparator for the prioriy queue.
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
			final_cost = current.get_cost() - current.h;
			return true;
		}
		open.pop();
		// Check if closed
		if (closed.count(current.get_state()) > 0)
			continue;
		closed.insert(current.get_state());
		uint g = current.get_cost() - current.h;
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
