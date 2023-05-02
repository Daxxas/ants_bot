#include "../../BT/BT_Node.h"

// Check if there is an ennemy hill closest than ANT_TO_HILL_DISTANCE
class I_NoHillsNearby : public BT_Node
{
public:
  virtual NodeStatus run(Ant *ant, State *state) override
  {
    state->bug << "I_NoHillsNearby" << std::endl;

    bool hasEnnemyHill = false;

    // Loop in all the hills
    for (int i = 0; i < state->enemyHills.size(); i++)
    {
      if (state->distance(ant->location, state->enemyHills[i]) < ANT_TO_HILL_DISTANCE)
      {
        hasEnnemyHill = true;
        state->bug << "Ant " << ant << " has an ennemy hill nearby" << std::endl;
        break;
      }
    }

    if (hasEnnemyHill)
    {
      state->bug << "SUCCESS Ant " << ant << " has an ennemy hill nearby" << std::endl;
      return NodeStatus::SUCCESS;
    }
    else
    {
      state->bug << "FAILURE Ant " << ant << " has no ennemy hill nearby" << std::endl;
      return NodeStatus::FAILURE;
    }
  }
};