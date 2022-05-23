#Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g

lab6: wordPuzzle.o timer.o HashTable.o
	$(CXX) $(DEBUG) wordPuzzle.o timer.o HashTable.o
	@echo

wordPuzzle.o : wordPuzzle.cpp
timer.o : timer.h timer.cpp
HashTable.o : HashTable.h HashTable.cpp

.PHONY: clean
clean:
	-rm -f *.o lab6