#Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g

lab7: counter.o timer.o
	$(CXX) $(DEBUG) counter.o timer.o
	@echo

counter.o : counter.cpp
timer.o : timer.h timer.cpp

.PHONY: clean
clean:
	-rm -f *.o lab7