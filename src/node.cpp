#include <iostream>
#include <cmath>
#include <bitset>
#include <vector>
#include "node.h"

inline State swap_positions(State state, int blank_position, int tile_position)
{
	std::bitset<64> new_state(state);
	for(int i = 0; i < 4; i++){
		new_state[4*blank_position+i] = new_state[4*tile_position+i];
		new_state[4*tile_position+i] = 0;
	}
	return new_state.to_ulong();
};

inline int get_blank_position(State& state, int num_of_columns)
{
	State aux = 15; // 1111
    for(int i = 0; i < num_of_columns*num_of_columns; i++)
	{
		if((aux&state) == 0){
			return i;
		}
		aux = aux<<4;
	}
}

State vec_to_state(std::vector<int> vec)
{
	State state = 0;
	State aux;
	for(int i = 0; i < vec.size(); i++){
		aux = 0;
		state = state|((aux|vec[i])<<(i*4));
		
	}
	return state;
}

void state_to_vec(State state, int* vec, int vec_size)
{
    State aux;
    for(int i = 0; i < vec_size; i++)
    {
        aux = state>>(i*4);
        vec[i] = 15&aux;
    }
}

State Node::move_blank(int direction, int num_of_columns)
{
	int board_size = num_of_columns == 4 ? 16 : 9;
    int blank_position = get_blank_position(state, num_of_columns);
    int end_position;
	if (direction == UP){
		if(blank_position - num_of_columns < 0)
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

void Node::print_table(int num_of_columns)
{
	int board_size = num_of_columns == 4 ? 16 : 9;
	int state_vec[16];
	state_to_vec(state, state_vec, num_of_columns*num_of_columns);
	std::cout << "Table " << state << ":" << std::endl;
	for(int i = 0; i < board_size; i++){
		std::cout << state_vec[i] << " ";
		if((i+1)%num_of_columns==0 && i>0)
			std::cout << std::endl;
	}
}

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
