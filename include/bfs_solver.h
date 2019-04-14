#include "solver.h"

class BfsSolver: public Solver
{
	public:
		BfsSolver();
		bool run(Node initial_state);
};