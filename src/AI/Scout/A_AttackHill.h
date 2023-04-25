#include "../../BT/BT_Node.h"

class A_AttackHill : public BT_Node
{
public:
  virtual NodeStatus run(Ant *ant, State *state) override
  {
    state->bug << "A_AttackHill" << std::endl;

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

        if (state->grid[pos.first][pos.second].isHill && state->grid[pos.first][pos.second].hillPlayer > 0)
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

    ant->setMeetingPoint(bestPos.first, bestPos.second);

    std::vector<CloseAnd> closeAnts;

    // Place meeting point for close ants
    for (int i = 0; i < state->myAnts.size(); i++)
    {
      if (state->distance(state->myAnts[i].location, Location(bestPos.first, bestPos.second)) < 40)
      {
        CloseAnd closeAnt;
        closeAnt.ant = &state->myAnts[i];
        closeAnt.distance = state->distance(state->myAnts[i].location, Location(bestPos.first, bestPos.second));
        closeAnts.push_back(closeAnt);
      }
    }

    state->bug << "Close ants: " << closeAnts.size() << std::endl;

    std::sort(closeAnts.begin(), closeAnts.end(), [](CloseAnd a, CloseAnd b)
              { return a.distance < b.distance; });

    for (int i = 0; i < std::min((int)closeAnts.size(), SEND_X_ANT); i++)
    {
      state->bug << "Sending ant " << &ant << " to " << bestPos.first << " " << bestPos.second << std::endl;
      closeAnts[i].ant->setMeetingPoint(bestPos.first, bestPos.second);
    }

    return NodeStatus::SUCCESS;
  }
};