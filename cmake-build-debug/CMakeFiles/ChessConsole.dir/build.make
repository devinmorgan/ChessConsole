# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.1.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.1.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Devin Morgan\CLionProjects\ChessConsole"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Devin Morgan\CLionProjects\ChessConsole\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/ChessConsole.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ChessConsole.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ChessConsole.dir/flags.make

CMakeFiles/ChessConsole.dir/main.c.obj: CMakeFiles/ChessConsole.dir/flags.make
CMakeFiles/ChessConsole.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Devin Morgan\CLionProjects\ChessConsole\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ChessConsole.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ChessConsole.dir\main.c.obj   -c "C:\Users\Devin Morgan\CLionProjects\ChessConsole\main.c"

CMakeFiles/ChessConsole.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ChessConsole.dir/main.c.i"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Devin Morgan\CLionProjects\ChessConsole\main.c" > CMakeFiles\ChessConsole.dir\main.c.i

CMakeFiles/ChessConsole.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ChessConsole.dir/main.c.s"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Devin Morgan\CLionProjects\ChessConsole\main.c" -o CMakeFiles\ChessConsole.dir\main.c.s

CMakeFiles/ChessConsole.dir/main.c.obj.requires:

.PHONY : CMakeFiles/ChessConsole.dir/main.c.obj.requires

CMakeFiles/ChessConsole.dir/main.c.obj.provides: CMakeFiles/ChessConsole.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\ChessConsole.dir\build.make CMakeFiles/ChessConsole.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/ChessConsole.dir/main.c.obj.provides

CMakeFiles/ChessConsole.dir/main.c.obj.provides.build: CMakeFiles/ChessConsole.dir/main.c.obj


CMakeFiles/ChessConsole.dir/ChessBoard.c.obj: CMakeFiles/ChessConsole.dir/flags.make
CMakeFiles/ChessConsole.dir/ChessBoard.c.obj: ../ChessBoard.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Devin Morgan\CLionProjects\ChessConsole\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ChessConsole.dir/ChessBoard.c.obj"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ChessConsole.dir\ChessBoard.c.obj   -c "C:\Users\Devin Morgan\CLionProjects\ChessConsole\ChessBoard.c"

CMakeFiles/ChessConsole.dir/ChessBoard.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ChessConsole.dir/ChessBoard.c.i"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Devin Morgan\CLionProjects\ChessConsole\ChessBoard.c" > CMakeFiles\ChessConsole.dir\ChessBoard.c.i

CMakeFiles/ChessConsole.dir/ChessBoard.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ChessConsole.dir/ChessBoard.c.s"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Devin Morgan\CLionProjects\ChessConsole\ChessBoard.c" -o CMakeFiles\ChessConsole.dir\ChessBoard.c.s

CMakeFiles/ChessConsole.dir/ChessBoard.c.obj.requires:

.PHONY : CMakeFiles/ChessConsole.dir/ChessBoard.c.obj.requires

CMakeFiles/ChessConsole.dir/ChessBoard.c.obj.provides: CMakeFiles/ChessConsole.dir/ChessBoard.c.obj.requires
	$(MAKE) -f CMakeFiles\ChessConsole.dir\build.make CMakeFiles/ChessConsole.dir/ChessBoard.c.obj.provides.build
.PHONY : CMakeFiles/ChessConsole.dir/ChessBoard.c.obj.provides

CMakeFiles/ChessConsole.dir/ChessBoard.c.obj.provides.build: CMakeFiles/ChessConsole.dir/ChessBoard.c.obj


CMakeFiles/ChessConsole.dir/ChessGameState.c.obj: CMakeFiles/ChessConsole.dir/flags.make
CMakeFiles/ChessConsole.dir/ChessGameState.c.obj: ../ChessGameState.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Devin Morgan\CLionProjects\ChessConsole\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ChessConsole.dir/ChessGameState.c.obj"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ChessConsole.dir\ChessGameState.c.obj   -c "C:\Users\Devin Morgan\CLionProjects\ChessConsole\ChessGameState.c"

CMakeFiles/ChessConsole.dir/ChessGameState.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ChessConsole.dir/ChessGameState.c.i"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Devin Morgan\CLionProjects\ChessConsole\ChessGameState.c" > CMakeFiles\ChessConsole.dir\ChessGameState.c.i

CMakeFiles/ChessConsole.dir/ChessGameState.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ChessConsole.dir/ChessGameState.c.s"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Devin Morgan\CLionProjects\ChessConsole\ChessGameState.c" -o CMakeFiles\ChessConsole.dir\ChessGameState.c.s

CMakeFiles/ChessConsole.dir/ChessGameState.c.obj.requires:

.PHONY : CMakeFiles/ChessConsole.dir/ChessGameState.c.obj.requires

CMakeFiles/ChessConsole.dir/ChessGameState.c.obj.provides: CMakeFiles/ChessConsole.dir/ChessGameState.c.obj.requires
	$(MAKE) -f CMakeFiles\ChessConsole.dir\build.make CMakeFiles/ChessConsole.dir/ChessGameState.c.obj.provides.build
.PHONY : CMakeFiles/ChessConsole.dir/ChessGameState.c.obj.provides

CMakeFiles/ChessConsole.dir/ChessGameState.c.obj.provides.build: CMakeFiles/ChessConsole.dir/ChessGameState.c.obj


# Object files for target ChessConsole
ChessConsole_OBJECTS = \
"CMakeFiles/ChessConsole.dir/main.c.obj" \
"CMakeFiles/ChessConsole.dir/ChessBoard.c.obj" \
"CMakeFiles/ChessConsole.dir/ChessGameState.c.obj"

# External object files for target ChessConsole
ChessConsole_EXTERNAL_OBJECTS =

ChessConsole.exe: CMakeFiles/ChessConsole.dir/main.c.obj
ChessConsole.exe: CMakeFiles/ChessConsole.dir/ChessBoard.c.obj
ChessConsole.exe: CMakeFiles/ChessConsole.dir/ChessGameState.c.obj
ChessConsole.exe: CMakeFiles/ChessConsole.dir/build.make
ChessConsole.exe: CMakeFiles/ChessConsole.dir/linklibs.rsp
ChessConsole.exe: CMakeFiles/ChessConsole.dir/objects1.rsp
ChessConsole.exe: CMakeFiles/ChessConsole.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Devin Morgan\CLionProjects\ChessConsole\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable ChessConsole.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ChessConsole.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ChessConsole.dir/build: ChessConsole.exe

.PHONY : CMakeFiles/ChessConsole.dir/build

CMakeFiles/ChessConsole.dir/requires: CMakeFiles/ChessConsole.dir/main.c.obj.requires
CMakeFiles/ChessConsole.dir/requires: CMakeFiles/ChessConsole.dir/ChessBoard.c.obj.requires
CMakeFiles/ChessConsole.dir/requires: CMakeFiles/ChessConsole.dir/ChessGameState.c.obj.requires

.PHONY : CMakeFiles/ChessConsole.dir/requires

CMakeFiles/ChessConsole.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ChessConsole.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ChessConsole.dir/clean

CMakeFiles/ChessConsole.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Devin Morgan\CLionProjects\ChessConsole" "C:\Users\Devin Morgan\CLionProjects\ChessConsole" "C:\Users\Devin Morgan\CLionProjects\ChessConsole\cmake-build-debug" "C:\Users\Devin Morgan\CLionProjects\ChessConsole\cmake-build-debug" "C:\Users\Devin Morgan\CLionProjects\ChessConsole\cmake-build-debug\CMakeFiles\ChessConsole.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ChessConsole.dir/depend

