#ifndef LOCATION_H_
#define LOCATION_H_

#include <cmath>

/*
    struct for representing locations in the grid.
*/
struct Location
{
    int row, col;

    Location()
    {
        row = col = 0;
    };

    Location(int r, int c)
    {
        row = r;
        col = c;
    };

    bool operator==(const Location &other) const
    {
        return row == other.row && col == other.col;
    };

    float distance(Location loc)
    {
        return sqrt(pow(row - loc.row, 2) + pow(col - loc.col, 2));
    }

    float manhattanDistance(Location loc)
    {
        return abs(loc.row - row) + abs(loc.col - col);
    }

    friend std::ostream& operator<<(std::ostream& os, const Location& loc)
    {
        os << "(" << loc.row << "," << loc.col << ")";
        return os;
    }
};

#endif // LOCATION_H_
