#include "../../BT/BT_Node.h"

// Check around to see if there is an ennemy nearby
class I_NoEnnemyNearby : public BT_Node
{
public:
    virtual NodeStatus run(Ant *ant, State *state) override
    {
        state->bug << "I_NoEnnemyNearby" << std::endl;

        int sizeOfSquare = (int)floor(SQUARE_TO_CHECK / 2);

        bool hasEnnemy = false;

        // Check the position near
        for (int i = -sizeOfSquare; i < sizeOfSquare + 1; i++)
        {
            for (int j = -sizeOfSquare; j < sizeOfSquare + 1; j++)
            {
                int newPosX = ant->location.row + i;
                int newPosY = ant->location.col + j;
                auto pos = state->correctPos(newPosX, newPosY);

                if (state->grid[pos.first][pos.second].ant > 0)
                {
                    hasEnnemy = true;
                    state->bug << "Ant " << ant << " has an ennemy nearby" << std::endl;
                }
            }
        }

        if (hasEnnemy)
        {
            state->bug << "SUCCESS Ennemy Nearby, should attack " << std::endl;

            return NodeStatus::SUCCESS;
        }
        else
        {
            state->bug << "FAILURE No Ennemy Nearby, should continue " << std::endl;

            return NodeStatus::FAILURE;
        }
    }
};