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
CMAKE_SOURCE_DIR = /Users/lewis/Documents/GitHub/tic-tac-toe/tic-tac-toe

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lewis/Documents/GitHub/tic-tac-toe/tic-tac-toe/build-release

# Include any dependencies generated for this target.
include CMakeFiles/tic-tac-toe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tic-tac-toe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tic-tac-toe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tic-tac-toe.dir/flags.make

CMakeFiles/tic-tac-toe.dir/main.cpp.o: CMakeFiles/tic-tac-toe.dir/flags.make
CMakeFiles/tic-tac-toe.dir/main.cpp.o: ../main.cpp
CMakeFiles/tic-tac-toe.dir/main.cpp.o: CMakeFiles/tic-tac-toe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lewis/Documents/GitHub/tic-tac-toe/tic-tac-toe/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tic-tac-toe.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tic-tac-toe.dir/main.cpp.o -MF CMakeFiles/tic-tac-toe.dir/main.cpp.o.d -o CMakeFiles/tic-tac-toe.dir/main.cpp.o -c /Users/lewis/Documents/GitHub/tic-tac-toe/tic-tac-toe/main.cpp

CMakeFiles/tic-tac-toe.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tic-tac-toe.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lewis/Documents/GitHub/tic-tac-toe/tic-tac-toe/main.cpp > CMakeFiles/tic-tac-toe.dir/main.cpp.i

CMakeFiles/tic-tac-toe.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tic-tac-toe.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lewis/Documents/GitHub/tic-tac-toe/tic-tac-toe/main.cpp -o CMakeFiles/tic-tac-toe.dir/main.cpp.s

CMakeFiles/tic-tac-toe.dir/loadTexture.cpp.o: CMakeFiles/tic-tac-toe.dir/flags.make
CMakeFiles/tic-tac-toe.dir/loadTexture.cpp.o: ../loadTexture.cpp
CMakeFiles/tic-tac-toe.dir/loadTexture.cpp.o: CMakeFiles/tic-tac-toe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lewis/Documents/GitHub/tic-tac-toe/tic-tac-toe/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tic-tac-toe.dir/loadTexture.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tic-tac-toe.dir/loadTexture.cpp.o -MF CMakeFiles/tic-tac-toe.dir/loadTexture.cpp.o.d -o CMakeFiles/tic-tac-toe.dir/loadTexture.cpp.o -c /Users/lewis/Documents/GitHub/tic-tac-toe/tic-tac-toe/loadTexture.cpp

CMakeFiles/tic-tac-toe.dir/loadTexture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tic-tac-toe.dir/loadTexture.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lewis/Documents/GitHub/tic-tac-toe/tic-tac-toe/loadTexture.cpp > CMakeFiles/tic-tac-toe.dir/loadTexture.cpp.i

CMakeFiles/tic-tac-toe.dir/loadTexture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tic-tac-toe.dir/loadTexture.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lewis/Documents/GitHub/tic-tac-toe/tic-tac-toe/loadTexture.cpp -o CMakeFiles/tic-tac-toe.dir/loadTexture.cpp.s

CMakeFiles/tic-tac-toe.dir/mainGame.cpp.o: CMakeFiles/tic-tac-toe.dir/flags.make
CMakeFiles/tic-tac-toe.dir/mainGame.cpp.o: ../mainGame.cpp
CMakeFiles/tic-tac-toe.dir/mainGame.cpp.o: CMakeFiles/tic-tac-toe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lewis/Documents/GitHub/tic-tac-toe/tic-tac-toe/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tic-tac-toe.dir/mainGame.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tic-tac-toe.dir/mainGame.cpp.o -MF CMakeFiles/tic-tac-toe.dir/mainGame.cpp.o.d -o CMakeFiles/tic-tac-toe.dir/mainGame.cpp.o -c /Users/lewis/Documents/GitHub/tic-tac-toe/tic-tac-toe/mainGame.cpp

CMakeFiles/tic-tac-toe.dir/mainGame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tic-tac-toe.dir/mainGame.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lewis/Documents/GitHub/tic-tac-toe/tic-tac-toe/mainGame.cpp > CMakeFiles/tic-tac-toe.dir/mainGame.cpp.i

CMakeFiles/tic-tac-toe.dir/mainGame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tic-tac-toe.dir/mainGame.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lewis/Documents/GitHub/tic-tac-toe/tic-tac-toe/mainGame.cpp -o CMakeFiles/tic-tac-toe.dir/mainGame.cpp.s

