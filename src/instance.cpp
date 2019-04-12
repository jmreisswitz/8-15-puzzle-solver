#include <iostream>
#include <cmath>
#include "instance.h"

/*
/// private methods:
*/

inline State swap_positions(State state, int position1, int position2)
{
    State new_state = state;
	// TODO
	return new_state;
};

inline int get_blank_position(State& state)
{
    // TODO
}

/*
/// public methods
*/

State Instance::move_blank(int direction, int num_of_columns)
{
    int blank_position = get_blank_position(state);
    int end_position;
	if (direction == UP){
		if(blank_position - num_of_columns < 0) //if((blank_position < 3 && board_size == 8) || (blank_position < 4 && board_size==15))
			return 0;
        end_position = blank_position-num_of_columns;
	} else if(direction == DOWN){
		if (blank_position+num_of_columns > board_size)
			return 0;
		end_position = blank_position+num_of_columns;
	} else if(direction == LEFT){
		if(blank_position%num_of_columns == 0)
			return 0;
		end_position = blank_position-1;
	} else if(direction == RIGHT){
		if(blank_position%num_of_columns == num_of_columns - 1)
			return 0;
		end_position = blank_position+1;
	}
	return swap_positions(state, blank_position, end_position);
};

void Instance::print_table()
{
	int num_of_columns = get_num_of_columns();
	std::cout << "\nTable " << identifier << ":" << std::endl;
	for(int i = 0; i < board_size+1; i++){
		std::cout << current_state[i] << " ";
		if((i+1)%num_of_columns==0 && i>0)
			std::cout << std::endl;
	}
	//std::cout << "Is goal? " << is_goal_state() << std::endl;
}


/*
/// Getters and Setters
*/

unsigned short int Instance::get_manhattan_distance()
{
	return 42; //TODO manhattan_distance;
};

/*
 5
 0  1  2  3  4
 5  5  6  8  9
10 11 12 13 14
15 16 17 18 19
20 21 22 23 24

 4
 0  1  2  3
 4  5  6  7
 8  9 10 11
12 13 14 15

3
0 1 2
3 4 5
6 7 8
*/
