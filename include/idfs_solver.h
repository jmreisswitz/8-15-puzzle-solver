#include "solver.h"

class IdfsSolver: public Solver
{
	public:
		IdfsSolver();
		bool run(State initial_state);
	private:
		int dfs(int depth, State current);
};