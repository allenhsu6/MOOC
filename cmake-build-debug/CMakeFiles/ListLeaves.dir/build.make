# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/allenhsu/CLionProjects/MOOC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/allenhsu/CLionProjects/MOOC/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ListLeaves.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ListLeaves.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ListLeaves.dir/flags.make

CMakeFiles/ListLeaves.dir/ListLeaves.cpp.o: CMakeFiles/ListLeaves.dir/flags.make
CMakeFiles/ListLeaves.dir/ListLeaves.cpp.o: ../ListLeaves.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/allenhsu/CLionProjects/MOOC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ListLeaves.dir/ListLeaves.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ListLeaves.dir/ListLeaves.cpp.o -c /Users/allenhsu/CLionProjects/MOOC/ListLeaves.cpp

CMakeFiles/ListLeaves.dir/ListLeaves.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ListLeaves.dir/ListLeaves.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/allenhsu/CLionProjects/MOOC/ListLeaves.cpp > CMakeFiles/ListLeaves.dir/ListLeaves.cpp.i

CMakeFiles/ListLeaves.dir/ListLeaves.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ListLeaves.dir/ListLeaves.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/allenhsu/CLionProjects/MOOC/ListLeaves.cpp -o CMakeFiles/ListLeaves.dir/ListLeaves.cpp.s

# Object files for target ListLeaves
ListLeaves_OBJECTS = \
"CMakeFiles/ListLeaves.dir/ListLeaves.cpp.o"

# External object files for target ListLeaves
ListLeaves_EXTERNAL_OBJECTS =

ListLeaves: CMakeFiles/ListLeaves.dir/ListLeaves.cpp.o
ListLeaves: CMakeFiles/ListLeaves.dir/build.make
ListLeaves: CMakeFiles/ListLeaves.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/allenhsu/CLionProjects/MOOC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ListLeaves"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ListLeaves.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ListLeaves.dir/build: ListLeaves

.PHONY : CMakeFiles/ListLeaves.dir/build

CMakeFiles/ListLeaves.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ListLeaves.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ListLeaves.dir/clean

CMakeFiles/ListLeaves.dir/depend:
	cd /Users/allenhsu/CLionProjects/MOOC/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/allenhsu/CLionProjects/MOOC /Users/allenhsu/CLionProjects/MOOC /Users/allenhsu/CLionProjects/MOOC/cmake-build-debug /Users/allenhsu/CLionProjects/MOOC/cmake-build-debug /Users/allenhsu/CLionProjects/MOOC/cmake-build-debug/CMakeFiles/ListLeaves.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ListLeaves.dir/depend
