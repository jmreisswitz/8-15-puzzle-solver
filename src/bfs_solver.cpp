#include <iostream>
#include <queue>
#include <map>
#include "bfs_solver.h"
#include "solver.h"

BfsSolver::BfsSolver()
:Solver()
{};

bool BfsSolver::run(Node initial_node)
{	
	init_state_heuristic = initial_node.get_manhattan_distance(goal);
	std::queue<Node> open;
	open.push(initial_node);
	closed.insert(initial_node.get_state());
	while(!open.empty())
	{
		Node current = open.front();
		explored_nodes++;
		open.pop();
		for(int i = FIRST; i <= LAST; i++) // for each <a,s'> element of succ(state)
		{
			State neighbor = current.move_blank(i, num_of_columns);			
			if (neighbor == 0 || closed.count(neighbor) > 0){ 
				continue;
			}
			Node child_node(neighbor, current.get_cost() + 1);
			if(neighbor == goal){
				//child_node.print_table(num_of_columns);
				//finish_simulation(child_node);
				
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
