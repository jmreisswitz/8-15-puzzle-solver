#include <iostream>
#include "instance.h"


Instance::Instance(int start_position, int board_size, char *argv[])
{
	for(int i = 0; i < board_size+1; i++)
	{
		current_state[i] = atoi(argv[i+start_position]);
		//std::cout << current_state[i] << std::endl;
	}
};


void Instance::move_blank(int direction)
{
	std::cout << "TODO" << std::endl;
};


float Instance::getValue()
{
	return 1;	
};

float Instance::getKey()
{
	return 2;
};