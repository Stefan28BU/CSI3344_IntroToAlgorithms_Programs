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
CMAKE_SOURCE_DIR = "/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/proj0-new"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/proj0-new/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/proj0_new.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/proj0_new.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/proj0_new.dir/flags.make

CMakeFiles/proj0_new.dir/MainGraphTester.cpp.o: CMakeFiles/proj0_new.dir/flags.make
CMakeFiles/proj0_new.dir/MainGraphTester.cpp.o: ../MainGraphTester.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/proj0-new/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/proj0_new.dir/MainGraphTester.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/proj0_new.dir/MainGraphTester.cpp.o -c "/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/proj0-new/MainGraphTester.cpp"

CMakeFiles/proj0_new.dir/MainGraphTester.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proj0_new.dir/MainGraphTester.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/proj0-new/MainGraphTester.cpp" > CMakeFiles/proj0_new.dir/MainGraphTester.cpp.i

CMakeFiles/proj0_new.dir/MainGraphTester.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proj0_new.dir/MainGraphTester.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/proj0-new/MainGraphTester.cpp" -o CMakeFiles/proj0_new.dir/MainGraphTester.cpp.s

CMakeFiles/proj0_new.dir/MainGraphTester.cpp.o.requires:

.PHONY : CMakeFiles/proj0_new.dir/MainGraphTester.cpp.o.requires

CMakeFiles/proj0_new.dir/MainGraphTester.cpp.o.provides: CMakeFiles/proj0_new.dir/MainGraphTester.cpp.o.requires
	$(MAKE) -f CMakeFiles/proj0_new.dir/build.make CMakeFiles/proj0_new.dir/MainGraphTester.cpp.o.provides.build
.PHONY : CMakeFiles/proj0_new.dir/MainGraphTester.cpp.o.provides

CMakeFiles/proj0_new.dir/MainGraphTester.cpp.o.provides.build: CMakeFiles/proj0_new.dir/MainGraphTester.cpp.o


CMakeFiles/proj0_new.dir/TestSuccessor.cpp.o: CMakeFiles/proj0_new.dir/flags.make
CMakeFiles/proj0_new.dir/TestSuccessor.cpp.o: ../TestSuccessor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/proj0-new/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/proj0_new.dir/TestSuccessor.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/proj0_new.dir/TestSuccessor.cpp.o -c "/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/proj0-new/TestSuccessor.cpp"

CMakeFiles/proj0_new.dir/TestSuccessor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proj0_new.dir/TestSuccessor.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/proj0-new/TestSuccessor.cpp" > CMakeFiles/proj0_new.dir/TestSuccessor.cpp.i

CMakeFiles/proj0_new.dir/TestSuccessor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proj0_new.dir/TestSuccessor.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/proj0-new/TestSuccessor.cpp" -o CMakeFiles/proj0_new.dir/TestSuccessor.cpp.s

CMakeFiles/proj0_new.dir/TestSuccessor.cpp.o.requires:

.PHONY : CMakeFiles/proj0_new.dir/TestSuccessor.cpp.o.requires

CMakeFiles/proj0_new.dir/TestSuccessor.cpp.o.provides: CMakeFiles/proj0_new.dir/TestSuccessor.cpp.o.requires
	$(MAKE) -f CMakeFiles/proj0_new.dir/build.make CMakeFiles/proj0_new.dir/TestSuccessor.cpp.o.provides.build
.PHONY : CMakeFiles/proj0_new.dir/TestSuccessor.cpp.o.provides

CMakeFiles/proj0_new.dir/TestSuccessor.cpp.o.provides.build: CMakeFiles/proj0_new.dir/TestSuccessor.cpp.o


CMakeFiles/proj0_new.dir/Successors.cpp.o: CMakeFiles/proj0_new.dir/flags.make
CMakeFiles/proj0_new.dir/Successors.cpp.o: ../Successors.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/proj0-new/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/proj0_new.dir/Successors.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/proj0_new.dir/Successors.cpp.o -c "/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/proj0-new/Successors.cpp"

CMakeFiles/proj0_new.dir/Successors.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proj0_new.dir/Successors.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/proj0-new/Successors.cpp" > CMakeFiles/proj0_new.dir/Successors.cpp.i

CMakeFiles/proj0_new.dir/Successors.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proj0_new.dir/Successors.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/proj0-new/Successors.cpp" -o CMakeFiles/proj0_new.dir/Successors.cpp.s

CMakeFiles/proj0_new.dir/Successors.cpp.o.requires:

.PHONY : CMakeFiles/proj0_new.dir/Successors.cpp.o.requires

CMakeFiles/proj0_new.dir/Successors.cpp.o.provides: CMakeFiles/proj0_new.dir/Successors.cpp.o.requires
	$(MAKE) -f CMakeFiles/proj0_new.dir/build.make CMakeFiles/proj0_new.dir/Successors.cpp.o.provides.build
.PHONY : CMakeFiles/proj0_new.dir/Successors.cpp.o.provides

CMakeFiles/proj0_new.dir/Successors.cpp.o.provides.build: CMakeFiles/proj0_new.dir/Successors.cpp.o


# Object files for target proj0_new
proj0_new_OBJECTS = \
"CMakeFiles/proj0_new.dir/MainGraphTester.cpp.o" \
"CMakeFiles/proj0_new.dir/TestSuccessor.cpp.o" \
"CMakeFiles/proj0_new.dir/Successors.cpp.o"

# External object files for target proj0_new
proj0_new_EXTERNAL_OBJECTS =

proj0_new: CMakeFiles/proj0_new.dir/MainGraphTester.cpp.o
proj0_new: CMakeFiles/proj0_new.dir/TestSuccessor.cpp.o
proj0_new: CMakeFiles/proj0_new.dir/Successors.cpp.o
proj0_new: CMakeFiles/proj0_new.dir/build.make
proj0_new: CMakeFiles/proj0_new.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/proj0-new/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable proj0_new"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/proj0_new.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/proj0_new.dir/build: proj0_new

.PHONY : CMakeFiles/proj0_new.dir/build

CMakeFiles/proj0_new.dir/requires: CMakeFiles/proj0_new.dir/MainGraphTester.cpp.o.requires
CMakeFiles/proj0_new.dir/requires: CMakeFiles/proj0_new.dir/TestSuccessor.cpp.o.requires
CMakeFiles/proj0_new.dir/requires: CMakeFiles/proj0_new.dir/Successors.cpp.o.requires

.PHONY : CMakeFiles/proj0_new.dir/requires

CMakeFiles/proj0_new.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/proj0_new.dir/cmake_clean.cmake
.PHONY : CMakeFiles/proj0_new.dir/clean

CMakeFiles/proj0_new.dir/depend:
	cd "/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/proj0-new/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/proj0-new" "/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/proj0-new" "/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/proj0-new/cmake-build-debug" "/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/proj0-new/cmake-build-debug" "/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/proj0-new/cmake-build-debug/CMakeFiles/proj0_new.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/proj0_new.dir/depend

