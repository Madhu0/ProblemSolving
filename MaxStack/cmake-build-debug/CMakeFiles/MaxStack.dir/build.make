# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/madhusudhan/MyCoding/ProblemSolving/MaxStack

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/madhusudhan/MyCoding/ProblemSolving/MaxStack/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MaxStack.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MaxStack.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MaxStack.dir/flags.make

CMakeFiles/MaxStack.dir/main.c.o: CMakeFiles/MaxStack.dir/flags.make
CMakeFiles/MaxStack.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/madhusudhan/MyCoding/ProblemSolving/MaxStack/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/MaxStack.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MaxStack.dir/main.c.o   -c /Users/madhusudhan/MyCoding/ProblemSolving/MaxStack/main.c

CMakeFiles/MaxStack.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MaxStack.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/madhusudhan/MyCoding/ProblemSolving/MaxStack/main.c > CMakeFiles/MaxStack.dir/main.c.i

CMakeFiles/MaxStack.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MaxStack.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/madhusudhan/MyCoding/ProblemSolving/MaxStack/main.c -o CMakeFiles/MaxStack.dir/main.c.s

CMakeFiles/MaxStack.dir/main.c.o.requires:

.PHONY : CMakeFiles/MaxStack.dir/main.c.o.requires

CMakeFiles/MaxStack.dir/main.c.o.provides: CMakeFiles/MaxStack.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/MaxStack.dir/build.make CMakeFiles/MaxStack.dir/main.c.o.provides.build
.PHONY : CMakeFiles/MaxStack.dir/main.c.o.provides

CMakeFiles/MaxStack.dir/main.c.o.provides.build: CMakeFiles/MaxStack.dir/main.c.o


# Object files for target MaxStack
MaxStack_OBJECTS = \
"CMakeFiles/MaxStack.dir/main.c.o"

# External object files for target MaxStack
MaxStack_EXTERNAL_OBJECTS =

MaxStack: CMakeFiles/MaxStack.dir/main.c.o
MaxStack: CMakeFiles/MaxStack.dir/build.make
MaxStack: CMakeFiles/MaxStack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/madhusudhan/MyCoding/ProblemSolving/MaxStack/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable MaxStack"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MaxStack.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MaxStack.dir/build: MaxStack

.PHONY : CMakeFiles/MaxStack.dir/build

CMakeFiles/MaxStack.dir/requires: CMakeFiles/MaxStack.dir/main.c.o.requires

.PHONY : CMakeFiles/MaxStack.dir/requires

CMakeFiles/MaxStack.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MaxStack.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MaxStack.dir/clean

CMakeFiles/MaxStack.dir/depend:
	cd /Users/madhusudhan/MyCoding/ProblemSolving/MaxStack/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/madhusudhan/MyCoding/ProblemSolving/MaxStack /Users/madhusudhan/MyCoding/ProblemSolving/MaxStack /Users/madhusudhan/MyCoding/ProblemSolving/MaxStack/cmake-build-debug /Users/madhusudhan/MyCoding/ProblemSolving/MaxStack/cmake-build-debug /Users/madhusudhan/MyCoding/ProblemSolving/MaxStack/cmake-build-debug/CMakeFiles/MaxStack.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MaxStack.dir/depend
