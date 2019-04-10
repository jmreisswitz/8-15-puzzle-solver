#include <iostream>
#include <list>
#include <map>
#include "bfs_solver.h"

BfsSolver::BfsSolver()
:Solver()
{};

bool BfsSolver::run(Instance initial_state)
{
	init_state_heuristic = initial_state.get_manhattan_distance();
	std::list<Instance> open;
	open.push_back(initial_state);
	insert_into_closed(initial_state);
	while(!open.empty())
	{
		Instance t = open.front();
		open.pop_front();
		for(int i = FIRST; i <= LAST; i++) // for each <a,s'> element of succ(state)
		{
			Instance* t_line = t.move_blank(i);
			if (t_line == nullptr){ // 
				continue;
			}
			if(t_line->is_goal_state()){
				t_line->print_table();
				finish_simulation();
				open.clear();
				delete t_line;
				return true;
			}
			if(!is_on_closed(t_line)){
				std::cout << "inserindo em closed: ";
				t_line->print_table();
				insert_into_closed(*t_line);
				open.push_back(*t_line);				
			}
			delete t_line;
		}
	}
	
	return false;
};