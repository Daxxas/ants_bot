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

        Location bestAnt = Location(-1, -1);
        Location bestFood = Location(-1, -1);
        int bestAntDistance = 1000000;

        for (auto food : state->food)
        {
            for(auto myAnt : state->myAnts) {

                if (bestAntDistance > myAnt.location.distance(food, state->rows, state->cols))
                {
                    bestAnt = myAnt.location;
                    bestFood = food;
                    bestAntDistance = myAnt.location.distance(food, state->rows, state->cols);
                }
            }
        }

        if(bestAnt != Location(-1, -1) && bestAnt == ant->location)
        {
            state->bug << "ant " << ant->location << " best for food " << bestFood << std::endl;

            target = bestFood;

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