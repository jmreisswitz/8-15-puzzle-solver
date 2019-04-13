#include <iostream>
#include <bitset>
#include "instance.h"
//#include "../src/instance.cpp"

using namespace std;

/*
    valgrind usage:
    valgrind --leak-check=yes ./main
*/

inline State swap_positions(State state, int blank_position, int tile_position)
{
	std::cout << "\nswaping before: " << std::bitset<64>(state) << std::endl;
	std::cout << "swaping positions: " << blank_position << ", " << tile_position << std::endl;

	std::bitset<64> new_state(state);
	for(int i = 0; i < 4; i++){
		new_state[4*blank_position+i] = new_state[4*tile_position+i];
		new_state[4*tile_position+i] = 0;
	}

	std::cout << "swaping result: " << new_state << std::endl;
    Instance inst(new_state.to_ulong(), 0);
    inst.print_table(3);
	return new_state.to_ulong();
};


Instance test_movement(Instance t, int direction, int num_of_cols)
{
    State state = t.move_blank(direction, num_of_cols);
    if(state == 0){
        return t;
    }
    //cout << "New state generated: " << state << endl;
    Instance t2(state, num_of_cols);
    t2.print_table(num_of_cols);
    return t2;
}

void test_instance()
{
    int vec1[9] = {0,1,2,3,4,5,6,7,8};
    int vec2[9] = {1,2,3,4,5,6,7,8,0};
    int vec3[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};

    State state = vec_to_state(vec1, 9);
    cout << "first state> " << state << endl;;
    Instance t(state , 0);
    Instance t_goal(vec_to_state(vec2, 9) , 0);

    cout << "Initial State: " << endl;
    t.print_table(3);

    
    //cout << "t2 should be final state: ";
    t_goal.print_table(3);

    //cout << "trying to move up, should be null: ";
    t = test_movement(t, UP, 3);
    
    //cout << "it should be moved down:";
    t = test_movement(t, DOWN, 3);

    //cout << "and down again...:";
    t = test_movement(t, DOWN, 3);
    
    //cout << "here t must be null again: ";
    t = test_movement(t, DOWN, 3);

    //cout << "and null again, after tryng to move left: ";
    t = test_movement(t, LEFT, 3);

    //cout << "moving right..";
    t = test_movement(t, RIGHT, 3);

    //cout << "and right again...";
    t = test_movement(t, RIGHT, 3);

    //cout << "Cant move right anymore, should be NULL: ";
    t = test_movement(t, RIGHT, 3);

    //cout << "moving up!";
    t = test_movement(t, UP, 3);
    
    //cout << "moving up!";
    t = test_movement(t, UP, 3);

    //cout << "moving up again, should be null: ";
    t = test_movement(t, UP, 3);
    
}