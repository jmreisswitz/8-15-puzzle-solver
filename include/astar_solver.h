#include "solver.h"

class AStarSolver: public Solver
{
	public:
		AStarSolver() : Solver() {}
		bool run(State initial_state);
};