#include "solver.h"

class GbfsSolver: public Solver
{
	public:
		GbfsSolver();
		bool run(Node initial_state);
};