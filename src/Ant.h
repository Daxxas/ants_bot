#ifndef ANT_H_
#define ANT_H_

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

#include "Location.h"

struct Ant
{
  bool hasHillDestination = false;
  Location hillDestination;

  Location location;

  Ant(Location loc);

  void setHillDestination(int row, int col);
};

std::ostream &operator<<(std::ostream &os, const Ant &state);

#endif