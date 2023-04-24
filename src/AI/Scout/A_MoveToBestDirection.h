#include "../../bt/BT_Node.h"
#include "../AStar.h"
#include "../Bug.h"

class A_MoveToBestDirection : public BT_Node
{
public:
    virtual NodeStatus run(Ant* ant, State* state) override
    {
        state->bug << "Move to best direction" << std::endl;

        //Location target = Location(0,0);
        //std::vector<Location> path = AStar::FindPath(state, ant.location, target);

        //Location nextLocation = Location(path[0].row - ant.location.row, path[0].col - ant.location.col);

        //state.bug << "Next location: " << nextLocation << std::endl;

        //state.makeMove(ant.location, state.turn % 4);

        return NodeStatus::RUNNING;
    }
};