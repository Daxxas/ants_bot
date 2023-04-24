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
    static std::vector<std::vector<int>>* GenerateBFS(State* state, Location* start);
};

std::vector<std::vector<int>>* BFS::GenerateBFS(State *state, Location *start) {
    state->bug << "Generating BFS" << std::endl;

    std::vector<Location> toVisit;
    auto* bfsMap = new std::vector<std::vector<int>>(state->rows, std::vector<int>(state->cols, -1));

    toVisit.push_back(*start);
    (*bfsMap)[start->row][start->col] = 0;

    int distance = 0;

    while(!toVisit.empty()) {
        Location current = toVisit.front();
        toVisit.erase(toVisit.begin());

        (*bfsMap)[current.row][current.col] = distance;

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


            auto duplicate = std::find(toVisit.begin(), toVisit.end(), next);

            if(duplicate != toVisit.end()) {
                if((*bfsMap)[next.row][next.col] > distance) {
                    (*bfsMap)[next.row][next.col] = distance;
                }
                continue;
            }

            if ((*bfsMap)[next.row][next.col] >= 0) { // already visited
                continue;
            }

            if (state->grid[next.row][next.col].isWater) {
                continue;
            }

            toVisit.push_back(next);
        }
        distance++;

        // no need to go further than the number  of turns
        if(distance > state->turns)
            break;
    }

    return bfsMap;
}


#endif //ANTS_BOT_BFS_H
