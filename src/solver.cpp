#include<iostream>
#include <ios>
#include "solver.h"

using namespace std;

//#define LINEAR_CONFLITC

Solver::Solver()
{
	expanded_nodes = 0;
	heuristic_avg = 0;
	heuristic_count = 0;
	final_cost = NO_SOLUTION;
};

void Solver::print_stats(double execution_time)
{
	cout << expanded_nodes << ", ";

	if (final_cost == NO_SOLUTION)
		cout << "-, ";
	else
		cout << final_cost << ", ";

    cout << std::fixed << execution_time << ", "
         << 1.0 * heuristic_avg / heuristic_count << ", "
         << (int) init_state_heuristic << endl;
}

/*
/// Heuristic
*/

inline uint8_t uabs(uint8_t x, uint8_t y) {
	return x > y ? x - y : y - x;
}

inline uint8_t get_manhattan_distance(uint num_of_cols, State state)
{

	#ifdef LINEAR_CONFLITC
	int8_t swap_col[num_of_cols];
	int8_t swap_row[num_of_cols];
	uint8_t col_conflicts = 0, row_conflicts = 0;
	for (int i = 0; i < num_of_cols; i++) {
		swap_col[i] = swap_row[i] = -1;
	}
	#endif

	uint8_t result = 0;
	unsigned long int aux = 15; // 1111
	unsigned long int number;
	uint8_t board_size = num_of_cols*num_of_cols;
	uint8_t x = 0, y = 0;
	for(uint8_t i = 0; i < board_size; i++)
	{
		// Get the number of the tile in the position (x, y) of the board.
		number = state&aux;
		number = number>>(i*4);
		if(number > 0 && number!=i)
		{
			// Get the position where this tile should be.
			uint8_t supposed_x = number % num_of_cols;
			uint8_t supposed_y = number / num_of_cols;
			result += uabs(x, supposed_x) + uabs(y, supposed_y);

			#ifdef LINEAR_CONFLITC
			// Horizontal conflicts
			if (supposed_y == y) {
				if (swap_row[y] > x)
					row_conflicts++;
				swap_row[y] = supposed_x;
			}
			// Vertical conflicts
			if (supposed_x == x) {
				if (swap_col[x] > y)
					col_conflicts++;
				swap_col[x] = supposed_y;
			}
			#endif

		}
		x++;
		if(x%num_of_cols== 0){
			x = 0;
			y++;
		}
		aux = aux<<4;
	}

	#ifdef LINEAR_CONFLITC
	result += row_conflicts + col_conflicts;
	#endif

	return result;
};

uint8_t Solver::heuristic(State state) {
	heuristic_count++;
	uint8_t h = get_manhattan_distance(num_of_columns, state);
	heuristic_avg += h;
	return h;
}