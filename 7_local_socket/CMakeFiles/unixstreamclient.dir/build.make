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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.16.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.16.5/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sanjay/Documents/GitHub/yolanda/7_local_socket

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sanjay/Documents/GitHub/yolanda/7_local_socket

# Include any dependencies generated for this target.
include CMakeFiles/unixstreamclient.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/unixstreamclient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/unixstreamclient.dir/flags.make

CMakeFiles/unixstreamclient.dir/unixstreamclient.c.o: CMakeFiles/unixstreamclient.dir/flags.make
CMakeFiles/unixstreamclient.dir/unixstreamclient.c.o: unixstreamclient.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sanjay/Documents/GitHub/yolanda/7_local_socket/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/unixstreamclient.dir/unixstreamclient.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/unixstreamclient.dir/unixstreamclient.c.o   -c /Users/sanjay/Documents/GitHub/yolanda/7_local_socket/unixstreamclient.c

CMakeFiles/unixstreamclient.dir/unixstreamclient.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/unixstreamclient.dir/unixstreamclient.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/sanjay/Documents/GitHub/yolanda/7_local_socket/unixstreamclient.c > CMakeFiles/unixstreamclient.dir/unixstreamclient.c.i

CMakeFiles/unixstreamclient.dir/unixstreamclient.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/unixstreamclient.dir/unixstreamclient.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/sanjay/Documents/GitHub/yolanda/7_local_socket/unixstreamclient.c -o CMakeFiles/unixstreamclient.dir/unixstreamclient.c.s

# Object files for target unixstreamclient
unixstreamclient_OBJECTS = \
"CMakeFiles/unixstreamclient.dir/unixstreamclient.c.o"

# External object files for target unixstreamclient
unixstreamclient_EXTERNAL_OBJECTS =

unixstreamclient: CMakeFiles/unixstreamclient.dir/unixstreamclient.c.o
unixstreamclient: CMakeFiles/unixstreamclient.dir/build.make
unixstreamclient: CMakeFiles/unixstreamclient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sanjay/Documents/GitHub/yolanda/7_local_socket/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable unixstreamclient"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unixstreamclient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/unixstreamclient.dir/build: unixstreamclient

.PHONY : CMakeFiles/unixstreamclient.dir/build

CMakeFiles/unixstreamclient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/unixstreamclient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/unixstreamclient.dir/clean

CMakeFiles/unixstreamclient.dir/depend:
	cd /Users/sanjay/Documents/GitHub/yolanda/7_local_socket && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sanjay/Documents/GitHub/yolanda/7_local_socket /Users/sanjay/Documents/GitHub/yolanda/7_local_socket /Users/sanjay/Documents/GitHub/yolanda/7_local_socket /Users/sanjay/Documents/GitHub/yolanda/7_local_socket /Users/sanjay/Documents/GitHub/yolanda/7_local_socket/CMakeFiles/unixstreamclient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/unixstreamclient.dir/depend

