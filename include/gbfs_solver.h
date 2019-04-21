#include "solver.h"

class GbfsSolver: public Solver
{
	public:
		GbfsSolver();
		bool run(State initial_state);
};