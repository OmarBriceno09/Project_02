# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /cygdrive/c/Users/OmarB/.CLion2019.2/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/OmarB/.CLion2019.2/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Project_02.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Project_02.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project_02.dir/flags.make

CMakeFiles/Project_02.dir/main.cpp.o: CMakeFiles/Project_02.dir/flags.make
CMakeFiles/Project_02.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Project_02.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_02.dir/main.cpp.o -c /cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/main.cpp

CMakeFiles/Project_02.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_02.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/main.cpp > CMakeFiles/Project_02.dir/main.cpp.i

CMakeFiles/Project_02.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_02.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/main.cpp -o CMakeFiles/Project_02.dir/main.cpp.s

CMakeFiles/Project_02.dir/state_transitions.cpp.o: CMakeFiles/Project_02.dir/flags.make
CMakeFiles/Project_02.dir/state_transitions.cpp.o: ../state_transitions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Project_02.dir/state_transitions.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_02.dir/state_transitions.cpp.o -c /cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/state_transitions.cpp

CMakeFiles/Project_02.dir/state_transitions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_02.dir/state_transitions.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/state_transitions.cpp > CMakeFiles/Project_02.dir/state_transitions.cpp.i

CMakeFiles/Project_02.dir/state_transitions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_02.dir/state_transitions.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/state_transitions.cpp -o CMakeFiles/Project_02.dir/state_transitions.cpp.s

CMakeFiles/Project_02.dir/tokenizer.cpp.o: CMakeFiles/Project_02.dir/flags.make
CMakeFiles/Project_02.dir/tokenizer.cpp.o: ../tokenizer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Project_02.dir/tokenizer.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_02.dir/tokenizer.cpp.o -c /cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/tokenizer.cpp

CMakeFiles/Project_02.dir/tokenizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_02.dir/tokenizer.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/tokenizer.cpp > CMakeFiles/Project_02.dir/tokenizer.cpp.i

CMakeFiles/Project_02.dir/tokenizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_02.dir/tokenizer.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/tokenizer.cpp -o CMakeFiles/Project_02.dir/tokenizer.cpp.s

CMakeFiles/Project_02.dir/DatalogProgram.cpp.o: CMakeFiles/Project_02.dir/flags.make
CMakeFiles/Project_02.dir/DatalogProgram.cpp.o: ../DatalogProgram.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Project_02.dir/DatalogProgram.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_02.dir/DatalogProgram.cpp.o -c /cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/DatalogProgram.cpp

CMakeFiles/Project_02.dir/DatalogProgram.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_02.dir/DatalogProgram.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/DatalogProgram.cpp > CMakeFiles/Project_02.dir/DatalogProgram.cpp.i

CMakeFiles/Project_02.dir/DatalogProgram.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_02.dir/DatalogProgram.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/DatalogProgram.cpp -o CMakeFiles/Project_02.dir/DatalogProgram.cpp.s

CMakeFiles/Project_02.dir/Rule.cpp.o: CMakeFiles/Project_02.dir/flags.make
CMakeFiles/Project_02.dir/Rule.cpp.o: ../Rule.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Project_02.dir/Rule.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_02.dir/Rule.cpp.o -c /cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/Rule.cpp

CMakeFiles/Project_02.dir/Rule.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_02.dir/Rule.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/Rule.cpp > CMakeFiles/Project_02.dir/Rule.cpp.i

CMakeFiles/Project_02.dir/Rule.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_02.dir/Rule.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/Rule.cpp -o CMakeFiles/Project_02.dir/Rule.cpp.s

CMakeFiles/Project_02.dir/Predicate.cpp.o: CMakeFiles/Project_02.dir/flags.make
CMakeFiles/Project_02.dir/Predicate.cpp.o: ../Predicate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Project_02.dir/Predicate.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_02.dir/Predicate.cpp.o -c /cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/Predicate.cpp

CMakeFiles/Project_02.dir/Predicate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_02.dir/Predicate.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/Predicate.cpp > CMakeFiles/Project_02.dir/Predicate.cpp.i

CMakeFiles/Project_02.dir/Predicate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_02.dir/Predicate.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/Predicate.cpp -o CMakeFiles/Project_02.dir/Predicate.cpp.s

CMakeFiles/Project_02.dir/Parameter.cpp.o: CMakeFiles/Project_02.dir/flags.make
CMakeFiles/Project_02.dir/Parameter.cpp.o: ../Parameter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Project_02.dir/Parameter.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_02.dir/Parameter.cpp.o -c /cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/Parameter.cpp

CMakeFiles/Project_02.dir/Parameter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_02.dir/Parameter.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/Parameter.cpp > CMakeFiles/Project_02.dir/Parameter.cpp.i

CMakeFiles/Project_02.dir/Parameter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_02.dir/Parameter.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/Parameter.cpp -o CMakeFiles/Project_02.dir/Parameter.cpp.s

# Object files for target Project_02
Project_02_OBJECTS = \
"CMakeFiles/Project_02.dir/main.cpp.o" \
"CMakeFiles/Project_02.dir/state_transitions.cpp.o" \
"CMakeFiles/Project_02.dir/tokenizer.cpp.o" \
"CMakeFiles/Project_02.dir/DatalogProgram.cpp.o" \
"CMakeFiles/Project_02.dir/Rule.cpp.o" \
"CMakeFiles/Project_02.dir/Predicate.cpp.o" \
"CMakeFiles/Project_02.dir/Parameter.cpp.o"

# External object files for target Project_02
Project_02_EXTERNAL_OBJECTS =

Project_02.exe: CMakeFiles/Project_02.dir/main.cpp.o
Project_02.exe: CMakeFiles/Project_02.dir/state_transitions.cpp.o
Project_02.exe: CMakeFiles/Project_02.dir/tokenizer.cpp.o
Project_02.exe: CMakeFiles/Project_02.dir/DatalogProgram.cpp.o
Project_02.exe: CMakeFiles/Project_02.dir/Rule.cpp.o
Project_02.exe: CMakeFiles/Project_02.dir/Predicate.cpp.o
Project_02.exe: CMakeFiles/Project_02.dir/Parameter.cpp.o
Project_02.exe: CMakeFiles/Project_02.dir/build.make
Project_02.exe: CMakeFiles/Project_02.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Project_02.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Project_02.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project_02.dir/build: Project_02.exe

.PHONY : CMakeFiles/Project_02.dir/build

CMakeFiles/Project_02.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Project_02.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Project_02.dir/clean

CMakeFiles/Project_02.dir/depend:
	cd /cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02 /cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02 /cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/cmake-build-debug /cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/cmake-build-debug /cygdrive/c/Users/OmarB/Desktop/BYU-2019FALL/CS-236/Project_02/cmake-build-debug/CMakeFiles/Project_02.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Project_02.dir/depend

