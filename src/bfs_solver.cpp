#include <iostream>
#include <queue>
#include <unordered_set>
#include "bfs_solver.h"
#define set std::unordered_set

BfsSolver::BfsSolver() : Solver() {};

bool BfsSolver::run(State initial_state)
{	
	// Stats
	init_state_heuristic = heuristic(initial_state);
	heuristic_avg = 0;
	if (initial_state == goal) {
		final_cost = 0;
		return true;
	}
	// Open set
	std::queue<Node> open;
	open.push(Node(initial_state, 0));
	// Closed set
	set<State> closed;
	closed.insert(initial_state);
	while(!open.empty())
	{
		Node current = open.front();
		open.pop();
		// Expand neighbors
		expanded_nodes++;
		for(int i = FIRST; i <= LAST; i++) // for each <a,s'> element of succ(state)
		{
			State neighbor = current.move_blank(i, num_of_columns);			
			if (neighbor == 0 || closed.count(neighbor) > 0){ 
				continue;
			}
			Node child_node(neighbor, current.get_cost() + 1);
			if(neighbor == goal){
				//child_node.print_table(num_of_columns);
				final_cost = child_node.get_cost();
				return true;
			}
            //std::cout << "inserindo em closed: ";
            //child_node.print_table(num_of_columns);
            closed.insert(neighbor);
            open.push(child_node);
		}
	}
	return false;
};
