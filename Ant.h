#ifndef ANT_H_
#define ANT_H_

#include "Location.h"

struct Ant
{
  bool hasMeetingPoint = false;
  Location meetingPoint;

  Location location;

  Ant(Location loc);
};

#endif