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
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/bin

# Include any dependencies generated for this target.
include CMakeFiles/jeu_siam.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/jeu_siam.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/jeu_siam.dir/flags.make

CMakeFiles/jeu_siam.dir/coup_jeu.c.o: CMakeFiles/jeu_siam.dir/flags.make
CMakeFiles/jeu_siam.dir/coup_jeu.c.o: /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/coup_jeu.c
	$(CMAKE_COMMAND) -E cmake_progress_report /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/bin/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/jeu_siam.dir/coup_jeu.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/jeu_siam.dir/coup_jeu.c.o   -c /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/coup_jeu.c

CMakeFiles/jeu_siam.dir/coup_jeu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/jeu_siam.dir/coup_jeu.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/coup_jeu.c > CMakeFiles/jeu_siam.dir/coup_jeu.c.i

CMakeFiles/jeu_siam.dir/coup_jeu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/jeu_siam.dir/coup_jeu.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/coup_jeu.c -o CMakeFiles/jeu_siam.dir/coup_jeu.c.s

CMakeFiles/jeu_siam.dir/coup_jeu.c.o.requires:
.PHONY : CMakeFiles/jeu_siam.dir/coup_jeu.c.o.requires

CMakeFiles/jeu_siam.dir/coup_jeu.c.o.provides: CMakeFiles/jeu_siam.dir/coup_jeu.c.o.requires
	$(MAKE) -f CMakeFiles/jeu_siam.dir/build.make CMakeFiles/jeu_siam.dir/coup_jeu.c.o.provides.build
.PHONY : CMakeFiles/jeu_siam.dir/coup_jeu.c.o.provides

CMakeFiles/jeu_siam.dir/coup_jeu.c.o.provides.build: CMakeFiles/jeu_siam.dir/coup_jeu.c.o

CMakeFiles/jeu_siam.dir/api_siam.c.o: CMakeFiles/jeu_siam.dir/flags.make
CMakeFiles/jeu_siam.dir/api_siam.c.o: /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/api_siam.c
	$(CMAKE_COMMAND) -E cmake_progress_report /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/bin/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/jeu_siam.dir/api_siam.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/jeu_siam.dir/api_siam.c.o   -c /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/api_siam.c

CMakeFiles/jeu_siam.dir/api_siam.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/jeu_siam.dir/api_siam.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/api_siam.c > CMakeFiles/jeu_siam.dir/api_siam.c.i

CMakeFiles/jeu_siam.dir/api_siam.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/jeu_siam.dir/api_siam.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/api_siam.c -o CMakeFiles/jeu_siam.dir/api_siam.c.s

CMakeFiles/jeu_siam.dir/api_siam.c.o.requires:
.PHONY : CMakeFiles/jeu_siam.dir/api_siam.c.o.requires

CMakeFiles/jeu_siam.dir/api_siam.c.o.provides: CMakeFiles/jeu_siam.dir/api_siam.c.o.requires
	$(MAKE) -f CMakeFiles/jeu_siam.dir/build.make CMakeFiles/jeu_siam.dir/api_siam.c.o.provides.build
.PHONY : CMakeFiles/jeu_siam.dir/api_siam.c.o.provides

CMakeFiles/jeu_siam.dir/api_siam.c.o.provides.build: CMakeFiles/jeu_siam.dir/api_siam.c.o

CMakeFiles/jeu_siam.dir/main.c.o: CMakeFiles/jeu_siam.dir/flags.make
CMakeFiles/jeu_siam.dir/main.c.o: /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/main.c
	$(CMAKE_COMMAND) -E cmake_progress_report /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/bin/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/jeu_siam.dir/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/jeu_siam.dir/main.c.o   -c /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/main.c

CMakeFiles/jeu_siam.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/jeu_siam.dir/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/main.c > CMakeFiles/jeu_siam.dir/main.c.i

CMakeFiles/jeu_siam.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/jeu_siam.dir/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/main.c -o CMakeFiles/jeu_siam.dir/main.c.s

CMakeFiles/jeu_siam.dir/main.c.o.requires:
.PHONY : CMakeFiles/jeu_siam.dir/main.c.o.requires

CMakeFiles/jeu_siam.dir/main.c.o.provides: CMakeFiles/jeu_siam.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/jeu_siam.dir/build.make CMakeFiles/jeu_siam.dir/main.c.o.provides.build
.PHONY : CMakeFiles/jeu_siam.dir/main.c.o.provides

