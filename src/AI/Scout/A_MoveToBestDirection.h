#include "../../bt/BT_Node.h"
#include "../AStar.h"
#include "../Bug.h"

class A_MoveToBestDirection : public BT_Node
{
public:
    virtual NodeStatus run(Ant* ant, State* state) override
    {
        state->bug << "A_MoveToBestDirection" << std::endl;

        Location target = Location(26,35);
        std::vector<Location>* path = AStar::FindPath(state, &ant->location, &target);

        // log path completely
        for (int i = 0; i < path->size(); ++i) {
            state->bug << "path step " << i << " " << (*path)[i] << std::endl;
        }

        //Location nextLocation = Location(abs((*path)[0].row- ant->location.row), abs((*path)[0].col - ant->location.col));

        state->bug << "Next location: " << (*path)[0] << std::endl;

        state->makeMove(ant->location, (*path)[0]);

        return NodeStatus::RUNNING;
    }
};