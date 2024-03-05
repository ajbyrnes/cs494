# Define the C++ compiler to use
CXX = g++

# Define any compile-time flags
CXXFLAGS = -std=c++14 -Wall -Wextra -pedantic -Wno-unused-parameter

# Define the C++ source files
SOURCES = prime.cc

# Define the C++ object files
OBJECTS = $(SOURCES:.cc=.o)

# Define the executable file 
MAIN = prime

.PHONY: all clean

all: $(MAIN)
	@echo Congratulations $(MAIN) has been compiled!

$(MAIN): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(MAIN) $(OBJECTS)

.cc.o:
	$(CXX) $(CXXFLAGS) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)