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
CMAKE_SOURCE_DIR = "/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/gp-dvc"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/gp-dvc/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/gp-dvc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gp-dvc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gp-dvc.dir/flags.make

CMakeFiles/gp-dvc.dir/Matrix.cpp.o: CMakeFiles/gp-dvc.dir/flags.make
CMakeFiles/gp-dvc.dir/Matrix.cpp.o: ../Matrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/gp-dvc/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gp-dvc.dir/Matrix.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gp-dvc.dir/Matrix.cpp.o -c "/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/gp-dvc/Matrix.cpp"

CMakeFiles/gp-dvc.dir/Matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gp-dvc.dir/Matrix.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/gp-dvc/Matrix.cpp" > CMakeFiles/gp-dvc.dir/Matrix.cpp.i

CMakeFiles/gp-dvc.dir/Matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gp-dvc.dir/Matrix.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/gp-dvc/Matrix.cpp" -o CMakeFiles/gp-dvc.dir/Matrix.cpp.s

CMakeFiles/gp-dvc.dir/Matrix.cpp.o.requires:

.PHONY : CMakeFiles/gp-dvc.dir/Matrix.cpp.o.requires

CMakeFiles/gp-dvc.dir/Matrix.cpp.o.provides: CMakeFiles/gp-dvc.dir/Matrix.cpp.o.requires
	$(MAKE) -f CMakeFiles/gp-dvc.dir/build.make CMakeFiles/gp-dvc.dir/Matrix.cpp.o.provides.build
.PHONY : CMakeFiles/gp-dvc.dir/Matrix.cpp.o.provides

CMakeFiles/gp-dvc.dir/Matrix.cpp.o.provides.build: CMakeFiles/gp-dvc.dir/Matrix.cpp.o


# Object files for target gp-dvc
gp__dvc_OBJECTS = \
"CMakeFiles/gp-dvc.dir/Matrix.cpp.o"

# External object files for target gp-dvc
gp__dvc_EXTERNAL_OBJECTS =

gp-dvc: CMakeFiles/gp-dvc.dir/Matrix.cpp.o
gp-dvc: CMakeFiles/gp-dvc.dir/build.make
gp-dvc: CMakeFiles/gp-dvc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/gp-dvc/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable gp-dvc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gp-dvc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gp-dvc.dir/build: gp-dvc

.PHONY : CMakeFiles/gp-dvc.dir/build

CMakeFiles/gp-dvc.dir/requires: CMakeFiles/gp-dvc.dir/Matrix.cpp.o.requires

.PHONY : CMakeFiles/gp-dvc.dir/requires

CMakeFiles/gp-dvc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gp-dvc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gp-dvc.dir/clean

CMakeFiles/gp-dvc.dir/depend:
	cd "/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/gp-dvc/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/gp-dvc" "/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/gp-dvc" "/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/gp-dvc/cmake-build-debug" "/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/gp-dvc/cmake-build-debug" "/Users/Stefan_Xu/Desktop/Stefan/CSI 3344/gp-dvc/cmake-build-debug/CMakeFiles/gp-dvc.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/gp-dvc.dir/depend

