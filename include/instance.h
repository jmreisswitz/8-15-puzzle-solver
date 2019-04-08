
#define DOWN 0
#define LEFT 1
#define RIGHT 2
#define UP 3

class Instance
{
	private:
		/// attributes
		unsigned short int current_state[16];
		unsigned short int manhattan_distance;
		int value;
		int blank_position;
		unsigned short int board_size;
		unsigned long int identifier;
		
		/// private methods
		void generate_manhattan_distance();
		void swap_positions(int position1, int position2);
		int get_num_of_columns();
		Instance* gen_new_instance(int end_position);

	public:
		/// constructors
		Instance(int start_position, unsigned short int board_size, char *argv[]);
		Instance(unsigned short int key, int value);
		Instance(unsigned short int board_size, unsigned short int* state);

		/// public methods
		Instance* move_blank(int direction);
		bool is_goal_state();
		void print_table();


		/// getters ans setters
		unsigned short int get_manhattan_distance();
		unsigned long get_identifier();
		float get_key();
		float get_value();
};
