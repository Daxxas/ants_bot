#include <iostream>

#include "AIAnt.h"
#include "../bt/Selector.h"
#include "../bt/Sequence.h"

// Include all leef
#include "HasMeetingPoint.h"
#include "IsOnMeetingPoint.h"

AIAnt::AIAnt(Ant &_ant) : ant(_ant)
{
  // Soldier Part (left)
  Sequence soldier = Sequence();
  root.addChild(soldier);

  HasMeetingPoint hasMeetingPoint = HasMeetingPoint();
  soldier.addChild(hasMeetingPoint);

  // Soldier -> MeetingPoint
  Selector meetingPoint = Selector();
  soldier.addChild(meetingPoint);

  IsOnMeetingPoint isOnMeetingPoint = IsOnMeetingPoint();
  meetingPoint.addChild(isOnMeetingPoint);

  NodeStatus status = root.run(ant);
  std::cout << "Status: " << status << " for ant " << ant << std::endl;
}

void AIAnt::run()
{
  root.run(ant);
}