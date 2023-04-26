#include "../../BT/BT_Node.h"

class I_NoHillsNearby : public BT_Node
{
public:
  virtual NodeStatus run(Ant *ant, State *state) override
  {
    state->bug << "I_NoHillsNearby" << std::endl;

    bool hasEnnemyHill = false;

    for (int i = 0; i < state->enemyHills.size(); i++)
    {
      if (state->distance(ant->location, state->enemyHills[i]) < ANT_TO_HILL_DISTANCE)
      {
        hasEnnemyHill = true;
        break;
      }
    }

    if (hasEnnemyHill)
    {
      return NodeStatus::FAILURE;
    }
    else
    {
      return NodeStatus::SUCCESS;
    }
  }
};