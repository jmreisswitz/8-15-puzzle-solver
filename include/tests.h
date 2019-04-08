#include <iostream>
#include "instance.h"
#include "nheap.h"

using namespace std;

/*
    valgrind usage:
    valgrind --leak-check=yes ./main
*/


void test_heap()
{
	srand(1);
	Nheap<Instance> heap(2);
	for(int i = 0; i < 10000 ; i++ ){
		int rand_number = rand()%5000;
		heap.insert(Instance(rand_number, rand_number));
	}
	//heap.printElements();
	Instance t = heap.pop_min();
	t = heap.pop_min();
	t = heap.pop_min();
	t = heap.pop_min();
	t = heap.pop_min();
	t = heap.pop_min();
	t = heap.pop_min();
	cout << "min: " << t.get_key() << endl;

}

void print_if_not_null(Instance* t)
{
    if(t != nullptr)
        t->print_table();
    else
        cout << "t is null!" << endl;
}

void test_movement(Instance** receiver, Instance* mover, int direction, bool delete_mover)
{
    *receiver = mover->move_blank(direction);
    print_if_not_null(*receiver);
    if(delete_mover)
        delete mover;
}

void test_instance()
{
    int board_size = 8;
    unsigned short int state[16] = {0,1,2,3,4,5,6,7,8};
    Instance *t = new Instance(8, state);
    Instance *t2;
    cout << "Initial State: " << endl;
    t->print_table();

    unsigned short int state2[9] = {1,2,3,4,5,6,7,8,0};
    t2 = new Instance(8, state2);
    cout << "t2 should be final state: ";
    t2->print_table();
    delete t2;

    cout << "trying to move up, should be null: ";
    test_movement(&t2, t, UP, false);
    
    cout << "it should be moved down:";
    test_movement(&t, t, DOWN, true);

    cout << "and down again...:";
    test_movement(&t, t, DOWN, true);
    
    cout << "here t must be null again: ";
    test_movement(&t2, t, DOWN, false);

    cout << "and null again, after tryng to move left: ";
    test_movement(&t2, t, LEFT, false);

    cout << "moving right..";
    test_movement(&t, t, RIGHT, true);

    cout << "and right again...";
    test_movement(&t, t, RIGHT, true);

    cout << "Cant move right anymore, should be NULL: ";
    test_movement(&t2, t, RIGHT, false);

    cout << "moving up!";
    test_movement(&t, t, UP, true);
    
    cout << "moving up!";
    test_movement(&t, t, UP, true);

    cout << "moving up again, should be null: ";
    test_movement(&t2, t, UP, false);

    delete t;
    delete t2;

    
}