#include "../../BT/BT_Node.h"
#include "../../AStar.h"

// Walk to and hill if there is an HillDestination
class A_WalkToHillDestination : public BT_Node
{
public:
  virtual NodeStatus run(Ant *ant, State *state) override
  {
    state->bug << "A_WalkToHillDestination" << std::endl;

    Location nextAstar = AStar::FindPath(state, &ant->location, &ant->hillDestination);

    Location nextLoc;
    // No path found to destination, stay in place
    if (nextAstar == Location(0,0))
    {
      nextLoc = ant->location;
    }
    else
    {
      nextLoc = nextAstar;
    }

    state->makeMove(ant->location, nextLoc);

    return NodeStatus::RUNNING;
  }
};