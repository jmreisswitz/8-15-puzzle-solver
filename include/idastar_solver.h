#include "solver.h"
#include <utility>
using std::pair;

class IdAstarSolver: public Solver
{
	public:
		IdAstarSolver();
		bool run(State initial_state);
	private:
		pair<uint, uint> dfs(Node node, State parent, uint limit);
};