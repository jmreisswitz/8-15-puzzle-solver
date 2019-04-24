#include "solver.h"

class BfsSolver: public Solver
{
	public:
		BfsSolver() : Solver() {}
		bool run(State initial_state);
};