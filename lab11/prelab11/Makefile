#Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g

lab11: topological.o middleearth.o
	$(CXX) $(DEBUG) topological.o middleearth.o
	@echo
	@doxygen

topological.o : topological.cpp
middleearth.o : middleearth.h middleearth.cpp

.PHONY: clean
clean:
	-rm -f *.o lab11