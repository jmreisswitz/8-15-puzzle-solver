#include "solver.h"

class BfsSolver: public Solver
{
	public:
		BfsSolver();
		bool run(Instance initial_state);
};