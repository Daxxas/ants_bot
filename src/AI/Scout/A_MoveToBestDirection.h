#include "../../bt/BT_Node.h"
#include "../AStar.h"
#include "../Bug.h"
#include "BFS.h"

class A_MoveToBestDirection : public BT_Node
{
public:
    virtual NodeStatus run(Ant* ant, State* state) override
    {
        state->bug << "A_MoveToBestDirection" << std::endl;

        auto bfs = BFS::GenerateBFS(state, &ant->location);

        Location target = Location(0,0);

        Location bestFood = Location(0,0);
        int bestFoodDistance = 1000000;
        for(auto food: state->food) {
            if(bestFoodDistance > (*bfs)[food.row][food.col] && (*bfs)[food.row][food.col] >= 0) {
                bestFood = food;
                bestFoodDistance = (*bfs)[food.row][food.col];
            }
        }
        target = bestFood;

        state->bug << "Ant: " << ant->location << " Food: " << bestFood << " distance " << bestFoodDistance << std::endl;

        std::vector<Location>* path = AStar::FindPath(state, &ant->location, &target);

        // log path completely
        for (int i = 0; i < path->size(); ++i) {
            state->bug << "path step " << i << " " << (*path)[i] << std::endl;
        }
        state->bug << "Next location: " << (*path)[0] << std::endl;
        state->makeMove(ant->location, (*path)[0]);

        return NodeStatus::RUNNING;
    }
};