CMakeFiles/jeu_siam.dir/main.c.o.provides.build: CMakeFiles/jeu_siam.dir/main.c.o

CMakeFiles/jeu_siam.dir/piece_siam.c.o: CMakeFiles/jeu_siam.dir/flags.make
CMakeFiles/jeu_siam.dir/piece_siam.c.o: /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/piece_siam.c
	$(CMAKE_COMMAND) -E cmake_progress_report /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/bin/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/jeu_siam.dir/piece_siam.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/jeu_siam.dir/piece_siam.c.o   -c /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/piece_siam.c

CMakeFiles/jeu_siam.dir/piece_siam.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/jeu_siam.dir/piece_siam.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/piece_siam.c > CMakeFiles/jeu_siam.dir/piece_siam.c.i

CMakeFiles/jeu_siam.dir/piece_siam.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/jeu_siam.dir/piece_siam.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/piece_siam.c -o CMakeFiles/jeu_siam.dir/piece_siam.c.s

CMakeFiles/jeu_siam.dir/piece_siam.c.o.requires:
.PHONY : CMakeFiles/jeu_siam.dir/piece_siam.c.o.requires

CMakeFiles/jeu_siam.dir/piece_siam.c.o.provides: CMakeFiles/jeu_siam.dir/piece_siam.c.o.requires
	$(MAKE) -f CMakeFiles/jeu_siam.dir/build.make CMakeFiles/jeu_siam.dir/piece_siam.c.o.provides.build
.PHONY : CMakeFiles/jeu_siam.dir/piece_siam.c.o.provides

CMakeFiles/jeu_siam.dir/piece_siam.c.o.provides.build: CMakeFiles/jeu_siam.dir/piece_siam.c.o

CMakeFiles/jeu_siam.dir/condition_victoire_partie.c.o: CMakeFiles/jeu_siam.dir/flags.make
CMakeFiles/jeu_siam.dir/condition_victoire_partie.c.o: /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/condition_victoire_partie.c
	$(CMAKE_COMMAND) -E cmake_progress_report /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/bin/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/jeu_siam.dir/condition_victoire_partie.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/jeu_siam.dir/condition_victoire_partie.c.o   -c /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/condition_victoire_partie.c

CMakeFiles/jeu_siam.dir/condition_victoire_partie.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/jeu_siam.dir/condition_victoire_partie.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/condition_victoire_partie.c > CMakeFiles/jeu_siam.dir/condition_victoire_partie.c.i

CMakeFiles/jeu_siam.dir/condition_victoire_partie.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/jeu_siam.dir/condition_victoire_partie.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/condition_victoire_partie.c -o CMakeFiles/jeu_siam.dir/condition_victoire_partie.c.s

CMakeFiles/jeu_siam.dir/condition_victoire_partie.c.o.requires:
.PHONY : CMakeFiles/jeu_siam.dir/condition_victoire_partie.c.o.requires

CMakeFiles/jeu_siam.dir/condition_victoire_partie.c.o.provides: CMakeFiles/jeu_siam.dir/condition_victoire_partie.c.o.requires
	$(MAKE) -f CMakeFiles/jeu_siam.dir/build.make CMakeFiles/jeu_siam.dir/condition_victoire_partie.c.o.provides.build
.PHONY : CMakeFiles/jeu_siam.dir/condition_victoire_partie.c.o.provides

CMakeFiles/jeu_siam.dir/condition_victoire_partie.c.o.provides.build: CMakeFiles/jeu_siam.dir/condition_victoire_partie.c.o

CMakeFiles/jeu_siam.dir/jeu_siam.c.o: CMakeFiles/jeu_siam.dir/flags.make
CMakeFiles/jeu_siam.dir/jeu_siam.c.o: /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/jeu_siam.c
	$(CMAKE_COMMAND) -E cmake_progress_report /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/bin/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/jeu_siam.dir/jeu_siam.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/jeu_siam.dir/jeu_siam.c.o   -c /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/jeu_siam.c

CMakeFiles/jeu_siam.dir/jeu_siam.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/jeu_siam.dir/jeu_siam.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/jeu_siam.c > CMakeFiles/jeu_siam.dir/jeu_siam.c.i

