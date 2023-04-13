#include <iostream>

#include "AIAnt.h"
#include "../bt/Selector.h"
#include "../bt/Sequence.h"

// Include all leef
#include "I_HasMeetingPoint.h"
#include "I_IsOnMeetingPoint.h"
#include "A_WalkToMeetingPoint.h"

AIAnt::AIAnt(Ant &_ant) : ant(_ant)
{
  // Soldier
  Sequence soldier = Sequence();
  root.addChild(soldier);

  I_HasMeetingPoint hasMeetingPoint = I_HasMeetingPoint();
  soldier.addChild(hasMeetingPoint);

  // Soldier -> MeetingPoint
  Selector meetingPoint = Selector();
  soldier.addChild(meetingPoint);

  I_IsOnMeetingPoint isOnMeetingPoint = I_IsOnMeetingPoint();
  meetingPoint.addChild(isOnMeetingPoint);

  A_WalkToMeetingPoint walkToMeetingPoint = A_WalkToMeetingPoint();
  meetingPoint.addChild(walkToMeetingPoint);

  // End and run the Behaviour Tree
  NodeStatus status = root.run(ant);
  std::cout << "Status: " << status << " for ant " << ant << std::endl;
}

void AIAnt::run()
{
  root.run(ant);
}