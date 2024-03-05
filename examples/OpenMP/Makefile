# Define the C++ compiler to use
CXX = g++

# Define any compile-time flags
CXXFLAGS = -std=c++14 -fopenmp -Wall -Wextra -pedantic -Wno-unused-parameter

# Define the C++ source files
SOURCES = $(wildcard *.cc)

# Define the C++ object files
OBJECTS = $(SOURCES:.cc=.o)

# Define the executable file 
EXECUTABLES = $(SOURCES:.cc=)

.PHONY: all clean

all: $(EXECUTABLES)

%: %.o
	$(CXX) $(CXXFLAGS) $< -o $@

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) *.o *~ $(EXECUTABLES)