CMakeFiles/jeu_siam.dir/jeu_siam.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/jeu_siam.dir/jeu_siam.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/jeu_siam.c -o CMakeFiles/jeu_siam.dir/jeu_siam.c.s

CMakeFiles/jeu_siam.dir/jeu_siam.c.o.requires:
.PHONY : CMakeFiles/jeu_siam.dir/jeu_siam.c.o.requires

CMakeFiles/jeu_siam.dir/jeu_siam.c.o.provides: CMakeFiles/jeu_siam.dir/jeu_siam.c.o.requires
	$(MAKE) -f CMakeFiles/jeu_siam.dir/build.make CMakeFiles/jeu_siam.dir/jeu_siam.c.o.provides.build
.PHONY : CMakeFiles/jeu_siam.dir/jeu_siam.c.o.provides

CMakeFiles/jeu_siam.dir/jeu_siam.c.o.provides.build: CMakeFiles/jeu_siam.dir/jeu_siam.c.o

CMakeFiles/jeu_siam.dir/parseur_mode_interactif.c.o: CMakeFiles/jeu_siam.dir/flags.make
CMakeFiles/jeu_siam.dir/parseur_mode_interactif.c.o: /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/parseur_mode_interactif.c
	$(CMAKE_COMMAND) -E cmake_progress_report /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/bin/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/jeu_siam.dir/parseur_mode_interactif.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/jeu_siam.dir/parseur_mode_interactif.c.o   -c /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/parseur_mode_interactif.c

CMakeFiles/jeu_siam.dir/parseur_mode_interactif.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/jeu_siam.dir/parseur_mode_interactif.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/parseur_mode_interactif.c > CMakeFiles/jeu_siam.dir/parseur_mode_interactif.c.i

CMakeFiles/jeu_siam.dir/parseur_mode_interactif.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/jeu_siam.dir/parseur_mode_interactif.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/parseur_mode_interactif.c -o CMakeFiles/jeu_siam.dir/parseur_mode_interactif.c.s

CMakeFiles/jeu_siam.dir/parseur_mode_interactif.c.o.requires:
.PHONY : CMakeFiles/jeu_siam.dir/parseur_mode_interactif.c.o.requires

CMakeFiles/jeu_siam.dir/parseur_mode_interactif.c.o.provides: CMakeFiles/jeu_siam.dir/parseur_mode_interactif.c.o.requires
	$(MAKE) -f CMakeFiles/jeu_siam.dir/build.make CMakeFiles/jeu_siam.dir/parseur_mode_interactif.c.o.provides.build
.PHONY : CMakeFiles/jeu_siam.dir/parseur_mode_interactif.c.o.provides

CMakeFiles/jeu_siam.dir/parseur_mode_interactif.c.o.provides.build: CMakeFiles/jeu_siam.dir/parseur_mode_interactif.c.o

CMakeFiles/jeu_siam.dir/plateau_siam.c.o: CMakeFiles/jeu_siam.dir/flags.make
CMakeFiles/jeu_siam.dir/plateau_siam.c.o: /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/plateau_siam.c
	$(CMAKE_COMMAND) -E cmake_progress_report /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/bin/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/jeu_siam.dir/plateau_siam.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/jeu_siam.dir/plateau_siam.c.o   -c /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/plateau_siam.c

CMakeFiles/jeu_siam.dir/plateau_siam.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/jeu_siam.dir/plateau_siam.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/plateau_siam.c > CMakeFiles/jeu_siam.dir/plateau_siam.c.i

CMakeFiles/jeu_siam.dir/plateau_siam.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/jeu_siam.dir/plateau_siam.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/plateau_siam.c -o CMakeFiles/jeu_siam.dir/plateau_siam.c.s

CMakeFiles/jeu_siam.dir/plateau_siam.c.o.requires:
.PHONY : CMakeFiles/jeu_siam.dir/plateau_siam.c.o.requires

CMakeFiles/jeu_siam.dir/plateau_siam.c.o.provides: CMakeFiles/jeu_siam.dir/plateau_siam.c.o.requires
	$(MAKE) -f CMakeFiles/jeu_siam.dir/build.make CMakeFiles/jeu_siam.dir/plateau_siam.c.o.provides.build
.PHONY : CMakeFiles/jeu_siam.dir/plateau_siam.c.o.provides

