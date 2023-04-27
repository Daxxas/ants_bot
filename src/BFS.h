//
// Created by daxxas on 24/04/2023.
//
#pragma once

#ifndef ANTS_BOT_BFS_H
#define ANTS_BOT_BFS_H

#include <algorithm>
#include "Location.h"
#include "State.h"

class BFS {
public:
    static int GetBFSDistance(State* state, Location* start, int maxDistance, bool (*function)(Square));
};

int BFS::GetBFSDistance(State *state, Location *start, int maxDistance, bool (*function)(Square)) {
    state->bug << "Generating BFS" << std::endl;

    std::queue<Location> toVisit;
    auto bfsMap = std::vector<std::vector<int>>(state->rows, std::vector<int>(state->cols, -1));

    toVisit.push(*start);
    bfsMap[start->row][start->col] = 0;

    while(!toVisit.empty()) {
        Location current = toVisit.front();
        toVisit.pop();

        if(bfsMap[current.row][current.col] > maxDistance) {
            continue;
        }

        if(function(state->grid[current.row][current.col])) {
            state->bug << "BFS found value " << bfsMap[current.row][current.col] << std::endl;

            return bfsMap[current.row][current.col];
        }

        for (int i = 0; i < 4; i++) {
            Location next = current;
            next.row = next.row + DIRECTIONS[i][0];
            next.col = next.col + DIRECTIONS[i][1];

            next.row = next.row % state->rows;
            if (next.row < 0) {
                next.row += state->rows;
            }

            next.col = next.col % state->cols;
            if (next.col < 0) {
                next.col += state->cols;
            }

            if (bfsMap[next.row][next.col] >= 0) { // already visited
                continue;
            }

            if (state->grid[next.row][next.col].isWater) {
                continue;
            }

            bfsMap[next.row][next.col] = bfsMap[current.row][current.col] + 1;
            toVisit.push(next);
        }
    }

    state->bug << "BFS can't reach target" << std::endl;
    return -1;
}


#endif //ANTS_BOT_BFS_H
