# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.21.3_1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.21.3_1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lewis/Documents/GitHub/tic-tac-toe/Frame04

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lewis/Documents/GitHub/tic-tac-toe/Frame04/build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/main.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.cpp.o: ../main.cpp
CMakeFiles/main.dir/main.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lewis/Documents/GitHub/tic-tac-toe/Frame04/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/main.cpp.o -MF CMakeFiles/main.dir/main.cpp.o.d -o CMakeFiles/main.dir/main.cpp.o -c /Users/lewis/Documents/GitHub/tic-tac-toe/Frame04/main.cpp

CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lewis/Documents/GitHub/tic-tac-toe/Frame04/main.cpp > CMakeFiles/main.dir/main.cpp.i

CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lewis/Documents/GitHub/tic-tac-toe/Frame04/main.cpp -o CMakeFiles/main.dir/main.cpp.s

CMakeFiles/main.dir/Game.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/Game.cpp.o: ../Game.cpp
CMakeFiles/main.dir/Game.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lewis/Documents/GitHub/tic-tac-toe/Frame04/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/Game.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/Game.cpp.o -MF CMakeFiles/main.dir/Game.cpp.o.d -o CMakeFiles/main.dir/Game.cpp.o -c /Users/lewis/Documents/GitHub/tic-tac-toe/Frame04/Game.cpp

CMakeFiles/main.dir/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/Game.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lewis/Documents/GitHub/tic-tac-toe/Frame04/Game.cpp > CMakeFiles/main.dir/Game.cpp.i

CMakeFiles/main.dir/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/Game.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lewis/Documents/GitHub/tic-tac-toe/Frame04/Game.cpp -o CMakeFiles/main.dir/Game.cpp.s

CMakeFiles/main.dir/GTexture.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/GTexture.cpp.o: ../GTexture.cpp
CMakeFiles/main.dir/GTexture.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lewis/Documents/GitHub/tic-tac-toe/Frame04/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/GTexture.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/GTexture.cpp.o -MF CMakeFiles/main.dir/GTexture.cpp.o.d -o CMakeFiles/main.dir/GTexture.cpp.o -c /Users/lewis/Documents/GitHub/tic-tac-toe/Frame04/GTexture.cpp

CMakeFiles/main.dir/GTexture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/GTexture.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lewis/Documents/GitHub/tic-tac-toe/Frame04/GTexture.cpp > CMakeFiles/main.dir/GTexture.cpp.i

CMakeFiles/main.dir/GTexture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/GTexture.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lewis/Documents/GitHub/tic-tac-toe/Frame04/GTexture.cpp -o CMakeFiles/main.dir/GTexture.cpp.s

CMakeFiles/main.dir/ball.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/ball.cpp.o: ../ball.cpp
CMakeFiles/main.dir/ball.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lewis/Documents/GitHub/tic-tac-toe/Frame04/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/ball.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/ball.cpp.o -MF CMakeFiles/main.dir/ball.cpp.o.d -o CMakeFiles/main.dir/ball.cpp.o -c /Users/lewis/Documents/GitHub/tic-tac-toe/Frame04/ball.cpp

CMakeFiles/main.dir/ball.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/ball.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lewis/Documents/GitHub/tic-tac-toe/Frame04/ball.cpp > CMakeFiles/main.dir/ball.cpp.i

CMakeFiles/main.dir/ball.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/ball.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lewis/Documents/GitHub/tic-tac-toe/Frame04/ball.cpp -o CMakeFiles/main.dir/ball.cpp.s

CMakeFiles/main.dir/CheckCollision.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/CheckCollision.cpp.o: ../CheckCollision.cpp
CMakeFiles/main.dir/CheckCollision.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lewis/Documents/GitHub/tic-tac-toe/Frame04/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main.dir/CheckCollision.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/CheckCollision.cpp.o -MF CMakeFiles/main.dir/CheckCollision.cpp.o.d -o CMakeFiles/main.dir/CheckCollision.cpp.o -c /Users/lewis/Documents/GitHub/tic-tac-toe/Frame04/CheckCollision.cpp

CMakeFiles/main.dir/CheckCollision.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/CheckCollision.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lewis/Documents/GitHub/tic-tac-toe/Frame04/CheckCollision.cpp > CMakeFiles/main.dir/CheckCollision.cpp.i

CMakeFiles/main.dir/CheckCollision.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/CheckCollision.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lewis/Documents/GitHub/tic-tac-toe/Frame04/CheckCollision.cpp -o CMakeFiles/main.dir/CheckCollision.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.o" \
"CMakeFiles/main.dir/Game.cpp.o" \
"CMakeFiles/main.dir/GTexture.cpp.o" \
"CMakeFiles/main.dir/ball.cpp.o" \
"CMakeFiles/main.dir/CheckCollision.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/main.cpp.o
main: CMakeFiles/main.dir/Game.cpp.o
main: CMakeFiles/main.dir/GTexture.cpp.o
main: CMakeFiles/main.dir/ball.cpp.o
main: CMakeFiles/main.dir/CheckCollision.cpp.o
main: CMakeFiles/main.dir/build.make
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lewis/Documents/GitHub/tic-tac-toe/Frame04/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /Users/lewis/Documents/GitHub/tic-tac-toe/Frame04/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lewis/Documents/GitHub/tic-tac-toe/Frame04 /Users/lewis/Documents/GitHub/tic-tac-toe/Frame04 /Users/lewis/Documents/GitHub/tic-tac-toe/Frame04/build /Users/lewis/Documents/GitHub/tic-tac-toe/Frame04/build /Users/lewis/Documents/GitHub/tic-tac-toe/Frame04/build/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

