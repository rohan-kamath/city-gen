# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rohan/Documents/city-gen/OpenMesh-8.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rohan/Documents/city-gen/OpenMesh-8.0/build

# Include any dependencies generated for this target.
include src/OpenMesh/Apps/Dualizer/CMakeFiles/Dualizer.dir/depend.make

# Include the progress variables for this target.
include src/OpenMesh/Apps/Dualizer/CMakeFiles/Dualizer.dir/progress.make

# Include the compile flags for this target's objects.
include src/OpenMesh/Apps/Dualizer/CMakeFiles/Dualizer.dir/flags.make

src/OpenMesh/Apps/Dualizer/CMakeFiles/Dualizer.dir/dualizer.cc.o: src/OpenMesh/Apps/Dualizer/CMakeFiles/Dualizer.dir/flags.make
src/OpenMesh/Apps/Dualizer/CMakeFiles/Dualizer.dir/dualizer.cc.o: ../src/OpenMesh/Apps/Dualizer/dualizer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rohan/Documents/city-gen/OpenMesh-8.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/OpenMesh/Apps/Dualizer/CMakeFiles/Dualizer.dir/dualizer.cc.o"
	cd /home/rohan/Documents/city-gen/OpenMesh-8.0/build/src/OpenMesh/Apps/Dualizer && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Dualizer.dir/dualizer.cc.o -c /home/rohan/Documents/city-gen/OpenMesh-8.0/src/OpenMesh/Apps/Dualizer/dualizer.cc

src/OpenMesh/Apps/Dualizer/CMakeFiles/Dualizer.dir/dualizer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Dualizer.dir/dualizer.cc.i"
	cd /home/rohan/Documents/city-gen/OpenMesh-8.0/build/src/OpenMesh/Apps/Dualizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rohan/Documents/city-gen/OpenMesh-8.0/src/OpenMesh/Apps/Dualizer/dualizer.cc > CMakeFiles/Dualizer.dir/dualizer.cc.i

src/OpenMesh/Apps/Dualizer/CMakeFiles/Dualizer.dir/dualizer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Dualizer.dir/dualizer.cc.s"
	cd /home/rohan/Documents/city-gen/OpenMesh-8.0/build/src/OpenMesh/Apps/Dualizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rohan/Documents/city-gen/OpenMesh-8.0/src/OpenMesh/Apps/Dualizer/dualizer.cc -o CMakeFiles/Dualizer.dir/dualizer.cc.s

src/OpenMesh/Apps/Dualizer/CMakeFiles/Dualizer.dir/dualizer.cc.o.requires:

.PHONY : src/OpenMesh/Apps/Dualizer/CMakeFiles/Dualizer.dir/dualizer.cc.o.requires

src/OpenMesh/Apps/Dualizer/CMakeFiles/Dualizer.dir/dualizer.cc.o.provides: src/OpenMesh/Apps/Dualizer/CMakeFiles/Dualizer.dir/dualizer.cc.o.requires
	$(MAKE) -f src/OpenMesh/Apps/Dualizer/CMakeFiles/Dualizer.dir/build.make src/OpenMesh/Apps/Dualizer/CMakeFiles/Dualizer.dir/dualizer.cc.o.provides.build
.PHONY : src/OpenMesh/Apps/Dualizer/CMakeFiles/Dualizer.dir/dualizer.cc.o.provides

src/OpenMesh/Apps/Dualizer/CMakeFiles/Dualizer.dir/dualizer.cc.o.provides.build: src/OpenMesh/Apps/Dualizer/CMakeFiles/Dualizer.dir/dualizer.cc.o


# Object files for target Dualizer
Dualizer_OBJECTS = \
"CMakeFiles/Dualizer.dir/dualizer.cc.o"

# External object files for target Dualizer
Dualizer_EXTERNAL_OBJECTS =

Build/bin/Dualizer: src/OpenMesh/Apps/Dualizer/CMakeFiles/Dualizer.dir/dualizer.cc.o
Build/bin/Dualizer: src/OpenMesh/Apps/Dualizer/CMakeFiles/Dualizer.dir/build.make
Build/bin/Dualizer: Build/lib/libOpenMeshTools.so.8.0
Build/bin/Dualizer: Build/lib/libOpenMeshCore.so.8.0
Build/bin/Dualizer: src/OpenMesh/Apps/Dualizer/CMakeFiles/Dualizer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rohan/Documents/city-gen/OpenMesh-8.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../../Build/bin/Dualizer"
	cd /home/rohan/Documents/city-gen/OpenMesh-8.0/build/src/OpenMesh/Apps/Dualizer && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Dualizer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/OpenMesh/Apps/Dualizer/CMakeFiles/Dualizer.dir/build: Build/bin/Dualizer

.PHONY : src/OpenMesh/Apps/Dualizer/CMakeFiles/Dualizer.dir/build

src/OpenMesh/Apps/Dualizer/CMakeFiles/Dualizer.dir/requires: src/OpenMesh/Apps/Dualizer/CMakeFiles/Dualizer.dir/dualizer.cc.o.requires

.PHONY : src/OpenMesh/Apps/Dualizer/CMakeFiles/Dualizer.dir/requires

src/OpenMesh/Apps/Dualizer/CMakeFiles/Dualizer.dir/clean:
	cd /home/rohan/Documents/city-gen/OpenMesh-8.0/build/src/OpenMesh/Apps/Dualizer && $(CMAKE_COMMAND) -P CMakeFiles/Dualizer.dir/cmake_clean.cmake
.PHONY : src/OpenMesh/Apps/Dualizer/CMakeFiles/Dualizer.dir/clean

src/OpenMesh/Apps/Dualizer/CMakeFiles/Dualizer.dir/depend:
	cd /home/rohan/Documents/city-gen/OpenMesh-8.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rohan/Documents/city-gen/OpenMesh-8.0 /home/rohan/Documents/city-gen/OpenMesh-8.0/src/OpenMesh/Apps/Dualizer /home/rohan/Documents/city-gen/OpenMesh-8.0/build /home/rohan/Documents/city-gen/OpenMesh-8.0/build/src/OpenMesh/Apps/Dualizer /home/rohan/Documents/city-gen/OpenMesh-8.0/build/src/OpenMesh/Apps/Dualizer/CMakeFiles/Dualizer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/OpenMesh/Apps/Dualizer/CMakeFiles/Dualizer.dir/depend

