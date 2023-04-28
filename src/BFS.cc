#include "BFS.h"
#include "State.h"

Location BFS::GetBFSPosition(State *state, Location *start, int maxDistance, bool (*condition)(Square)) {
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

        if(condition(state->grid[current.row][current.col])) {
            state->bug << "BFS found value " << bfsMap[current.row][current.col] << std::endl;

            return Location(current.row,current.col);
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
    return Location(-1,-1);
}