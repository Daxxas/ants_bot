#ifndef ANT_H_
#define ANT_H_

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

#include "Location.h"

struct Ant
{
  // Hill Destination: Prio destination for the next turn to focus hills
  bool hasHillDestination = false;
  Location hillDestination;
  Location foodDestination = Location(-1,-1);

  std::vector<std::vector<int>> *bfsMap;

  Location location;

  Ant(Location loc);

  void setHillDestination(int row, int col);
};

std::ostream &operator<<(std::ostream &os, const Ant &state);

#endif