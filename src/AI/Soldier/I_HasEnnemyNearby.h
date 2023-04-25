#include "../../BT/BT_Node.h"
#include <cmath>

class I_HasEnnemyNearby : public BT_Node
{
public:
  virtual NodeStatus run(Ant *ant, State *state) override
  {
    state->bug << "I_HasEnnemyNearby" << std::endl;

    int sizeOfSquare = (int)floor(SQUARE_TO_CHECK / 2);

    bool hasEnnemy = false;

    for (int i = -sizeOfSquare; i < sizeOfSquare + 1; i++)
    {
      for (int j = -sizeOfSquare; j < sizeOfSquare + 1; j++)
      {
        auto pos = state->correctPos(ant->location.row + i, ant->location.col + j);

        if (
            state->grid[pos.first][pos.second].ant > 0 ||
            (state->grid[pos.first][pos.second].hillPlayer > 0 &&
             state->grid[pos.first][pos.second].isHill))
        {
          hasEnnemy = true;
        }
      }
    }

    if (hasEnnemy)
    {
      return NodeStatus::SUCCESS;
    }
    else
    {
      return NodeStatus::FAILURE;
    }
  }
};