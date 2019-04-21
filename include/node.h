#ifndef Node_H
#define INSTACE_H

#define FIRST 0 // assim podemos iterar
#define UP 0
#define LEFT 1
#define RIGHT 2
#define DOWN 3
#define LAST 3 // pela ordem de abertura dos nodos

#define State unsigned long

#include <vector>

State vec_to_state(std::vector<int> vec);

class Node
{
	private:
		/// attributes
		State state = 0;
        unsigned short int cost;
        unsigned short int h;

	public:
		/// constructors
		Node(State state, int unsigned short cost = 0) { 
			this->state = state; 
			this->cost = cost;
		}

		/// public methods
		State move_blank(int direction, int num_of_columns);
		bool is_goal_state();
		void print_table(int num_of_columns);
		
		inline State get_state() const { 
			return this->state; 
		}
		
		inline unsigned short int get_cost() const { 
			return this->cost; 
		}

		inline bool operator ==(const Node& param) const {
			return param.state == state;
		}

		inline bool operator <(const Node& param) const {
			return param.state < state;
		}

};


#endif /* Node_H */