CMakeFiles/jeu_siam.dir/plateau_siam.c.o.provides.build: CMakeFiles/jeu_siam.dir/plateau_siam.c.o

CMakeFiles/jeu_siam.dir/type_piece.c.o: CMakeFiles/jeu_siam.dir/flags.make
CMakeFiles/jeu_siam.dir/type_piece.c.o: /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/type_piece.c
	$(CMAKE_COMMAND) -E cmake_progress_report /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/bin/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/jeu_siam.dir/type_piece.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/jeu_siam.dir/type_piece.c.o   -c /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/type_piece.c

CMakeFiles/jeu_siam.dir/type_piece.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/jeu_siam.dir/type_piece.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/type_piece.c > CMakeFiles/jeu_siam.dir/type_piece.c.i

CMakeFiles/jeu_siam.dir/type_piece.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/jeu_siam.dir/type_piece.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/type_piece.c -o CMakeFiles/jeu_siam.dir/type_piece.c.s

CMakeFiles/jeu_siam.dir/type_piece.c.o.requires:
.PHONY : CMakeFiles/jeu_siam.dir/type_piece.c.o.requires

CMakeFiles/jeu_siam.dir/type_piece.c.o.provides: CMakeFiles/jeu_siam.dir/type_piece.c.o.requires
	$(MAKE) -f CMakeFiles/jeu_siam.dir/build.make CMakeFiles/jeu_siam.dir/type_piece.c.o.provides.build
.PHONY : CMakeFiles/jeu_siam.dir/type_piece.c.o.provides

CMakeFiles/jeu_siam.dir/type_piece.c.o.provides.build: CMakeFiles/jeu_siam.dir/type_piece.c.o

CMakeFiles/jeu_siam.dir/mode_interactif.c.o: CMakeFiles/jeu_siam.dir/flags.make
CMakeFiles/jeu_siam.dir/mode_interactif.c.o: /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/mode_interactif.c
	$(CMAKE_COMMAND) -E cmake_progress_report /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/bin/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/jeu_siam.dir/mode_interactif.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/jeu_siam.dir/mode_interactif.c.o   -c /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/mode_interactif.c

CMakeFiles/jeu_siam.dir/mode_interactif.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/jeu_siam.dir/mode_interactif.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/mode_interactif.c > CMakeFiles/jeu_siam.dir/mode_interactif.c.i

CMakeFiles/jeu_siam.dir/mode_interactif.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/jeu_siam.dir/mode_interactif.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/mode_interactif.c -o CMakeFiles/jeu_siam.dir/mode_interactif.c.s

CMakeFiles/jeu_siam.dir/mode_interactif.c.o.requires:
.PHONY : CMakeFiles/jeu_siam.dir/mode_interactif.c.o.requires

CMakeFiles/jeu_siam.dir/mode_interactif.c.o.provides: CMakeFiles/jeu_siam.dir/mode_interactif.c.o.requires
	$(MAKE) -f CMakeFiles/jeu_siam.dir/build.make CMakeFiles/jeu_siam.dir/mode_interactif.c.o.provides.build
.PHONY : CMakeFiles/jeu_siam.dir/mode_interactif.c.o.provides

CMakeFiles/jeu_siam.dir/mode_interactif.c.o.provides.build: CMakeFiles/jeu_siam.dir/mode_interactif.c.o

CMakeFiles/jeu_siam.dir/joueur.c.o: CMakeFiles/jeu_siam.dir/flags.make
CMakeFiles/jeu_siam.dir/joueur.c.o: /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/joueur.c
	$(CMAKE_COMMAND) -E cmake_progress_report /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/bin/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/jeu_siam.dir/joueur.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/jeu_siam.dir/joueur.c.o   -c /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/joueur.c

CMakeFiles/jeu_siam.dir/joueur.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/jeu_siam.dir/joueur.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/joueur.c > CMakeFiles/jeu_siam.dir/joueur.c.i

CMakeFiles/jeu_siam.dir/joueur.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/jeu_siam.dir/joueur.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/joueur.c -o CMakeFiles/jeu_siam.dir/joueur.c.s

CMakeFiles/jeu_siam.dir/joueur.c.o.requires:
.PHONY : CMakeFiles/jeu_siam.dir/joueur.c.o.requires

