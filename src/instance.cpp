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
		identifier += (unsigned long int)(i+1)*current_state[i];
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
	for(int i = 0; i < board_size+1; i++)
	{
		current_state[i] = state[i];
		identifier += (unsigned long int)(i+1)*current_state[i];
		if(current_state[i] == 0)
			blank_position = i;		
	}
};


/*
/// private methods:
*/

void Instance::generate_manhattan_distance()
{

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

/*
/// public methods
*/


Instance* Instance::move_blank(int direction)
{
	int num_of_columns = get_num_of_columns();
	if (direction == UP){
		if(blank_position - num_of_columns < 0) //if((blank_position < 3 && board_size == 8) || (blank_position < 4 && board_size==15))
			return NULL;
		swap_positions(blank_position, blank_position-num_of_columns);
		Instance* t = new Instance(board_size, current_state);
		swap_positions(blank_position-num_of_columns, blank_position);
		return t;
	}
	if(direction == DOWN){
		if (blank_position+num_of_columns > board_size)
			return NULL;
		swap_positions(blank_position, blank_position+num_of_columns);
		Instance* t = new Instance(board_size, current_state);
		swap_positions(blank_position+num_of_columns, blank_position);
		return t;
	}
	if(direction == LEFT){
		return NULL; // TODO
	}
	if(direction == RIGHT){
		return NULL; // TODO
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
	std::cout << "Table " << identifier << ":" << std::endl;
	for(int i = 0; i < board_size+1; i++){
		if((i+1)%num_of_columns && i>0)
			std::cout << std::endl;
		std::cout << current_state[i] << " ";
	}
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

