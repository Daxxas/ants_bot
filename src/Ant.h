#ifndef ANT_H_
#define ANT_H_

#include <iostream>
#include <stdio.h>
#include <string>

#include "Location.h"

struct Ant
{
  bool hasMeetingPoint = false;
  Location meetingPoint;

  Location location;

  Ant(Location loc);
};

std::ostream &operator<<(std::ostream &os, const Ant &state);

#endif