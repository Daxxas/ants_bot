#include "../../BT/BT_Node.h"
#include "../../AStar.h"

class A_MoveToBestDirection : public BT_Node
{
public:
    virtual NodeStatus run(Ant &ant, State &state) override
    {
        Location target = Location(0, 0);
        std::vector<Location> path = AStar::FindPath(state, ant.location, target);

        return NodeStatus::RUNNING;
    }
};