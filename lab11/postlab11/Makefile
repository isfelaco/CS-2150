#Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2
# DEBUG=-g

lab11: puzzleSolver.o
	$(CXX) $(DEBUG) puzzleSolver.o
	@echo
	@doxygen

puzzleSolver.o : puzzleSolver.cpp

.PHONY: clean
clean:
	-rm -f *.o lab11