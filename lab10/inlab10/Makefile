# Makefile for CS 2150 in-lab 10

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g

lab10: huffmandec.o
	$(CXX) $(DEBUG) huffmandec.o

huffmandec.o : huffmandec.cpp

.PHONY: clean
clean:
	-rm -f ~.o lab10