# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/tchuan/wP/cmakeDemo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tchuan/wP/cmakeDemo/build

# Include any dependencies generated for this target.
include src/CMakeFiles/add.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/add.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/add.dir/flags.make

src/CMakeFiles/add.dir/add.cpp.o: src/CMakeFiles/add.dir/flags.make
src/CMakeFiles/add.dir/add.cpp.o: ../src/add.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tchuan/wP/cmakeDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/add.dir/add.cpp.o"
	cd /home/tchuan/wP/cmakeDemo/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/add.dir/add.cpp.o -c /home/tchuan/wP/cmakeDemo/src/add.cpp

src/CMakeFiles/add.dir/add.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/add.dir/add.cpp.i"
	cd /home/tchuan/wP/cmakeDemo/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tchuan/wP/cmakeDemo/src/add.cpp > CMakeFiles/add.dir/add.cpp.i

src/CMakeFiles/add.dir/add.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/add.dir/add.cpp.s"
	cd /home/tchuan/wP/cmakeDemo/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tchuan/wP/cmakeDemo/src/add.cpp -o CMakeFiles/add.dir/add.cpp.s

# Object files for target add
add_OBJECTS = \
"CMakeFiles/add.dir/add.cpp.o"

# External object files for target add
add_EXTERNAL_OBJECTS =

lib/libadd.a: src/CMakeFiles/add.dir/add.cpp.o
lib/libadd.a: src/CMakeFiles/add.dir/build.make
lib/libadd.a: src/CMakeFiles/add.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tchuan/wP/cmakeDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../lib/libadd.a"
	cd /home/tchuan/wP/cmakeDemo/build/src && $(CMAKE_COMMAND) -P CMakeFiles/add.dir/cmake_clean_target.cmake
	cd /home/tchuan/wP/cmakeDemo/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/add.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/add.dir/build: lib/libadd.a

.PHONY : src/CMakeFiles/add.dir/build

src/CMakeFiles/add.dir/clean:
	cd /home/tchuan/wP/cmakeDemo/build/src && $(CMAKE_COMMAND) -P CMakeFiles/add.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/add.dir/clean

src/CMakeFiles/add.dir/depend:
	cd /home/tchuan/wP/cmakeDemo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tchuan/wP/cmakeDemo /home/tchuan/wP/cmakeDemo/src /home/tchuan/wP/cmakeDemo/build /home/tchuan/wP/cmakeDemo/build/src /home/tchuan/wP/cmakeDemo/build/src/CMakeFiles/add.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/add.dir/depend

