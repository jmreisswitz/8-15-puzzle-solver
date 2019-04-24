#include "solver.h"

class GbfsSolver: public Solver
{
	public:
		GbfsSolver() : Solver() {}
		bool run(State initial_state);
};