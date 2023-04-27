#include "../../BT/BT_Node.h"
#include "../AStar.h"
#include "../Bug.h"

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
            if(target != Location(-1, -1)) {
                // if new food is closer than current target, check if need to change target
                if(ant->location.manhattanDistance(food, state->rows, state->cols) < ant->location.manhattanDistance(target, state->rows, state->cols)) {
                    state->bug << "food " << food << " is closer than " << target << std::endl;
                }
                else {
                    continue;
                }
            }

            for(auto myAnt : state->myAnts)
            {
                // if an ant is closer to the food, I'm not the one for it
                if (myAnt.location.manhattanDistance(food, state->rows, state->cols) < ant->location.manhattanDistance(food, state->rows, state->cols)) {
                    target = Location(-1,-1);
                    break;
                }

                // if above is not called once, we are the best ant for this food
                target = food;
            }
        }

        state->bug << "final food target for ant " << ant->location << " is " << target << std::endl;


        // Ant isn't the best for any food, so should explore/cover map
        if(target == Location(-1, -1)) {
            target = Location(0,0); // Default location in case something goes wrong
            state->bug << "ant " << ant->location << " not best for any food" << std::endl;
            {
                // find closest unexplored square
                for (int row = 0; row < state->rows; row++) {
                    for (int col = 0; col < state->cols; col++)
                    {

                    }
                }
            }
        }

        // Don't move is no correct target
        if(target == Location(-1,-1)) {
            target = Location(0,0);
        }

        //state->bug << "Ant: " << ant->location << " Food: " << bestFood << " distance " << bestFoodDistance << std::endl;

        std::vector<Location> *path = AStar::FindPath(state, &ant->location, &target);

        state->bug << "Path size " << path->size() << std::endl;

        Location nextLoc;
        // No path found to destination
        if(path->size() <= 0) {
            // Go to opposite direction
            int diffX = ant->location.row - target.row;
            int diffY = ant->location.col - target.col;

            nextLoc = ant->location + Location(diffX/abs(diffX), diffY/abs(diffY));
            std::pair<int,int> correctedLoc = state->correctPos(nextLoc.row, nextLoc.col);
            nextLoc = Location(correctedLoc.first, correctedLoc.second);

            state->bug << "No path found to destination, changing destination to " << nextLoc << std::endl;
        }
        else {
            nextLoc = (*path)[0];
        }

        state->bug << "Next location: " << nextLoc << std::endl;
        state->makeMove(ant->location, nextLoc);

        return NodeStatus::RUNNING;
    }
};