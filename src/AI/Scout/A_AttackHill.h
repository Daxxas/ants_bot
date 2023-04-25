#include "../../BT/BT_Node.h"

#define SQUARE_TO_CHECK 5 // Square to check (must be odd)

class A_AttackHill : public BT_Node
{
public:
  virtual NodeStatus run(Ant *ant, State *state) override
  {
    state->bug << "A_AttackGaze" << std::endl;

    int sizeOfSquare = (int)floor(SQUARE_TO_CHECK / 2);

    for (int i = -sizeOfSquare; i < sizeOfSquare + 1; i++)
    {
      for (int j = -sizeOfSquare; j < sizeOfSquare + 1; j++)
      {
        state->bug << "Checking " << ant->location.row + i << " " << ant->location.col + j << std::endl;
        int newPosX = ant->location.row + i;
        int newPosY = ant->location.col + j;
        auto pos = state->correctPos(newPosX, newPosY);

        if (state->grid[pos.first][pos.second].isHill && state->grid[pos.first][pos.second].hillPlayer > 0)
        {
          state->bug << "Found hill of player " << state->grid[pos.first][pos.second].hillPlayer << std::endl;
          ant->setMeetingPoint(pos.first, pos.second);
          return NodeStatus::SUCCESS;
        }
      }
    }

    return NodeStatus::SUCCESS;
  }
};