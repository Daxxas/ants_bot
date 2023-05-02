#include "../../BT/BT_Node.h"

#include "../../AStar.h"

// If an hill is nearby, attack it
class A_AttackHill : public BT_Node
{
public:
  virtual NodeStatus run(Ant *ant, State *state) override
  {
    state->bug << "A_AttackHill" << std::endl;

    // Find if there is an enemy hill nearby
    bool hasEnnemyHill = false;

    Location hillLocation;

    for (int i = 0; i < state->enemyHills.size(); i++)
    {
      if (state->distance(ant->location, state->enemyHills[i]) < ANT_TO_HILL_DISTANCE)
      {
        hillLocation = Location(state->enemyHills[i].row, state->enemyHills[i].col);
        state->bug << "Sending ant " << ant << " to " << state->enemyHills[i].row << " " << state->enemyHills[i].col << std::endl;

        break;
      }
    }

    // Set the hill destination of the ant for next moves
    ant->setHillDestination(hillLocation.row, hillLocation.col);

    // Find the path to the hill and move to it
    auto path = AStar::FindPath(state, &ant->location, &hillLocation);

    Location nextLoc;
    // No path found to destination, stay in place
    if (path->size() <= 0)
    {
      nextLoc = ant->location;
    }
    else
    {
      nextLoc = (*path)[0];
    }

    state->makeMove(ant->location, nextLoc);

    return NodeStatus::RUNNING;
  }
};