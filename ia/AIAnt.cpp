#include "AIAnt.h"
#include "../bt/Selector.h"
#include "../bt/Sequence.h"

// Include all leef
#include "HasMeetingPoint.h"

AIAnt::AIAnt(Ant &_ant) : ant(_ant)
{
}

void AIAnt::run()
{
  Selector root = Selector();

  // Soldier Part (left)
  Sequence soldier = Sequence();
  root.addChild(soldier);

  HasMeetingPoint hasMeetingPoint = HasMeetingPoint();
  soldier.addChild(hasMeetingPoint);
}