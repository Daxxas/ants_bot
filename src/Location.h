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

    bool operator!=(const Location &other) const
    {
        return !(*this == other);
    };

    Location operator+(const Location &other) const
    {
        return Location(row + other.row, col + other.col);
    }

    float distance(Location loc, int rows, int cols)
    {
        int d1 = abs(row - loc.row),
            d2 = abs(col - loc.col),
            dr = std::min(d1, rows - d1),
            dc = std::min(d2, cols - d2);

        return sqrt(dr * dr + dc * dc);
    }

    float manhattanDistance(Location loc, int rows, int cols)
    {
        int d1 = abs(row - loc.row),
            d2 = abs(col - loc.col),
            dr = std::min(d1, rows - d1),
            dc = std::min(d2, cols - d2);
        return dr + dc;
    }

    // Overload hash

    friend std::ostream &operator<<(std::ostream &os, const Location &loc)
    {
        os << "(" << loc.row << "," << loc.col << ")";
        return os;
    }
};

#endif // LOCATION_H_
