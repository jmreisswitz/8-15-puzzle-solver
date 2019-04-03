
#define DOWN 0
#define LEFT 1
#define RIGHT 2
#define UP 3

class Instance
{
	private:
		short int current_state[9];
	public:
		Instance(int start_position, int board_size, char *argv[]);
		void move_blank(int direction);		
};
