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
CMAKE_SOURCE_DIR = /Users/sanjay/Documents/GitHub/yolanda/chap-6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sanjay/Documents/GitHub/yolanda/chap-6

# Include any dependencies generated for this target.
include CMakeFiles/my_udp_client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/my_udp_client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_udp_client.dir/flags.make

CMakeFiles/my_udp_client.dir/my_udp_client.c.o: CMakeFiles/my_udp_client.dir/flags.make
CMakeFiles/my_udp_client.dir/my_udp_client.c.o: my_udp_client.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sanjay/Documents/GitHub/yolanda/chap-6/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/my_udp_client.dir/my_udp_client.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/my_udp_client.dir/my_udp_client.c.o   -c /Users/sanjay/Documents/GitHub/yolanda/chap-6/my_udp_client.c

CMakeFiles/my_udp_client.dir/my_udp_client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_udp_client.dir/my_udp_client.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/sanjay/Documents/GitHub/yolanda/chap-6/my_udp_client.c > CMakeFiles/my_udp_client.dir/my_udp_client.c.i

CMakeFiles/my_udp_client.dir/my_udp_client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_udp_client.dir/my_udp_client.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/sanjay/Documents/GitHub/yolanda/chap-6/my_udp_client.c -o CMakeFiles/my_udp_client.dir/my_udp_client.c.s

# Object files for target my_udp_client
my_udp_client_OBJECTS = \
"CMakeFiles/my_udp_client.dir/my_udp_client.c.o"

# External object files for target my_udp_client
my_udp_client_EXTERNAL_OBJECTS =

my_udp_client: CMakeFiles/my_udp_client.dir/my_udp_client.c.o
my_udp_client: CMakeFiles/my_udp_client.dir/build.make
my_udp_client: CMakeFiles/my_udp_client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sanjay/Documents/GitHub/yolanda/chap-6/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable my_udp_client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_udp_client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_udp_client.dir/build: my_udp_client

.PHONY : CMakeFiles/my_udp_client.dir/build

CMakeFiles/my_udp_client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_udp_client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_udp_client.dir/clean

CMakeFiles/my_udp_client.dir/depend:
	cd /Users/sanjay/Documents/GitHub/yolanda/chap-6 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sanjay/Documents/GitHub/yolanda/chap-6 /Users/sanjay/Documents/GitHub/yolanda/chap-6 /Users/sanjay/Documents/GitHub/yolanda/chap-6 /Users/sanjay/Documents/GitHub/yolanda/chap-6 /Users/sanjay/Documents/GitHub/yolanda/chap-6/CMakeFiles/my_udp_client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_udp_client.dir/depend

