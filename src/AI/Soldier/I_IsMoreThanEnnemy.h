#include "../../BT/BT_Node.h"

#define SQUARE_TO_CHECK 5 // Square to check (must be odd)

class I_IsMoreThanEnnemy : public BT_Node
{
public:
  virtual NodeStatus run(Ant* ant, State* state) override
  {
    int sizeOfSquare = (int)floor(SQUARE_TO_CHECK / 2);

    int numberEnnemy = 0;
    int numberAlly = 0;

    for (int i = -sizeOfSquare; i < sizeOfSquare + 1; i++)
    {
      for (int j = -sizeOfSquare; j < sizeOfSquare + 1; j++)
      {
        if (state->grid[ant->location.row + i][ant->location.col + j].ant > 0)
        {
          numberEnnemy++;
        } else if (state->grid[ant->location.row + i][ant->location.col + j].ant == 0)
        {
          numberAlly++;
        }
      }
    }

    if (numberEnnemy < numberAlly)
    {
      return NodeStatus::SUCCESS;
    }
    else
    {
      return NodeStatus::FAILURE;
    }
  }
};