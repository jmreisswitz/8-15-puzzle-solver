#ifndef INSTANCE_H
#define INSTACE_H

#define FIRST 0 // assim podemos iterar
#define UP 0
#define LEFT 1
#define RIGHT 2
#define DOWN 3
#define LAST 3 // pela ordem de abertura dos nodos

#define State unsigned long


State vec_to_state(int* vec, int size);

class Instance
{
	private:
		/// attributes
		State state = 0;
        unsigned int cost;

	public:
		/// constructors
		Instance(State state, int cost = 0) { this->state = state; this->cost = cost;};

		/// public methods
		State move_blank(int direction, int num_of_columns);
		bool is_goal_state();
		void print_table(int num_of_columns);

		/// getters ans setters
		unsigned short int get_manhattan_distance(State goal);
		State get_state() {return this->state;};
};


#endif /* INSTANCE_H */