CMakeFiles/jeu_siam.dir/joueur.c.o.provides: CMakeFiles/jeu_siam.dir/joueur.c.o.requires
	$(MAKE) -f CMakeFiles/jeu_siam.dir/build.make CMakeFiles/jeu_siam.dir/joueur.c.o.provides.build
.PHONY : CMakeFiles/jeu_siam.dir/joueur.c.o.provides

CMakeFiles/jeu_siam.dir/joueur.c.o.provides.build: CMakeFiles/jeu_siam.dir/joueur.c.o

CMakeFiles/jeu_siam.dir/plateau_modification.c.o: CMakeFiles/jeu_siam.dir/flags.make
CMakeFiles/jeu_siam.dir/plateau_modification.c.o: /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/plateau_modification.c
	$(CMAKE_COMMAND) -E cmake_progress_report /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/bin/CMakeFiles $(CMAKE_PROGRESS_12)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/jeu_siam.dir/plateau_modification.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/jeu_siam.dir/plateau_modification.c.o   -c /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/plateau_modification.c

CMakeFiles/jeu_siam.dir/plateau_modification.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/jeu_siam.dir/plateau_modification.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/plateau_modification.c > CMakeFiles/jeu_siam.dir/plateau_modification.c.i

CMakeFiles/jeu_siam.dir/plateau_modification.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/jeu_siam.dir/plateau_modification.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/plateau_modification.c -o CMakeFiles/jeu_siam.dir/plateau_modification.c.s

CMakeFiles/jeu_siam.dir/plateau_modification.c.o.requires:
.PHONY : CMakeFiles/jeu_siam.dir/plateau_modification.c.o.requires

CMakeFiles/jeu_siam.dir/plateau_modification.c.o.provides: CMakeFiles/jeu_siam.dir/plateau_modification.c.o.requires
	$(MAKE) -f CMakeFiles/jeu_siam.dir/build.make CMakeFiles/jeu_siam.dir/plateau_modification.c.o.provides.build
.PHONY : CMakeFiles/jeu_siam.dir/plateau_modification.c.o.provides

CMakeFiles/jeu_siam.dir/plateau_modification.c.o.provides.build: CMakeFiles/jeu_siam.dir/plateau_modification.c.o

CMakeFiles/jeu_siam.dir/orientation_deplacement.c.o: CMakeFiles/jeu_siam.dir/flags.make
CMakeFiles/jeu_siam.dir/orientation_deplacement.c.o: /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/orientation_deplacement.c
	$(CMAKE_COMMAND) -E cmake_progress_report /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/bin/CMakeFiles $(CMAKE_PROGRESS_13)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/jeu_siam.dir/orientation_deplacement.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/jeu_siam.dir/orientation_deplacement.c.o   -c /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/orientation_deplacement.c

CMakeFiles/jeu_siam.dir/orientation_deplacement.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/jeu_siam.dir/orientation_deplacement.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/orientation_deplacement.c > CMakeFiles/jeu_siam.dir/orientation_deplacement.c.i

CMakeFiles/jeu_siam.dir/orientation_deplacement.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/jeu_siam.dir/orientation_deplacement.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/orientation_deplacement.c -o CMakeFiles/jeu_siam.dir/orientation_deplacement.c.s

CMakeFiles/jeu_siam.dir/orientation_deplacement.c.o.requires:
.PHONY : CMakeFiles/jeu_siam.dir/orientation_deplacement.c.o.requires

CMakeFiles/jeu_siam.dir/orientation_deplacement.c.o.provides: CMakeFiles/jeu_siam.dir/orientation_deplacement.c.o.requires
	$(MAKE) -f CMakeFiles/jeu_siam.dir/build.make CMakeFiles/jeu_siam.dir/orientation_deplacement.c.o.provides.build
.PHONY : CMakeFiles/jeu_siam.dir/orientation_deplacement.c.o.provides

CMakeFiles/jeu_siam.dir/orientation_deplacement.c.o.provides.build: CMakeFiles/jeu_siam.dir/orientation_deplacement.c.o

CMakeFiles/jeu_siam.dir/entree_sortie.c.o: CMakeFiles/jeu_siam.dir/flags.make
CMakeFiles/jeu_siam.dir/entree_sortie.c.o: /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/entree_sortie.c
	$(CMAKE_COMMAND) -E cmake_progress_report /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/bin/CMakeFiles $(CMAKE_PROGRESS_14)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/jeu_siam.dir/entree_sortie.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/jeu_siam.dir/entree_sortie.c.o   -c /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/entree_sortie.c

