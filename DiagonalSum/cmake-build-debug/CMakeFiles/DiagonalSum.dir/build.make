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
CMAKE_SOURCE_DIR = /Users/madhusudhan/MyCoding/ProblemSolving/DiagonalSum

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/madhusudhan/MyCoding/ProblemSolving/DiagonalSum/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DiagonalSum.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DiagonalSum.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DiagonalSum.dir/flags.make

CMakeFiles/DiagonalSum.dir/main.c.o: CMakeFiles/DiagonalSum.dir/flags.make
CMakeFiles/DiagonalSum.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/madhusudhan/MyCoding/ProblemSolving/DiagonalSum/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/DiagonalSum.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/DiagonalSum.dir/main.c.o   -c /Users/madhusudhan/MyCoding/ProblemSolving/DiagonalSum/main.c

CMakeFiles/DiagonalSum.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DiagonalSum.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/madhusudhan/MyCoding/ProblemSolving/DiagonalSum/main.c > CMakeFiles/DiagonalSum.dir/main.c.i

CMakeFiles/DiagonalSum.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DiagonalSum.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/madhusudhan/MyCoding/ProblemSolving/DiagonalSum/main.c -o CMakeFiles/DiagonalSum.dir/main.c.s

CMakeFiles/DiagonalSum.dir/main.c.o.requires:

.PHONY : CMakeFiles/DiagonalSum.dir/main.c.o.requires

CMakeFiles/DiagonalSum.dir/main.c.o.provides: CMakeFiles/DiagonalSum.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/DiagonalSum.dir/build.make CMakeFiles/DiagonalSum.dir/main.c.o.provides.build
.PHONY : CMakeFiles/DiagonalSum.dir/main.c.o.provides

CMakeFiles/DiagonalSum.dir/main.c.o.provides.build: CMakeFiles/DiagonalSum.dir/main.c.o


# Object files for target DiagonalSum
DiagonalSum_OBJECTS = \
"CMakeFiles/DiagonalSum.dir/main.c.o"

# External object files for target DiagonalSum
DiagonalSum_EXTERNAL_OBJECTS =

DiagonalSum: CMakeFiles/DiagonalSum.dir/main.c.o
DiagonalSum: CMakeFiles/DiagonalSum.dir/build.make
DiagonalSum: CMakeFiles/DiagonalSum.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/madhusudhan/MyCoding/ProblemSolving/DiagonalSum/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable DiagonalSum"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DiagonalSum.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DiagonalSum.dir/build: DiagonalSum

.PHONY : CMakeFiles/DiagonalSum.dir/build

CMakeFiles/DiagonalSum.dir/requires: CMakeFiles/DiagonalSum.dir/main.c.o.requires

.PHONY : CMakeFiles/DiagonalSum.dir/requires

CMakeFiles/DiagonalSum.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DiagonalSum.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DiagonalSum.dir/clean

CMakeFiles/DiagonalSum.dir/depend:
	cd /Users/madhusudhan/MyCoding/ProblemSolving/DiagonalSum/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/madhusudhan/MyCoding/ProblemSolving/DiagonalSum /Users/madhusudhan/MyCoding/ProblemSolving/DiagonalSum /Users/madhusudhan/MyCoding/ProblemSolving/DiagonalSum/cmake-build-debug /Users/madhusudhan/MyCoding/ProblemSolving/DiagonalSum/cmake-build-debug /Users/madhusudhan/MyCoding/ProblemSolving/DiagonalSum/cmake-build-debug/CMakeFiles/DiagonalSum.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DiagonalSum.dir/depend
