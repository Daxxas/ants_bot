#include "../../BT/BT_Node.h"
#include "../AStar.h"
#include "../Bug.h"
#include "BFS.h"

class A_MoveToBestDirection : public BT_Node
{
public:
    virtual NodeStatus run(Ant *ant, State *state) override
    {
        state->bug << "A_MoveToBestDirection" << std::endl;

        Location target = Location(-1, -1);

        // target closest food if I'm the best ant
        for (auto food : state->food)
        {
            state->bug << "looping food " << food << std::endl;

            for(auto myAnt : state->myAnts)
            {
                state->bug << "looping ant " << myAnt.location << std::endl;

                // if an ant is closer to the food, I'm not the one for it
                if (myAnt.location.manhattanDistance(food, state->rows, state->cols) < ant->location.manhattanDistance(food, state->rows, state->cols)) {
                    target = Location(-1,-1);
                    break;
                }

                // if above is not called once, we are the best ant for this food
                state->bug << "best ant for food " << food << " should be " << ant->location << std::endl;
                target = food;

                // no better ant found other than me
            }
        }

        // Ant isn't the best for any food, so should explore/cover map
        if(target == Location(-1, -1)) {
            state->bug << "ant " << ant->location << " not best for any food" << std::endl;

            // find closest unexplored square
            Location closestUnexplored = Location(-1, -1);
            int closestUnexploredDistance = 1000000;

            for (int row = 0; row < state->rows; row++)
            {
                for (int col = 0; col < state->cols; col++)
                {
                    if (state->grid[row][col].isVisible)
                    {
                        continue;
                    }

                    if (closestUnexploredDistance > ant->location.distance(Location(row, col), state->rows, state->cols))
                    {
                        closestUnexplored = Location(row, col);
                        closestUnexploredDistance = ant->location.distance(Location(row, col), state->rows, state->cols);
                    }
                }
            }

            target = closestUnexplored;

        }

        //state->bug << "Ant: " << ant->location << " Food: " << bestFood << " distance " << bestFoodDistance << std::endl;

        std::vector<Location> *path = AStar::FindPath(state, &ant->location, &target);

        state->bug << "Next location: " << (*path)[0] << std::endl;
        state->makeMove(ant->location, (*path)[0]);

        return NodeStatus::RUNNING;
    }
};