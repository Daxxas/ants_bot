#include <iostream>

#include "AIAnt.h"
#include "../BT/BT_Selector.h"
#include "../BT/BT_Sequence.h"

// Include all leef
#include "./Soldier/I_HasMeetingPoint.h"
#include "./Soldier/I_IsOnMeetingPoint.h"
#include "./Soldier/I_HasEnnemyNearby.h"
#include "./Soldier/I_IsMoreThanEnnemy.h"
#include "./Soldier/A_WalkToMeetingPoint.h"
#include "./Soldier/A_DeleteMeetingPoint.h"
#include "./Soldier/A_WalkToEnnemy.h"

#include "./Scout/I_NoEnnemyNearby.h"
#include "./Scout/I_NoHillsNearby.h"
#include "./Scout/A_PlaceMeetingPoint.h"
#include "./Scout/A_AttackHill.h"
#include "./Scout/A_MoveToBestDirection.h"

AIAnt::AIAnt()
{
    // Soldier
    BT_Sequence *soldier = new BT_Sequence();
    root.addChild(soldier);

    I_HasMeetingPoint *hasMeetingPoint = new I_HasMeetingPoint();
    soldier->addChild(hasMeetingPoint);

    // Soldier/MeetingPoint
    BT_Selector *meetingPoint = new BT_Selector();
    soldier->addChild(meetingPoint);

    I_IsOnMeetingPoint *isOnMeetingPoint = new I_IsOnMeetingPoint();
    meetingPoint->addChild(isOnMeetingPoint);

    A_WalkToMeetingPoint *walkToMeetingPoint = new A_WalkToMeetingPoint();
    meetingPoint->addChild(walkToMeetingPoint);

    // Soldier/Attack
    BT_Sequence *attack = new BT_Sequence();
    soldier->addChild(attack);

    // Soldier/Attack/Keep Status
    BT_Selector *keepStatus = new BT_Selector();
    attack->addChild(keepStatus);

    I_HasEnnemyNearby *hasEnnemyNearby = new I_HasEnnemyNearby();
    keepStatus->addChild(hasEnnemyNearby);

    A_DeleteMeetingPoint *deleteMeetingPoint = new A_DeleteMeetingPoint();
    keepStatus->addChild(deleteMeetingPoint);

    // Soldier/Attack
    I_IsMoreThanEnnemy *isMoreThanEnnemy = new I_IsMoreThanEnnemy();
    attack->addChild(isMoreThanEnnemy);

    A_WalkToEnnemy *walkToEnnemy = new A_WalkToEnnemy();
    attack->addChild(walkToEnnemy);

    // Scout
    BT_Sequence *scout = new BT_Sequence();
    root.addChild(scout);

    // Scout/Ennemy
    BT_Selector *ennemy = new BT_Selector();
    scout->addChild(ennemy);

    I_NoEnnemyNearby *noEnnemyNearby = new I_NoEnnemyNearby();
    ennemy->addChild(noEnnemyNearby);

    A_PlaceMeetingPoint *placeMeetingPoint = new A_PlaceMeetingPoint();
    ennemy->addChild(placeMeetingPoint);

    // Scout/Gaze
    BT_Selector *gaze = new BT_Selector();
    scout->addChild(gaze);

    I_NoHillsNearby *noHillsNearby = new I_NoHillsNearby();
    gaze->addChild(noHillsNearby);

    A_AttackHill *attackHill = new A_AttackHill();
    gaze->addChild(attackHill);

    // Scout
    A_MoveToBestDirection *moveToBestDirection = new A_MoveToBestDirection();
    scout->addChild(moveToBestDirection);

    // End and run the Behaviour Tree
    // NodeStatus status = root.run(ant, state);
    // std::cout << "Status: " << status << " for ant " << ant << std::endl;
}

AIAnt::~AIAnt()
{
    // TODO : Faire le delete
    // delete pointeur;
}

void AIAnt::run(Ant *ant, State *state)
{
    state->bug << "Run AI ant " << ant << std::endl;

    root.run(ant, state);
}