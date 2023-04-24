# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jules/Ants/ants_bot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jules/Ants/ants_bot

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/local/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/jules/Ants/ants_bot/CMakeFiles /home/jules/Ants/ants_bot//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/jules/Ants/ants_bot/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named ants_bot

# Build rule for target.
ants_bot: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 ants_bot
.PHONY : ants_bot

# fast build rule for target.
ants_bot/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ants_bot.dir/build.make CMakeFiles/ants_bot.dir/build
.PHONY : ants_bot/fast

src/AI/AIAnt.o: src/AI/AIAnt.cpp.o
.PHONY : src/AI/AIAnt.o

# target to build an object file
src/AI/AIAnt.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ants_bot.dir/build.make CMakeFiles/ants_bot.dir/src/AI/AIAnt.cpp.o
.PHONY : src/AI/AIAnt.cpp.o

src/AI/AIAnt.i: src/AI/AIAnt.cpp.i
.PHONY : src/AI/AIAnt.i

# target to preprocess a source file
src/AI/AIAnt.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ants_bot.dir/build.make CMakeFiles/ants_bot.dir/src/AI/AIAnt.cpp.i
.PHONY : src/AI/AIAnt.cpp.i

src/AI/AIAnt.s: src/AI/AIAnt.cpp.s
.PHONY : src/AI/AIAnt.s

# target to generate assembly for a file
src/AI/AIAnt.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ants_bot.dir/build.make CMakeFiles/ants_bot.dir/src/AI/AIAnt.cpp.s
.PHONY : src/AI/AIAnt.cpp.s

src/Ant.o: src/Ant.cc.o
.PHONY : src/Ant.o

# target to build an object file
src/Ant.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ants_bot.dir/build.make CMakeFiles/ants_bot.dir/src/Ant.cc.o
.PHONY : src/Ant.cc.o

src/Ant.i: src/Ant.cc.i
.PHONY : src/Ant.i

# target to preprocess a source file
src/Ant.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ants_bot.dir/build.make CMakeFiles/ants_bot.dir/src/Ant.cc.i
.PHONY : src/Ant.cc.i

src/Ant.s: src/Ant.cc.s
.PHONY : src/Ant.s

# target to generate assembly for a file
src/Ant.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ants_bot.dir/build.make CMakeFiles/ants_bot.dir/src/Ant.cc.s
.PHONY : src/Ant.cc.s

src/Bot.o: src/Bot.cc.o
.PHONY : src/Bot.o

# target to build an object file
src/Bot.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ants_bot.dir/build.make CMakeFiles/ants_bot.dir/src/Bot.cc.o
.PHONY : src/Bot.cc.o

src/Bot.i: src/Bot.cc.i
.PHONY : src/Bot.i

# target to preprocess a source file
src/Bot.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ants_bot.dir/build.make CMakeFiles/ants_bot.dir/src/Bot.cc.i
.PHONY : src/Bot.cc.i

src/Bot.s: src/Bot.cc.s
.PHONY : src/Bot.s

# target to generate assembly for a file
src/Bot.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ants_bot.dir/build.make CMakeFiles/ants_bot.dir/src/Bot.cc.s
.PHONY : src/Bot.cc.s

src/MyBot.o: src/MyBot.cc.o
.PHONY : src/MyBot.o

# target to build an object file
src/MyBot.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ants_bot.dir/build.make CMakeFiles/ants_bot.dir/src/MyBot.cc.o
.PHONY : src/MyBot.cc.o

src/MyBot.i: src/MyBot.cc.i
.PHONY : src/MyBot.i

# target to preprocess a source file
src/MyBot.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ants_bot.dir/build.make CMakeFiles/ants_bot.dir/src/MyBot.cc.i
.PHONY : src/MyBot.cc.i

src/MyBot.s: src/MyBot.cc.s
.PHONY : src/MyBot.s

# target to generate assembly for a file
src/MyBot.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ants_bot.dir/build.make CMakeFiles/ants_bot.dir/src/MyBot.cc.s
.PHONY : src/MyBot.cc.s

src/State.o: src/State.cc.o
.PHONY : src/State.o

# target to build an object file
src/State.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ants_bot.dir/build.make CMakeFiles/ants_bot.dir/src/State.cc.o
.PHONY : src/State.cc.o

src/State.i: src/State.cc.i
.PHONY : src/State.i

# target to preprocess a source file
src/State.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ants_bot.dir/build.make CMakeFiles/ants_bot.dir/src/State.cc.i
.PHONY : src/State.cc.i

src/State.s: src/State.cc.s
.PHONY : src/State.s

# target to generate assembly for a file
src/State.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ants_bot.dir/build.make CMakeFiles/ants_bot.dir/src/State.cc.s
.PHONY : src/State.cc.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... ants_bot"
	@echo "... src/AI/AIAnt.o"
	@echo "... src/AI/AIAnt.i"
	@echo "... src/AI/AIAnt.s"
	@echo "... src/Ant.o"
	@echo "... src/Ant.i"
	@echo "... src/Ant.s"
	@echo "... src/Bot.o"
	@echo "... src/Bot.i"
	@echo "... src/Bot.s"
	@echo "... src/MyBot.o"
	@echo "... src/MyBot.i"
	@echo "... src/MyBot.s"
	@echo "... src/State.o"
	@echo "... src/State.i"
	@echo "... src/State.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

