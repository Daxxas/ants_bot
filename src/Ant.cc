

#include "Ant.h"

Ant::Ant(Location loc)
{
  location = loc;
}

void Ant::setHillDestination(int row, int col)
{
  hasHillDestination = true;
  hillDestination.row = row;
  hillDestination.col = col;
}

std::ostream &operator<<(std::ostream &os, const Ant &ant)
{
  os << ant.location;

  return os;
};