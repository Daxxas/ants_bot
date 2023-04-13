

#include "Ant.h"

Ant::Ant(Location loc)
{
  location = loc;
}

std::ostream &operator<<(std::ostream &os, const Ant &ant)
{
  os << ant.location;

  return os;
};