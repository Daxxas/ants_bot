#ifndef LOCATION_H_
#define LOCATION_H_

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
};

#endif // LOCATION_H_
