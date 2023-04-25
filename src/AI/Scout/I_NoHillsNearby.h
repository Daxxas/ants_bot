#include "../../BT/BT_Node.h"

class I_NoHillsNearby : public BT_Node
{
public:
  virtual NodeStatus run(Ant *ant, State *state) override
  {
    state->bug << "I_NoHillsNearby" << std::endl;

    int sizeOfSquare = (int)floor(SQUARE_TO_CHECK / 2);

    bool hasEnnemyHill = false;

    for (int i = -sizeOfSquare; i < sizeOfSquare + 1; i++)
    {
      for (int j = -sizeOfSquare; j < sizeOfSquare + 1; j++)
      {
        int newPosX = ant->location.row + i;
        int newPosY = ant->location.col + j;
        auto pos = state->correctPos(newPosX, newPosY);

        state->bug << pos.first << "," << pos.second << state->grid[pos.first][pos.second].isHill << " " << state->grid[pos.first][pos.second].hillPlayer << std::endl;

        if (state->grid[pos.first][pos.second].isHill && state->grid[pos.first][pos.second].hillPlayer > 0)
        {
          state->bug << "Found ennemy hill" << std::endl;
          hasEnnemyHill = true;
        }
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