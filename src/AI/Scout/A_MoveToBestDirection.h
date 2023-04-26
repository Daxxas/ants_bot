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

            int closeAnts = 0;
            Location centroid = Location(0,0);

            for(auto myAnt : state->myAnts){
                if(ant->location.distance(myAnt.location, state->rows, state->cols) < state->viewradius) {
                    closeAnts++;
                    centroid.row += myAnt.location.row;
                    centroid.col += myAnt.location.col;
                }
            }

            centroid.row /= closeAnts;
            centroid.col /= closeAnts;
            state->correctPos(&centroid);


            if(closeAnts > 5) {
                // Go away from centroid
                Location awayFromCentroid = ant->location + centroid;
                state->correctPos(&awayFromCentroid);
                target = awayFromCentroid;

                state->bug << "ant " << ant->location << " going away from centroid " << centroid << " to " << target << " close to " << closeAnts << " ants | view radius " << state->viewradius << std::endl;
            }
            else {
                // find closest unexplored square
                Location closestUnexplored = Location(-1, -1);
                float closestUnexploredDistance = 1000000;

                for (int row = 0; row < state->rows; row++)
                {
                    for (int col = 0; col < state->cols; col++)
                    {
                        if (state->grid[row][col].isVisible || state->grid[row][col].isWater)
                        {
                            continue;
                        }

                        float distance = ant->location.manhattanDistance(Location(row, col), state->rows, state->cols);

                        if (closestUnexploredDistance > distance)
                        {
                            closestUnexplored = Location(row, col);
                            closestUnexploredDistance = distance;
                        }
                    }
                }

                state->bug << "Final closestUnexplored: " << closestUnexplored  << " isWater: " << state->grid[closestUnexplored.row][closestUnexplored.col].isWater  << " isVisible: " << state->grid[closestUnexplored.row][closestUnexplored.col].isVisible << std::endl;

                target = closestUnexplored;
            }
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