

#include "Ant.h"

Ant::Ant(Location loc)
{
  location = loc;
}

void Ant::setMeetingPoint(int row, int col)
{
  hasMeetingPoint = true;
  meetingPoint.row = row;
  meetingPoint.col = col;
}

std::ostream &operator<<(std::ostream &os, const Ant &ant)
{
  os << ant.location;

  return os;
};