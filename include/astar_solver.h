#include "solver.h"

class AStarSolver: public Solver
{
	public:
		AStarSolver() : Solver() {}
		bool run(Node initial_state);
};