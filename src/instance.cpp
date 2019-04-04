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

Instance::Instance(int key, int value)
{
	this->key = key;
	this->value = value;
}

void Instance::move_blank(int direction)
{
	std::cout << "TODO" << std::endl;
};


float Instance::getValue()
{
	return value;	
};

float Instance::getKey()
{
	return key;
};