CMakeFiles/jeu_siam.dir/entree_sortie.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/jeu_siam.dir/entree_sortie.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/entree_sortie.c > CMakeFiles/jeu_siam.dir/entree_sortie.c.i

CMakeFiles/jeu_siam.dir/entree_sortie.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/jeu_siam.dir/entree_sortie.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/entree_sortie.c -o CMakeFiles/jeu_siam.dir/entree_sortie.c.s

CMakeFiles/jeu_siam.dir/entree_sortie.c.o.requires:
.PHONY : CMakeFiles/jeu_siam.dir/entree_sortie.c.o.requires

CMakeFiles/jeu_siam.dir/entree_sortie.c.o.provides: CMakeFiles/jeu_siam.dir/entree_sortie.c.o.requires
	$(MAKE) -f CMakeFiles/jeu_siam.dir/build.make CMakeFiles/jeu_siam.dir/entree_sortie.c.o.provides.build
.PHONY : CMakeFiles/jeu_siam.dir/entree_sortie.c.o.provides

CMakeFiles/jeu_siam.dir/entree_sortie.c.o.provides.build: CMakeFiles/jeu_siam.dir/entree_sortie.c.o

CMakeFiles/jeu_siam.dir/coordonnees_plateau.c.o: CMakeFiles/jeu_siam.dir/flags.make
CMakeFiles/jeu_siam.dir/coordonnees_plateau.c.o: /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/coordonnees_plateau.c
	$(CMAKE_COMMAND) -E cmake_progress_report /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/bin/CMakeFiles $(CMAKE_PROGRESS_15)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/jeu_siam.dir/coordonnees_plateau.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/jeu_siam.dir/coordonnees_plateau.c.o   -c /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/coordonnees_plateau.c

CMakeFiles/jeu_siam.dir/coordonnees_plateau.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/jeu_siam.dir/coordonnees_plateau.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/coordonnees_plateau.c > CMakeFiles/jeu_siam.dir/coordonnees_plateau.c.i

CMakeFiles/jeu_siam.dir/coordonnees_plateau.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/jeu_siam.dir/coordonnees_plateau.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src/coordonnees_plateau.c -o CMakeFiles/jeu_siam.dir/coordonnees_plateau.c.s

CMakeFiles/jeu_siam.dir/coordonnees_plateau.c.o.requires:
.PHONY : CMakeFiles/jeu_siam.dir/coordonnees_plateau.c.o.requires

CMakeFiles/jeu_siam.dir/coordonnees_plateau.c.o.provides: CMakeFiles/jeu_siam.dir/coordonnees_plateau.c.o.requires
	$(MAKE) -f CMakeFiles/jeu_siam.dir/build.make CMakeFiles/jeu_siam.dir/coordonnees_plateau.c.o.provides.build
.PHONY : CMakeFiles/jeu_siam.dir/coordonnees_plateau.c.o.provides

CMakeFiles/jeu_siam.dir/coordonnees_plateau.c.o.provides.build: CMakeFiles/jeu_siam.dir/coordonnees_plateau.c.o

# Object files for target jeu_siam
jeu_siam_OBJECTS = \
"CMakeFiles/jeu_siam.dir/coup_jeu.c.o" \
"CMakeFiles/jeu_siam.dir/api_siam.c.o" \
"CMakeFiles/jeu_siam.dir/main.c.o" \
"CMakeFiles/jeu_siam.dir/piece_siam.c.o" \
"CMakeFiles/jeu_siam.dir/condition_victoire_partie.c.o" \
"CMakeFiles/jeu_siam.dir/jeu_siam.c.o" \
"CMakeFiles/jeu_siam.dir/parseur_mode_interactif.c.o" \
"CMakeFiles/jeu_siam.dir/plateau_siam.c.o" \
"CMakeFiles/jeu_siam.dir/type_piece.c.o" \
"CMakeFiles/jeu_siam.dir/mode_interactif.c.o" \
"CMakeFiles/jeu_siam.dir/joueur.c.o" \
"CMakeFiles/jeu_siam.dir/plateau_modification.c.o" \
"CMakeFiles/jeu_siam.dir/orientation_deplacement.c.o" \
"CMakeFiles/jeu_siam.dir/entree_sortie.c.o" \
"CMakeFiles/jeu_siam.dir/coordonnees_plateau.c.o"

