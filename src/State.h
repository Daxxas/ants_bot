#ifndef STATE_H_
#define STATE_H_

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <stdint.h>

#include "Timer.h"
#include "Bug.h"
#include "Square.h"
#include "Location.h"
#include "Ant.h"
#include "Location.h"
#include "BFS.h"

/*
    constants
*/
const int TDIRECTIONS = 4;
const char CDIRECTIONS[4] = {'N', 'E', 'S', 'W'};
const int DIRECTIONS[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; //{N, E, S, W}

/*
    struct to store current state information
*/
struct State
{
    /*
        Variables
    */
    int rows, cols,
        turn, turns,
        noPlayers;
    double attackradius, spawnradius, viewradius;
    double loadtime, turntime;
    std::vector<double> scores;
    bool gameover;
    int64_t seed;

    std::vector<std::vector<Square>> grid;
    std::vector<Location> enemyAnts, myHills, enemyHills, food;
    std::vector<Ant> myAnts;
    std::map<std::string, Location> hillsDestination;

    Timer timer;
    Bug bug;

    /*
        Functions
    */
    State();
    ~State();

    void setup();
    void reset();

    void makeMove(const Location &loc, int direction);
    void makeMove(const Location &loc, const Location &nextLoc);

    std::pair<int, int> correctPos(int row, int col);
    double distance(const Location &loc1, const Location &loc2);
    Location getLocation(const Location &startLoc, int direction);

    void saveHillsDestination();
    void applyHillsDestination();
    void updateFoodDestination();

    void updateVisionInformation();
};

std::ostream &operator<<(std::ostream &os, const State &state);
std::istream &operator>>(std::istream &is, State &state);

#endif // STATE_H_
