# The compiler to use
CC = g++
# The compiler flags to use
CPPFLAGS = -pedantic -std=c++14 -Wall -Wextra -Wshadow -O2

# the name of the outputed executable binary
EXENAME = main
# the directory to output objects to. (use  .  for current dir)
OUTDIR = bin

# the main.cpp file
MAIN = main.cpp

# get all the other .cpp files to compile (don't need touch)
SOURCES	= $(filter-out $(MAIN), $(wildcard *.cpp))
# create .o files from .cpp files (don't need to touch)
OBJECTS = $(SOURCES:%.cpp=$(OUTDIR)/%.o)

# where the executable outputs to (don't need to touch)
EXE = $(OUTDIR)/$(EXENAME)

# default (make) compile all and run the program. (remove 'run' if you don't want it to run)
all: $(EXE) run

# compile the executable with the object files
$(EXE): $(OBJECTS) $(MAIN)
	$(CC) $(CPPFLAGS) -o $@ $^

# compile all the object files
$(OUTDIR)/%.o: %.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

# run the exe
run:
	$(EXE)

# purge all the things
clean:
	rm -rf $(OBJECTS) $(EXE)
