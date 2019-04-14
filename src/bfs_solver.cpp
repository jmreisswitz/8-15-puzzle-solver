#include <iostream>
#include <queue>
#include <map>
#include "bfs_solver.h"
#include "solver.h"

BfsSolver::BfsSolver()
:Solver()
{};

bool BfsSolver::run(Instance initial_node)
{	
	init_state_heuristic = initial_node.get_manhattan_distance(goal);
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
			State neighbor = current.move_blank(i, num_of_columns);
			Instance child_node(neighbor, current.get_cost() + 1); // tá tendo que ser feito antes pois o closed pega Instancias
			if (neighbor == 0 || closed.count(child_node) > 0){ //
				continue;
			}
			
			if(neighbor == goal){
				//child_node.print_table(num_of_columns);
				//finish_simulation(child_node);
				while(!open.empty()){
					open.pop();
				}
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
