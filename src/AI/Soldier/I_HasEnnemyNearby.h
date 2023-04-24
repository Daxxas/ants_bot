#include "../../BT/BT_Node.h"
#include <cmath>

#define SQUARE_TO_CHECK 5 // Square to check (must be odd)

class I_HasEnnemyNearby : public BT_Node
{
public:
  virtual NodeStatus run(Ant &ant, State &state) override
  {
    int sizeOfSquare = (int)floor(SQUARE_TO_CHECK / 2);

    bool hasEnnemy = false;

    for (int i = -sizeOfSquare; i < sizeOfSquare + 1; i++)
    {
      for (int j = -sizeOfSquare; j < sizeOfSquare + 1; j++)
      {
        if (state.grid[ant.location.row + i][ant.location.col + j].ant > 0)
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