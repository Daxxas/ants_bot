#ifndef ANTS_BOT_ASTAR_H
#define ANTS_BOT_ASTAR_H

#include "State.h"
#include <map>
#include <algorithm>
#include <cstring>

struct AStarLocation
{
public:
    Location location;
    Location parentLocation;
    bool hasParent;
    float g;
    float h;
    float f;

    AStarLocation()
    {
    }
};

class AStar
{
public:
    static Location FindPath(State *state, Location *start, Location *target);

    static Location MakePath(State *state, const std::vector<std::vector<AStarLocation>> *map, Location *target);
};

Location AStar::MakePath(State *state, const std::vector<std::vector<AStarLocation>> *map, Location *target)
{
    state->bug << "Making path " << std::endl;

    int x = target->row;
    int y = target->col;
    AStarLocation current;
    AStarLocation nextLocation = (*map)[x][y];


    bool noParent = false;

    while (nextLocation.hasParent)
    {
        current = nextLocation;
        nextLocation = (*map)[current.parentLocation.row][current.parentLocation.col];
    }
    state->bug << " astar returning " << current.location << std::endl;

    return current.location;
}

Location AStar::FindPath(State *state, Location *start, Location *target)
{
    if (*start == *target || state->grid[target->row][target->col].isWater) // || state->grid[target->row][target->col].ant == 0)
    {
        state->bug << "start is target " << std::endl;
        return Location(0,0);
    }

    state->bug << "Finding path from " << (*start) << " to " << (*target) << std::endl;
    // Initialize open and closed list
    std::vector<AStarLocation> openList;
    bool closedList[state->rows][state->cols];
    memset(closedList, false, sizeof(closedList));
    std::vector<std::vector<AStarLocation>> allMap;

    for (int x = 0; x < state->rows; x++)
    {
        allMap.emplace_back(state->cols);
        for (int y = 0; y < state->cols; y++)
        {
            allMap[x][y].f = 100000;
            allMap[x][y].g = 100000;
            allMap[x][y].h = 100000;
            allMap[x][y].hasParent = false;
            allMap[x][y].location = Location(x, y);
        }
    }

    allMap[start->row][start->col].location = *start;
    allMap[start->row][start->col].f = 0;
    allMap[start->row][start->col].g = 0;
    allMap[start->row][start->col].h = 0;

    openList.push_back(allMap[start->row][start->col]);

    while (!openList.empty())
    {
        // Find smallest f in open list
        float minf = 100000;
        AStarLocation currentLoc;
        int toRemoveIndex = -1;
        for (int i = 0; i < openList.size(); ++i)
        {
            AStarLocation loc = (openList[i]);
            if (loc.f <= minf)
            {
                minf = loc.f;
                currentLoc = loc;
                toRemoveIndex = i;
            }
        }

        openList.erase(openList.begin() + toRemoveIndex);
        closedList[currentLoc.location.row][currentLoc.location.col] = true;

        // generate neighbors of current loc
        for (int xOffset = -1; xOffset <= 1; ++xOffset)
        {
            for (int yOffset = -1; yOffset <= 1; ++yOffset)
            {

                // Move only in 4 directions
                if ((xOffset != 0 && yOffset != 0) || (xOffset == 0 && yOffset == 0))
                    continue;

                int newPosX = currentLoc.location.row + xOffset;
                int newPosY = currentLoc.location.col + yOffset;

                auto neighborPos = state->correctPos(newPosX, newPosY);

                // Ants can't walk on water
                if (state->grid[neighborPos.first][neighborPos.second].isWater)
                {
                    continue;
                }

                // Avoid moving on player hill
                if (state->grid[neighborPos.first][neighborPos.second].hillPlayer == 0)
                {
                    continue;
                }

                // Avoid moving on other ants
                //if (state->grid[neighborPos.first][neighborPos.second].ant == 0)
                //{
                //    continue;
                //}

                Location neighborLocation = Location(neighborPos.first, neighborPos.second);
                double neighborG = 0;
                double neighborH = 0;
                double neighborF = 0;

                // Found destination
                if (neighborPos.first == target->row && neighborPos.second == target->col)
                {
                    allMap[neighborPos.first][neighborPos.second].parentLocation = currentLoc.location;
                    allMap[neighborPos.first][neighborPos.second].hasParent = true;

                    state->bug << "Astar found path :)" << std::endl;

                    return MakePath(state, &allMap, target);
                }
                else
                {
                    neighborG = currentLoc.g + currentLoc.location.manhattanDistance(neighborLocation, state->rows, state->cols);
                    neighborH = neighborLocation.manhattanDistance(*target, state->rows, state->cols);
                    neighborF = neighborG + neighborH;
                }

                // Create neighbor
                AStarLocation neighbor;
                neighbor.location = neighborLocation;
                neighbor.parentLocation = currentLoc.location;
                neighbor.hasParent = true;
                neighbor.f = neighborF;
                neighbor.g = neighborG;
                neighbor.h = neighborH;

                // Add neighbor if matches conditions
                bool skipNeighbor = false;

                for (auto it = openList.begin(); it != openList.end(); it = next(it))
                {
                    AStarLocation loc = *it;
                    if (loc.location.row == neighbor.location.row && loc.location.col == neighbor.location.col && loc.f < neighbor.f)
                    {
                        skipNeighbor = true;
                        break;
                    }
                }

                if (skipNeighbor)
                    continue;

                if (!closedList[neighbor.location.row][neighbor.location.col])
                {
                    closedList[neighbor.location.row][neighbor.location.col] = true;
                    allMap[neighborPos.first][neighborPos.second] = neighbor;
                    openList.push_back(neighbor);
                }
            }
        }
    }

    state->bug << "No path found!" << std::endl;
    return Location(0,0);
}

#endif // ANTS_BOT_ASTAR_H
