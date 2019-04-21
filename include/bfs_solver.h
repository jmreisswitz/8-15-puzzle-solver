#include "solver.h"

class BfsSolver: public Solver
{
	public:
		BfsSolver();
		bool run(State initial_state);
};