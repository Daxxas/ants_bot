#ifndef ANTS_BOT_ASTAR_H
#define ANTS_BOT_ASTAR_H

#include "State.h"
#include<map>
#include <algorithm>

struct AStarLocation {
public:
    Location location;
    AStarLocation* parentLocation;
    float g;
    float h;
    float f;

    AStarLocation() {

    }
};

class AStar {
public:
    static std::vector<Location> FindPath(State &state, Location &start, Location &target);

    static std::vector<Location> MakePath(const std::vector<std::vector<AStarLocation>>& map, Location &target);
};


std::vector<Location> AStar::MakePath(const std::vector<std::vector<AStarLocation>>& map, Location &target) {
    std::stack<AStarLocation> path;
    std::vector<Location> usablePath;

    int x = target.row;
    int y = target.col;

    while(!(map[x][y].parentLocation->location.row == x && map[x][y].parentLocation->location.col == y))
    {
        path.push(map[x][y]);
        int tempX = map[x][y].parentLocation->location.row;
        int tempY = map[x][y].parentLocation->location.col;
        x = tempX;
        y = tempY;
    }

    path.push(map[x][y]);

    while (!path.empty()) {
        AStarLocation top = path.top();
        path.pop();
        usablePath.emplace_back(top.location);
    }
    return usablePath;
}


std::vector<Location> AStar::FindPath(State &state, Location &start, Location &target) {
    std::vector<AStarLocation> openList;
    bool closedList[state.rows][state.cols];
    memset(closedList, false, sizeof(closedList));
    std::vector<std::vector<AStarLocation>> allMap;

    for (int x = 0; x < state.rows; x++) {
        for (int y = 0; y < state.cols; y++) {
            allMap[x][y].f = 100000;
            allMap[x][y].g = 100000;
            allMap[x][y].h = 100000;
            allMap[x][y].location = Location(x,y);
        }
    }

    allMap[start.row][start.col].location = start;
    allMap[start.row][start.col].f = 0;
    allMap[start.row][start.col].g = 0;
    allMap[start.row][start.col].h = 0;

    openList.push_back(allMap[start.row][start.col]);

    while(!openList.empty()) {

        // Find smallest f in open list
        float minf = 100000;
        AStarLocation currentLoc;
        int toRemoveIndex = -1;
        for (int i = 0; i < openList.size(); ++i) {
            AStarLocation loc = openList[i];
            if (loc.f < minf) {
                minf = loc.f;
                currentLoc = loc;
                toRemoveIndex = i;
            }
        }

        openList.erase(openList.begin() + toRemoveIndex);

        // generate neighbors of current loc
        for (int xOffset = -1; xOffset <= 1; ++xOffset) {
            for (int yOffset = -1; yOffset <= 1; ++yOffset) {
                int neighborX = (currentLoc.location.row + xOffset + state.rows) % state.rows;
                int neighborY = (currentLoc.location.col + yOffset + state.cols) % state.cols;

                // Ants can't walk on water
                if (!state.grid[neighborX][neighborY].isWater) {
                    continue;
                }

                Location neighborLocation = Location(neighborX, neighborY);
                double neighborG = 0;
                double neighborH = 0;
                double neighborF = 0;

                // Found destination
                if (neighborX == target.row && neighborY == target.col) {
                    allMap[neighborX][neighborY].parentLocation = &currentLoc;
                    return MakePath(allMap, target); // TODO : makepath function
                } else {
                    neighborG = currentLoc.g + state.distance(currentLoc.location, neighborLocation);
                    neighborH = state.distance(neighborLocation, target);
                    neighborF = neighborG + neighborH;
                }

                // Create neighbor
                AStarLocation neighbor;
                neighbor.location = Location(neighborX, neighborY);
                neighbor.parentLocation = &currentLoc;
                neighbor.f = neighborF;
                neighbor.g = neighborG;
                neighbor.h = neighborH;


                // Add neighbor if matches conditions
                bool skipNeighbor = false;

                for (auto it = openList.begin(); it != openList.end(); it = next(it)) {
                    AStarLocation loc = *it;
                    if (loc.location.row == neighbor.location.row && loc.location.col == neighbor.location.col
                        && loc.f < neighbor.f) {
                        skipNeighbor = true;
                        break;
                    }
                }

                if (skipNeighbor)
                    continue;

                if (!closedList[neighbor.location.row][neighbor.location.col]) {
                    allMap[neighborX][neighborY] = neighbor;
                    openList.push_back(neighbor);
                }
            }
        }

        closedList[currentLoc.location.row][currentLoc.location.col] = true;
    }
}


#endif //ANTS_BOT_ASTAR_H
