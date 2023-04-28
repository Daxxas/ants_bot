#include "../../BT/BT_Node.h"
#include "../AStar.h"
#include "../Bug.h"

bool IsSquareNotVisible(Square square){
    return !square.isVisible;
}

class A_MoveToBestDirection : public BT_Node
{
public:
    virtual NodeStatus run(Ant *ant, State *state) override
    {
        state->bug << "A_MoveToBestDirection" << std::endl;

        Location target = Location(-1, -1);

        // target closest food if I'm the best ant
        state->bug << "foodDestination " << ant->foodDestination << std::endl;
        if(ant->foodDestination != (Location(-1,-1))) {
            target = ant->foodDestination;
        }

        state->bug << "final food target for ant " << ant->location << " is " << target << std::endl;


        // Ant isn't the best for any food, so should explore/cover map
        if(target == Location(-1, -1)) {
            target = Location(0,0); // Default location in case something goes wrong
            state->bug << "ant " << ant->location << " not best for any food" << std::endl;
            state->bug << "Timer before BFS: " << state->timer.getTime() << " ms" << std::endl;
            // find closest unexplored square
            Location closestUnexplored = BFS::GetBFSPosition(state, &ant->location, 20, &IsSquareNotVisible);
            state->bug << "Timer after BFS: " << state->timer.getTime() << " ms" << std::endl;

            state->bug << "closestUnexplored for ant " << ant->location << " is " << closestUnexplored << std::endl;

            state->bug << "Final closestUnexplored: " << closestUnexplored  << " isWater: " << state->grid[closestUnexplored.row][closestUnexplored.col].isWater  << " isVisible: " << state->grid[closestUnexplored.row][closestUnexplored.col].isVisible << std::endl;

            target = closestUnexplored;
        }

        // nothing to explore
        if(target == Location(-1,-1)) {

            for (const auto &item: state->hillsDestination) {
                target = item.second;
                break;
            }
        }

        //state->bug << "Ant: " << ant->location << " Food: " << bestFood << " distance " << bestFoodDistance << std::endl;
        state->bug << "Timer before Astar: " << state->timer.getTime() << " ms" << std::endl;

        Location nextAstar = AStar::FindPath(state, &ant->location, &target);
        state->bug << "Timer after Astar: " << state->timer.getTime() << " ms" << std::endl;

        Location nextLoc;
        // No path found to destination
        if(nextAstar == Location(0,0)) {
            // Go to opposite direction
            int diffX = ant->location.row - target.row;
            int diffY = ant->location.col - target.col;

            nextLoc = ant->location + Location(diffX/abs(diffX), diffY/abs(diffY));
            std::pair<int,int> correctedLoc = state->correctPos(nextLoc.row, nextLoc.col);
            nextLoc = Location(correctedLoc.first, correctedLoc.second);

            state->bug << "Nod path found to destination, changing destination to " << nextLoc << std::endl;
        }
        else {
            nextLoc = nextAstar;
        }

        if(state->grid[nextLoc.row][nextLoc.col].ant == 0){
            nextLoc = ant->location;
        }

        state->bug << "Next location: " << nextLoc << std::endl;
        state->makeMove(ant->location, nextLoc);


        return NodeStatus::RUNNING;
    }
};