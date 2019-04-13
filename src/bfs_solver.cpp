#include <iostream>
#include <queue>
#include <map>
#include "bfs_solver.h"

BfsSolver::BfsSolver()
:Solver()
{};

bool BfsSolver::run(Instance initial_node)
{
	/*
	init_state_heuristic = initial_node.get_manhattan_distance();
	std::queue<Instance> open;
	open.push(initial_node);
	closed.insert(initial_node);
	while(!open.empty())
	{
		Instance current = open.front();
		explored_nodes++;
		open.pop();
		for(int i = FIRST; i <= LAST; i++) // for each <a,s'> element of succ(state)
		{
			State neighbor = current.move_blank(i, );
			if (neighbor == 0 || closed.count(neighbor)){ //
				continue;
			}
			Instance child_node(neighbor, current.cost + 1);
			if(neighbor == goal)){
				child_node->print_table();
				finish_simulation(child_node);
				open.clear();
				return true;
			}
            std::cout << "inserindo em closed: ";
            child_node->print_table();
            closed.insert(neighbor);
            open.push_back(child_node);
		}
	}
	*/
	return false;
};
