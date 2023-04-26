#include "../../BT/BT_Node.h"

#include <algorithm>
#include "../../AStar.h"

struct CloseAnd
{
  Ant *ant;
  float distance;
};

class A_AttackEnnemy : public BT_Node
{
public:
  virtual NodeStatus run(Ant *ant, State *state) override
  {
    state->bug << "A_PlaceMeetingPoint" << std::endl;

    int sizeOfSquare = (int)floor(SQUARE_TO_CHECK / 2);

    std::vector<std::pair<int, int>> possiblePositions;
    std::vector<float> distance;

    for (int i = -sizeOfSquare; i < sizeOfSquare + 1; i++)
    {
      for (int j = -sizeOfSquare; j < sizeOfSquare + 1; j++)
      {
        state->bug << "Checking " << ant->location.row + i << " " << ant->location.col + j << std::endl;
        int newPosX = ant->location.row + i;
        int newPosY = ant->location.col + j;
        auto pos = state->correctPos(newPosX, newPosY);

        if (state->grid[pos.first][pos.second].ant > 0)
        {
          possiblePositions.push_back(pos);
          distance.push_back(state->distance(ant->location, Location(pos.first, pos.second)));
        }
      }
    }

    std::pair<int, int> bestPos = possiblePositions[0];
    float bestDistance = distance[0];

    for (int i = 0; i < possiblePositions.size(); i++)
    {
      if (distance[i] < bestDistance)
      {
        bestPos = possiblePositions[i];
        bestDistance = distance[i];
      }
    }

    Location loc = Location(bestPos.first, bestPos.second);

    auto path = AStar::FindPath(state, &ant->location, &loc);

    Location nextLoc;
    // No path found to destination, stay in place
    if (path->size() <= 0)
    {
      nextLoc = ant->location;
    }
    else
    {
      nextLoc = (*path)[0];
    }

    state->makeMove(ant->location, nextLoc);

    return NodeStatus::RUNNING;
  }
};