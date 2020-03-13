

# Makefile for the Game of Life
# Assumes the following directory hierarchy:
# Assignment 02
# 	src
#       include

#this Makefile goes in the CPSC350-Game-of-Life directory


EXECUTABLE := assignment2

# the source files to be built
SOURCES := GameOfLifeMain.cpp

#stuff you don't need to worry about
INCLUDES := -I ../include
EXT := exe
CC := g++

all:
	$(CC) $(INCLUDES) $(SOURCES) -o $(EXECUTABLE).$(EXT)

#find these .o, .exec files and delete them before running the program, edit this part according to what files i have in folder
realclean:
	find . -type f -name "*.o" -exec rm '{}' \;
	find . -type f -name "*.exe" -exec rm '{}' \;
	find . -type f -name "*.out" -exec rm '{}' \;
	find . -type f -name "*.gch" -exec rm '{}' \;

# this line required by make - don't delete
