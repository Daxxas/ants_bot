cmake_minimum_required(VERSION 3.23)
project(ants_bot)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")

#add_definitions(-DDEBUG)

include_directories(src)
include_directories(src/AI)
include_directories(src/AI/Scout)
include_directories(src/AI/Soldier)
include_directories(src/BT)

add_executable(ants_bot
        src/AI/Scout/A_MoveToBestDirection.h
        src/AI/Soldier/A_AttackHill.h
        src/AI/Soldier/A_AttackEnnemy.h
        src/AI/Soldier/A_WalkToHillDestination.h
        src/AI/Soldier/I_NoEnnemyNearby.h
        src/AI/Soldier/I_NoHillsNearby.h
        src/AI/Soldier/I_HasHillDestination.h
        src/AI/AIAnt.cpp
        src/AI/AIAnt.h
        src/BT/BT_CompositeNode.h
        src/BT/BT_Node.h
        src/BT/BT_Selector.h
        src/BT/BT_Sequence.h
        src/Ant.cc
        src/Ant.h
        src/Bot.cc
        src/Bot.h
        src/Bug.h
        src/Location.h
        src/MyBot.cc
        src/Square.h
        src/State.cc
        src/State.h
        src/Timer.h src/AStar.h src/BFS.h src/BFS.cc)
