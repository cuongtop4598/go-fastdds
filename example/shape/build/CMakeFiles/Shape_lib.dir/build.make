# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /usr/local/bin/cmake-3.29.0-rc1-linux-x86_64/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake-3.29.0-rc1-linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dev/go/src/github.com/go-fastdds/example/shape

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dev/go/src/github.com/go-fastdds/example/shape/build

# Include any dependencies generated for this target.
include CMakeFiles/Shape_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Shape_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Shape_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Shape_lib.dir/flags.make

CMakeFiles/Shape_lib.dir/Shape.cxx.o: CMakeFiles/Shape_lib.dir/flags.make
CMakeFiles/Shape_lib.dir/Shape.cxx.o: /home/dev/go/src/github.com/go-fastdds/example/shape/Shape.cxx
CMakeFiles/Shape_lib.dir/Shape.cxx.o: CMakeFiles/Shape_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/dev/go/src/github.com/go-fastdds/example/shape/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Shape_lib.dir/Shape.cxx.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Shape_lib.dir/Shape.cxx.o -MF CMakeFiles/Shape_lib.dir/Shape.cxx.o.d -o CMakeFiles/Shape_lib.dir/Shape.cxx.o -c /home/dev/go/src/github.com/go-fastdds/example/shape/Shape.cxx

CMakeFiles/Shape_lib.dir/Shape.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Shape_lib.dir/Shape.cxx.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dev/go/src/github.com/go-fastdds/example/shape/Shape.cxx > CMakeFiles/Shape_lib.dir/Shape.cxx.i

CMakeFiles/Shape_lib.dir/Shape.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Shape_lib.dir/Shape.cxx.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dev/go/src/github.com/go-fastdds/example/shape/Shape.cxx -o CMakeFiles/Shape_lib.dir/Shape.cxx.s

# Object files for target Shape_lib
Shape_lib_OBJECTS = \
"CMakeFiles/Shape_lib.dir/Shape.cxx.o"

# External object files for target Shape_lib
Shape_lib_EXTERNAL_OBJECTS =

libShape_lib.a: CMakeFiles/Shape_lib.dir/Shape.cxx.o
libShape_lib.a: CMakeFiles/Shape_lib.dir/build.make
libShape_lib.a: CMakeFiles/Shape_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/dev/go/src/github.com/go-fastdds/example/shape/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libShape_lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Shape_lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Shape_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Shape_lib.dir/build: libShape_lib.a
.PHONY : CMakeFiles/Shape_lib.dir/build

CMakeFiles/Shape_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Shape_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Shape_lib.dir/clean

CMakeFiles/Shape_lib.dir/depend:
	cd /home/dev/go/src/github.com/go-fastdds/example/shape/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dev/go/src/github.com/go-fastdds/example/shape /home/dev/go/src/github.com/go-fastdds/example/shape /home/dev/go/src/github.com/go-fastdds/example/shape/build /home/dev/go/src/github.com/go-fastdds/example/shape/build /home/dev/go/src/github.com/go-fastdds/example/shape/build/CMakeFiles/Shape_lib.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Shape_lib.dir/depend