CMakeFiles/tic-tac-toe.dir/mouseEvent.cpp.o: CMakeFiles/tic-tac-toe.dir/flags.make
CMakeFiles/tic-tac-toe.dir/mouseEvent.cpp.o: ../mouseEvent.cpp
CMakeFiles/tic-tac-toe.dir/mouseEvent.cpp.o: CMakeFiles/tic-tac-toe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lewis/Documents/GitHub/tic-tac-toe/tic-tac-toe/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/tic-tac-toe.dir/mouseEvent.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tic-tac-toe.dir/mouseEvent.cpp.o -MF CMakeFiles/tic-tac-toe.dir/mouseEvent.cpp.o.d -o CMakeFiles/tic-tac-toe.dir/mouseEvent.cpp.o -c /Users/lewis/Documents/GitHub/tic-tac-toe/tic-tac-toe/mouseEvent.cpp

CMakeFiles/tic-tac-toe.dir/mouseEvent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tic-tac-toe.dir/mouseEvent.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lewis/Documents/GitHub/tic-tac-toe/tic-tac-toe/mouseEvent.cpp > CMakeFiles/tic-tac-toe.dir/mouseEvent.cpp.i

CMakeFiles/tic-tac-toe.dir/mouseEvent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tic-tac-toe.dir/mouseEvent.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lewis/Documents/GitHub/tic-tac-toe/tic-tac-toe/mouseEvent.cpp -o CMakeFiles/tic-tac-toe.dir/mouseEvent.cpp.s

CMakeFiles/tic-tac-toe.dir/rendererDraw.cpp.o: CMakeFiles/tic-tac-toe.dir/flags.make
CMakeFiles/tic-tac-toe.dir/rendererDraw.cpp.o: ../rendererDraw.cpp
CMakeFiles/tic-tac-toe.dir/rendererDraw.cpp.o: CMakeFiles/tic-tac-toe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lewis/Documents/GitHub/tic-tac-toe/tic-tac-toe/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/tic-tac-toe.dir/rendererDraw.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tic-tac-toe.dir/rendererDraw.cpp.o -MF CMakeFiles/tic-tac-toe.dir/rendererDraw.cpp.o.d -o CMakeFiles/tic-tac-toe.dir/rendererDraw.cpp.o -c /Users/lewis/Documents/GitHub/tic-tac-toe/tic-tac-toe/rendererDraw.cpp

CMakeFiles/tic-tac-toe.dir/rendererDraw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tic-tac-toe.dir/rendererDraw.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lewis/Documents/GitHub/tic-tac-toe/tic-tac-toe/rendererDraw.cpp > CMakeFiles/tic-tac-toe.dir/rendererDraw.cpp.i

CMakeFiles/tic-tac-toe.dir/rendererDraw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tic-tac-toe.dir/rendererDraw.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lewis/Documents/GitHub/tic-tac-toe/tic-tac-toe/rendererDraw.cpp -o CMakeFiles/tic-tac-toe.dir/rendererDraw.cpp.s

# Object files for target tic-tac-toe
tic__tac__toe_OBJECTS = \
"CMakeFiles/tic-tac-toe.dir/main.cpp.o" \
"CMakeFiles/tic-tac-toe.dir/loadTexture.cpp.o" \
"CMakeFiles/tic-tac-toe.dir/mainGame.cpp.o" \
"CMakeFiles/tic-tac-toe.dir/mouseEvent.cpp.o" \
"CMakeFiles/tic-tac-toe.dir/rendererDraw.cpp.o"

# External object files for target tic-tac-toe
tic__tac__toe_EXTERNAL_OBJECTS =

tic-tac-toe: CMakeFiles/tic-tac-toe.dir/main.cpp.o
tic-tac-toe: CMakeFiles/tic-tac-toe.dir/loadTexture.cpp.o
tic-tac-toe: CMakeFiles/tic-tac-toe.dir/mainGame.cpp.o
tic-tac-toe: CMakeFiles/tic-tac-toe.dir/mouseEvent.cpp.o
tic-tac-toe: CMakeFiles/tic-tac-toe.dir/rendererDraw.cpp.o
tic-tac-toe: CMakeFiles/tic-tac-toe.dir/build.make
tic-tac-toe: CMakeFiles/tic-tac-toe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lewis/Documents/GitHub/tic-tac-toe/tic-tac-toe/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable tic-tac-toe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tic-tac-toe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tic-tac-toe.dir/build: tic-tac-toe
.PHONY : CMakeFiles/tic-tac-toe.dir/build

CMakeFiles/tic-tac-toe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tic-tac-toe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tic-tac-toe.dir/clean

CMakeFiles/tic-tac-toe.dir/depend:
	cd /Users/lewis/Documents/GitHub/tic-tac-toe/tic-tac-toe/build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lewis/Documents/GitHub/tic-tac-toe/tic-tac-toe /Users/lewis/Documents/GitHub/tic-tac-toe/tic-tac-toe /Users/lewis/Documents/GitHub/tic-tac-toe/tic-tac-toe/build-release /Users/lewis/Documents/GitHub/tic-tac-toe/tic-tac-toe/build-release /Users/lewis/Documents/GitHub/tic-tac-toe/tic-tac-toe/build-release/CMakeFiles/tic-tac-toe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tic-tac-toe.dir/depend
