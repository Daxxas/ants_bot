#ifndef ANTS_BOT_ASTAR_H
#define ANTS_BOT_ASTAR_H

#include "State.h"
#include<map>
#include <algorithm>

struct AStarLocation {
public:
    Location location;
    Location parentLocation;
    bool hasParent;
    float g;
    float h;
    float f;

    AStarLocation() {

    }
};

class AStar {
public:
    static std::vector<Location>* FindPath(State* state, Location* start, Location* target);

    static std::vector<Location>* MakePath(State* state, const std::vector<std::vector<AStarLocation>>* map, Location* target);
};


std::vector<Location>* AStar::MakePath(State* state, const std::vector<std::vector<AStarLocation>>* map, Location* target) {
    std::stack<const AStarLocation*> path;
    auto* usablePath = new std::vector<Location>();

    int x = target->row;
    int y = target->col;
    const AStarLocation* current = &((*map)[x][y]);

    state->bug << "Making path" << std::endl;

    bool noParent = false;

    while(!noParent) {
        state->bug << "Adding to path: " << current->location << std::endl;
        path.push(current);
        state->bug << "Current parent: " << current->parentLocation << std::endl;
        current = &((*map)[current->parentLocation.row][current->parentLocation.col]);
        state->bug << "New current: " << current->location << std::endl;
        noParent = !current->hasParent;
    }

    state->bug << "Path size: " << path.size() << std::endl;


    while (!path.empty()) {
        AStarLocation top = *path.top();
        path.pop();
        usablePath->emplace_back(top.location);
    }
    return usablePath;
}


std::vector<Location>* AStar::FindPath(State* state, Location* start, Location* target) {
    state->bug << "Finding path from " << (*start) << " to " << (*target) << std::endl;

    // Initialize open and closed list
    std::vector<AStarLocation> openList;
    bool closedList[state->rows][state->cols];
    memset(closedList, false, sizeof(closedList));
    std::vector<std::vector<AStarLocation>> allMap;

    for (int x = 0; x < state->rows; x++) {
        allMap.push_back(std::vector<AStarLocation>(state->cols));
        for (int y = 0; y < state->cols; y++) {
            allMap[x][y].f = 100000;
            allMap[x][y].g = 100000;
            allMap[x][y].h = 100000;
            allMap[x][y].hasParent = false;
            allMap[x][y].location = Location(x,y);
        }
    }

    allMap[start->row][start->col].location = *start;
    allMap[start->row][start->col].f = 0;
    allMap[start->row][start->col].g = 0;
    allMap[start->row][start->col].h = 0;

    openList.push_back(allMap[start->row][start->col]);

    while(!openList.empty()) {
        // Find smallest f in open list
        float minf = 100000;
        AStarLocation* currentLoc;
        int toRemoveIndex = -1;
        for (int i = 0; i < openList.size(); ++i) {
            AStarLocation* loc = &(openList[i]);
            if (loc->f <= minf) {
                minf = loc->f;
                currentLoc = loc;
                toRemoveIndex = i;
            }
        }
        state->bug << "Current loc: " << currentLoc->location << std::endl;


        openList.erase(openList.begin() + toRemoveIndex);
        closedList[currentLoc->location.row][currentLoc->location.col] = true;

        // generate neighbors of current loc
        for (int xOffset = -1; xOffset <= 1; ++xOffset) {
            for (int yOffset = -1; yOffset <= 1; ++yOffset) {

                if((xOffset != 0 && yOffset != 0) || (xOffset == 0 && yOffset == 0))
                    continue;

                // (a % b + b) % b is a way to get a positive remainder
                int newPosX = currentLoc->location.row + xOffset;
                int newPosY = currentLoc->location.col + yOffset;
                int neighborX = (newPosX % state->rows + state->rows) % state->rows;
                int neighborY = (newPosY % state->rows + state->cols) % state->cols;

                state->bug << "Checking neighbor: " << neighborX << ", " << neighborY << std::endl;

                // Ants can't walk on water
                if (state->grid[neighborX][neighborY].isWater) {
                    continue;
                }

                Location neighborLocation = Location(neighborX, neighborY);
                double neighborG = 0;
                double neighborH = 0;
                double neighborF = 0;

                // Found destination
                if (neighborX == target->row && neighborY == target->col) {
                    allMap[neighborX][neighborY].parentLocation = currentLoc->location;
                    allMap[neighborX][neighborY].hasParent = true;

                    state->bug << "Found path!" << std::endl;
                    return MakePath(state, &allMap, target);
                }
                else {
                    neighborG = currentLoc->g + state->distance(currentLoc->location, neighborLocation);
                    neighborH = state->distance(neighborLocation, *target);
                    neighborF = neighborG + neighborH;
                }

                // Create neighbor
                AStarLocation neighbor;
                neighbor.location = Location(neighborX, neighborY);
                neighbor.parentLocation = currentLoc->location;

                neighbor.hasParent = true;

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
                        state->bug << "Skipping neighbor " << neighbor.location << " because it has a lower f in openlist" << std::endl;
                        break;
                    }
                }

                if (skipNeighbor)
                    continue;

                if (!closedList[neighbor.location.row][neighbor.location.col]) {
                    allMap[neighborX][neighborY] = neighbor;
                    state->bug << "Adding neighbor " << neighbor.location << " to open list" << std::endl;
                    openList.push_back(neighbor);
                }
            }
        }
    }

    state->bug << "No path found!" << std::endl;
    return new std::vector<Location>();
}


#endif //ANTS_BOT_ASTAR_H
