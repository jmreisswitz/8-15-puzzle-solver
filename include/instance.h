
#define DOWN 0
#define LEFT 1
#define RIGHT 2
#define UP 3

class Instance
{
	private:
		short int current_state[9];
		int key;
		int value;
	public:
		Instance(int start_position, int board_size, char *argv[]);
		Instance(int key, int value);
		void move_blank(int direction);
		float getKey();
		float getValue();
		
};
