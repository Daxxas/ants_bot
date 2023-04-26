#include "../../BT/BT_Node.h"

class A_AttackHill : public BT_Node
{
public:
  virtual NodeStatus run(Ant *ant, State *state) override
  {
    state->bug << "A_AttackHill" << std::endl;

    bool hasEnnemyHill = false;

    for (int i = 0; i < state->enemyHills.size(); i++)
    {
      if (state->distance(ant->location, state->enemyHills[i]) < ANT_TO_HILL_DISTANCE)
      {
        ant->setMeetingPoint(state->enemyHills[i].row, state->enemyHills[i].col);
        state->bug << "Sending ant " << ant << " to " << state->enemyHills[i].row << " " << state->enemyHills[i].col << std::endl;

        break;
      }
    }

    return NodeStatus::SUCCESS;
  }
};