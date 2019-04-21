#include<iostream>
#include "solver.h"

using namespace std;

Solver::Solver()
{
	expanded_nodes = 0;
	heuristic_avg = 0;
};

void Solver::print_stats(unsigned long execution_time)
{
	/// aqui a ideia é setar as variáveis de print_stats para depois imprimir elas com print_status
	/// pode ser que esse método nem seja preciso, sei lá
	cout<< expanded_nodes << ", "
        << final_cost << ", "
        << execution_time << ", "
        << heuristic_avg << ", "
        << init_state_heuristic << endl;
};

/*
/// Heuristic
*/
inline unsigned long int uabs_diff(unsigned long v1, unsigned long v2)
{
	if(v1-v2 > 0x7fffffffffff)
		return v2-v1;
	return v1-v2;
}

inline unsigned int get_col_diff(unsigned long number, unsigned long i, unsigned int num_of_cols)
{
	unsigned long numbers_distance = uabs_diff(i, number);
	if(numbers_distance >= num_of_cols){
		return numbers_distance/num_of_cols;
	}
	if(number%num_of_cols == 0){
		return 1;
	}
}

inline unsigned short int get_manhattan_distance(unsigned int num_of_cols, State state)
{
	unsigned long int result = 0;
	State aux = 15; // 1111
	unsigned long int number;
	unsigned int row_diff, col_diff;
	unsigned int board_size = num_of_cols*num_of_cols;
	unsigned int x = 0, y = 0;
	for(unsigned long int i = 1; i < (num_of_cols*num_of_cols) + 1; i++)
	{
		number = state&aux;
		number = number>>((i-1)*4);
		if(number > 0 && number!=i)
		{
			unsigned int suposed_x = (number-1)/num_of_cols;
			unsigned int suposed_y = (number-1)%num_of_cols;
			/*
			std::cout << "number: " << number << ", i: " << i << std::endl;
			std::cout << "suposed_y: " << suposed_y << ", suposed_x: " << suposed_x << std::endl;
			std::cout << "curent x: " << x << ",current y: " << y << std::endl;
			std::cout << "dx: " << uabs_diff(x, suposed_y) << ", dx = " << uabs_diff(y, suposed_x) << std::endl;
			*/
			result += uabs_diff(x, suposed_y) + uabs_diff(y, suposed_x);
		}
		x++;
		if(x%num_of_cols== 0){
			x = 0;
			y++;
		}
		aux = aux<<4;
	}
	return (unsigned short int) result;
};

unsigned short int Solver::heuristic(State state) {
	return get_manhattan_distance(num_of_columns, state);
}