# External object files for target jeu_siam
jeu_siam_EXTERNAL_OBJECTS =

jeu_siam: CMakeFiles/jeu_siam.dir/coup_jeu.c.o
jeu_siam: CMakeFiles/jeu_siam.dir/api_siam.c.o
jeu_siam: CMakeFiles/jeu_siam.dir/main.c.o
jeu_siam: CMakeFiles/jeu_siam.dir/piece_siam.c.o
jeu_siam: CMakeFiles/jeu_siam.dir/condition_victoire_partie.c.o
jeu_siam: CMakeFiles/jeu_siam.dir/jeu_siam.c.o
jeu_siam: CMakeFiles/jeu_siam.dir/parseur_mode_interactif.c.o
jeu_siam: CMakeFiles/jeu_siam.dir/plateau_siam.c.o
jeu_siam: CMakeFiles/jeu_siam.dir/type_piece.c.o
jeu_siam: CMakeFiles/jeu_siam.dir/mode_interactif.c.o
jeu_siam: CMakeFiles/jeu_siam.dir/joueur.c.o
jeu_siam: CMakeFiles/jeu_siam.dir/plateau_modification.c.o
jeu_siam: CMakeFiles/jeu_siam.dir/orientation_deplacement.c.o
jeu_siam: CMakeFiles/jeu_siam.dir/entree_sortie.c.o
jeu_siam: CMakeFiles/jeu_siam.dir/coordonnees_plateau.c.o
jeu_siam: CMakeFiles/jeu_siam.dir/build.make
jeu_siam: CMakeFiles/jeu_siam.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable jeu_siam"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/jeu_siam.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/jeu_siam.dir/build: jeu_siam
.PHONY : CMakeFiles/jeu_siam.dir/build

CMakeFiles/jeu_siam.dir/requires: CMakeFiles/jeu_siam.dir/coup_jeu.c.o.requires
CMakeFiles/jeu_siam.dir/requires: CMakeFiles/jeu_siam.dir/api_siam.c.o.requires
CMakeFiles/jeu_siam.dir/requires: CMakeFiles/jeu_siam.dir/main.c.o.requires
CMakeFiles/jeu_siam.dir/requires: CMakeFiles/jeu_siam.dir/piece_siam.c.o.requires
CMakeFiles/jeu_siam.dir/requires: CMakeFiles/jeu_siam.dir/condition_victoire_partie.c.o.requires
CMakeFiles/jeu_siam.dir/requires: CMakeFiles/jeu_siam.dir/jeu_siam.c.o.requires
CMakeFiles/jeu_siam.dir/requires: CMakeFiles/jeu_siam.dir/parseur_mode_interactif.c.o.requires
CMakeFiles/jeu_siam.dir/requires: CMakeFiles/jeu_siam.dir/plateau_siam.c.o.requires
CMakeFiles/jeu_siam.dir/requires: CMakeFiles/jeu_siam.dir/type_piece.c.o.requires
CMakeFiles/jeu_siam.dir/requires: CMakeFiles/jeu_siam.dir/mode_interactif.c.o.requires
CMakeFiles/jeu_siam.dir/requires: CMakeFiles/jeu_siam.dir/joueur.c.o.requires
CMakeFiles/jeu_siam.dir/requires: CMakeFiles/jeu_siam.dir/plateau_modification.c.o.requires
CMakeFiles/jeu_siam.dir/requires: CMakeFiles/jeu_siam.dir/orientation_deplacement.c.o.requires
CMakeFiles/jeu_siam.dir/requires: CMakeFiles/jeu_siam.dir/entree_sortie.c.o.requires
CMakeFiles/jeu_siam.dir/requires: CMakeFiles/jeu_siam.dir/coordonnees_plateau.c.o.requires
.PHONY : CMakeFiles/jeu_siam.dir/requires

CMakeFiles/jeu_siam.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/jeu_siam.dir/cmake_clean.cmake
.PHONY : CMakeFiles/jeu_siam.dir/clean

CMakeFiles/jeu_siam.dir/depend:
	cd /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/src /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/bin /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/bin /share/users/manon.cadart/home/Documents/TP_INFO/CSC2/Blain_Cadart_projet_siam/bin/CMakeFiles/jeu_siam.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/jeu_siam.dir/depend

