#include <iostream>
#include <cmath>
#include "instance.h"


Instance::Instance(int start_position, unsigned short int board_size, char *argv[])
{
	identifier = 0;
	this->board_size = board_size;
	for(int i = 0; i < board_size+1; i++)
	{
		current_state[i] = atoi(argv[i+start_position]);
		identifier += (unsigned long int)(pow(10, i))*current_state[i];
		std::cout << identifier << std::endl;
		if(current_state[i] == 0)
			blank_position = i;		
	}
	
};

Instance::Instance(unsigned short int key, int value)
{
	this->manhattan_distance = key;
	this->value = value;
}

Instance::Instance(unsigned short int board_size, unsigned short int* state)
{
	identifier = 0;
	this->board_size = board_size;
	for(unsigned short int i = 0; i < board_size+1; i++)
	{
		current_state[i] = state[i];
		identifier += (unsigned long int)(pow(10, i))*state[i];
		if(current_state[i] == 0)
			blank_position = i;		
	}
};


/*
/// private methods:
*/

void Instance::generate_manhattan_distance()
{
	manhattan_distance = 1; // TODO
};

void Instance::swap_positions(int position1, int position2)
{
	unsigned short int aux = current_state[position1];
	current_state[position1] = current_state[position2];
	current_state[position2] = aux;
};

int Instance::get_num_of_columns()
{
	return (int) sqrt(board_size+1);
}

Instance* Instance::gen_new_instance(int end_position)
{
	swap_positions(blank_position, end_position);
	Instance* t = new Instance(board_size, current_state);
	swap_positions(end_position, blank_position);
	return t;
}

/*
/// public methods
*/

Instance* Instance::move_blank(int direction)
{
	int num_of_columns = get_num_of_columns();
	if (direction == UP){
		if(blank_position - num_of_columns < 0) //if((blank_position < 3 && board_size == 8) || (blank_position < 4 && board_size==15))
			return NULL;
		return gen_new_instance(blank_position-num_of_columns);
	}
	if(direction == DOWN){
		if (blank_position+num_of_columns > board_size)
			return NULL;
		return gen_new_instance(blank_position+num_of_columns);
	}
	if(direction == LEFT){
		if(blank_position%num_of_columns == 0)
			return NULL;
		return gen_new_instance(blank_position-1);
	}
	if(direction == RIGHT){
		if(blank_position%num_of_columns == num_of_columns - 1)
			return NULL;
		return gen_new_instance(blank_position+1);
	}
	return NULL; // shouldnt never reach here
};

bool Instance::is_goal_state()
{
	for(int i = 0; i < board_size; i++){
		if((i+1)%(board_size+1) != current_state[i])
			return false;
	}
	return true;
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
	std::cout << "Is goal? " << is_goal_state() << std::endl;
}


/*
/// Getters and Setters
*/

unsigned long int Instance::get_identifier()
{
	return identifier;
};

// used only for heap functions. Not important
float Instance::get_value()
{
	return (float) identifier;	
};

/// used
float Instance::get_key()
{
	return (float) manhattan_distance;
};

unsigned short int Instance::get_manhattan_distance()
{
	return manhattan_distance;
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