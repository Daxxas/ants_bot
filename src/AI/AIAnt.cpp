#include <iostream>

#include "AIAnt.h"
#include "../bt/BT_Selector.h"
#include "../bt/BT_Sequence.h"

// Include all leef
#include "./Soldier/I_HasMeetingPoint.h"
#include "./Soldier/I_IsOnMeetingPoint.h"
#include "./Soldier/I_HasEnnemyNearby.h"
#include "./Soldier/I_IsMoreThanEnnemy.h"
#include "./Soldier/A_WalkToMeetingPoint.h"
#include "./Soldier/A_DeleteMeetingPoint.h"
#include "./Soldier/A_WalkToEnnemy.h"

#include "./Scout/I_NoEnnemyNearby.h"
#include "./Scout/I_NoGazeNearby.h"
#include "./Scout/A_PlaceMeetingPoint.h"
#include "./Scout/A_AttackGaze.h"
#include "./Scout/A_MoveToBestDirection.h"

AIAnt::AIAnt(Ant &_ant, State &_state) : ant(_ant), state(_state)
{
  // Soldier
  BT_Sequence soldier = BT_Sequence();
  root.addChild(&soldier);

  I_HasMeetingPoint hasMeetingPoint = I_HasMeetingPoint();
  soldier.addChild(&hasMeetingPoint);

  // Soldier/MeetingPoint
  BT_Selector meetingPoint = BT_Selector();
  soldier.addChild(&meetingPoint);

  I_IsOnMeetingPoint isOnMeetingPoint = I_IsOnMeetingPoint();
  meetingPoint.addChild(&isOnMeetingPoint);

  A_WalkToMeetingPoint walkToMeetingPoint = A_WalkToMeetingPoint();
  meetingPoint.addChild(&walkToMeetingPoint);

  // Soldier/Attack
  BT_Sequence attack = BT_Sequence();
  soldier.addChild(&attack);

  // Soldier/Attack/Keep Status
  BT_Selector keepStatus = BT_Selector();
  attack.addChild(&keepStatus);

  I_HasEnnemyNearby hasEnnemyNearby = I_HasEnnemyNearby();
  keepStatus.addChild(&hasEnnemyNearby);

  A_DeleteMeetingPoint deleteMeetingPoint = A_DeleteMeetingPoint();
  keepStatus.addChild(&deleteMeetingPoint);

  // Soldier/Attack
  I_IsMoreThanEnnemy isMoreThanEnnemy = I_IsMoreThanEnnemy();
  attack.addChild(&isMoreThanEnnemy);

  A_WalkToEnnemy walkToEnnemy = A_WalkToEnnemy();
  attack.addChild(&walkToEnnemy);

  // Scout
  BT_Sequence scout = BT_Sequence();
  root.addChild(&scout);

  // Scout/Ennemy
  BT_Selector ennemy = BT_Selector();
  scout.addChild(&ennemy);

  I_NoEnnemyNearby noEnnemyNearby = I_NoEnnemyNearby();
  ennemy.addChild(&noEnnemyNearby);

  A_PlaceMeetingPoint placeMeetingPoint = A_PlaceMeetingPoint();
  ennemy.addChild(&placeMeetingPoint);

  // Scout/Gaze
  BT_Selector gaze = BT_Selector();
  scout.addChild(&gaze);

  I_NoGazeNearby noGazeNearby = I_NoGazeNearby();
  gaze.addChild(&noGazeNearby);

  A_AttackGaze attackGaze = A_AttackGaze();
  gaze.addChild(&attackGaze);

  // Scout
  A_MoveToBestDirection moveToBestDirection = A_MoveToBestDirection();
  scout.addChild(&moveToBestDirection);

  // End and run the Behaviour Tree
  NodeStatus status = root.run(ant, state);
  std::cout << "Status: " << status << " for ant " << ant << std::endl;
}

void AIAnt::run()
{
  root.run(ant, state);
}