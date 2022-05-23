#Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2# Enable all warnings
DEBUG=-g

lab11: travelling.o middleearth.o
	$(CXX) $(DEBUG) travelling.o middleearth.o
	@echo
	@doxygen

travelling.o : travelling.cpp
middleearth.o : middleearth.h middleearth.cpp

.PHONY: clean
clean:
	-rm -f *.o lab11