# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/irap/git/QtCMake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/irap/git/QtCMake/build

# Include any dependencies generated for this target.
include CMakeFiles/MyProject.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MyProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyProject.dir/flags.make

CMakeFiles/MyProject.dir/qtcmakesample.cpp.o: CMakeFiles/MyProject.dir/flags.make
CMakeFiles/MyProject.dir/qtcmakesample.cpp.o: ../qtcmakesample.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/irap/git/QtCMake/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MyProject.dir/qtcmakesample.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MyProject.dir/qtcmakesample.cpp.o -c /home/irap/git/QtCMake/qtcmakesample.cpp

CMakeFiles/MyProject.dir/qtcmakesample.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyProject.dir/qtcmakesample.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/irap/git/QtCMake/qtcmakesample.cpp > CMakeFiles/MyProject.dir/qtcmakesample.cpp.i

CMakeFiles/MyProject.dir/qtcmakesample.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyProject.dir/qtcmakesample.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/irap/git/QtCMake/qtcmakesample.cpp -o CMakeFiles/MyProject.dir/qtcmakesample.cpp.s

CMakeFiles/MyProject.dir/qtcmakesample.cpp.o.requires:
.PHONY : CMakeFiles/MyProject.dir/qtcmakesample.cpp.o.requires

CMakeFiles/MyProject.dir/qtcmakesample.cpp.o.provides: CMakeFiles/MyProject.dir/qtcmakesample.cpp.o.requires
	$(MAKE) -f CMakeFiles/MyProject.dir/build.make CMakeFiles/MyProject.dir/qtcmakesample.cpp.o.provides.build
.PHONY : CMakeFiles/MyProject.dir/qtcmakesample.cpp.o.provides

CMakeFiles/MyProject.dir/qtcmakesample.cpp.o.provides.build: CMakeFiles/MyProject.dir/qtcmakesample.cpp.o

CMakeFiles/MyProject.dir/MyProject_automoc.cpp.o: CMakeFiles/MyProject.dir/flags.make
CMakeFiles/MyProject.dir/MyProject_automoc.cpp.o: MyProject_automoc.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/irap/git/QtCMake/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MyProject.dir/MyProject_automoc.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MyProject.dir/MyProject_automoc.cpp.o -c /home/irap/git/QtCMake/build/MyProject_automoc.cpp

CMakeFiles/MyProject.dir/MyProject_automoc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyProject.dir/MyProject_automoc.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/irap/git/QtCMake/build/MyProject_automoc.cpp > CMakeFiles/MyProject.dir/MyProject_automoc.cpp.i

CMakeFiles/MyProject.dir/MyProject_automoc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyProject.dir/MyProject_automoc.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/irap/git/QtCMake/build/MyProject_automoc.cpp -o CMakeFiles/MyProject.dir/MyProject_automoc.cpp.s

CMakeFiles/MyProject.dir/MyProject_automoc.cpp.o.requires:
.PHONY : CMakeFiles/MyProject.dir/MyProject_automoc.cpp.o.requires

CMakeFiles/MyProject.dir/MyProject_automoc.cpp.o.provides: CMakeFiles/MyProject.dir/MyProject_automoc.cpp.o.requires
	$(MAKE) -f CMakeFiles/MyProject.dir/build.make CMakeFiles/MyProject.dir/MyProject_automoc.cpp.o.provides.build
.PHONY : CMakeFiles/MyProject.dir/MyProject_automoc.cpp.o.provides

CMakeFiles/MyProject.dir/MyProject_automoc.cpp.o.provides.build: CMakeFiles/MyProject.dir/MyProject_automoc.cpp.o

# Object files for target MyProject
MyProject_OBJECTS = \
"CMakeFiles/MyProject.dir/qtcmakesample.cpp.o" \
"CMakeFiles/MyProject.dir/MyProject_automoc.cpp.o"

# External object files for target MyProject
MyProject_EXTERNAL_OBJECTS =

MyProject: CMakeFiles/MyProject.dir/qtcmakesample.cpp.o
MyProject: CMakeFiles/MyProject.dir/MyProject_automoc.cpp.o
MyProject: CMakeFiles/MyProject.dir/build.make
MyProject: libMyProjectLib.so
MyProject: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.2.1
MyProject: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.2.1
MyProject: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.2.1
MyProject: CMakeFiles/MyProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable MyProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyProject.dir/build: MyProject
.PHONY : CMakeFiles/MyProject.dir/build

CMakeFiles/MyProject.dir/requires: CMakeFiles/MyProject.dir/qtcmakesample.cpp.o.requires
CMakeFiles/MyProject.dir/requires: CMakeFiles/MyProject.dir/MyProject_automoc.cpp.o.requires
.PHONY : CMakeFiles/MyProject.dir/requires

CMakeFiles/MyProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MyProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MyProject.dir/clean

CMakeFiles/MyProject.dir/depend:
	cd /home/irap/git/QtCMake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/irap/git/QtCMake /home/irap/git/QtCMake /home/irap/git/QtCMake/build /home/irap/git/QtCMake/build /home/irap/git/QtCMake/build/CMakeFiles/MyProject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MyProject.dir/depend

