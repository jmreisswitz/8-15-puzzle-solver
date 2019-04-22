#include "solver.h"

class IdfsSolver: public Solver
{
	public:
		IdfsSolver();
		bool run(State initial_state);
	private:
		uint dfs(uint depth, State current, State parent);
};