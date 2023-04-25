#include "../../BT/BT_Node.h"
#include "../AStar.h"

class A_WalkToMeetingPoint : public BT_Node
{
public:
    virtual NodeStatus run(Ant *ant, State *state) override
    {
        state->bug << "A_WalkToMeetingPoint" << std::endl;

        auto path = AStar::FindPath(state, &ant->location, &ant->meetingPoint);

        Location nextLoc;
        // No path found to destination, stay in place
        if(path->size() <= 0) {
            nextLoc = ant->location;
        }
        else {
            nextLoc = (*path)[0];
        }

        state->makeMove(ant->location, nextLoc);

        // TODO: Implement this method.
        return NodeStatus::RUNNING;
    }
};