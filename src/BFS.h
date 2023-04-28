//
// Created by daxxas on 24/04/2023.
//
#pragma once

#ifndef ANTS_BOT_BFS_H
#define ANTS_BOT_BFS_H

#include <algorithm>
#include "Square.h"

struct State;
struct Location;

class BFS {
public:
    static Location GetBFSPosition(State* state, Location* start, int maxDistance, bool (*condition)(Square));
};


#endif //ANTS_BOT_BFS_H
