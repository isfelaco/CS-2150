# Makefile for CS 2150 pre-lab 10

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g

lab10: huffmanenc.o heap.o
	$(CXX) $(DEBUG) huffmanenc.o heap.o

huffmanenc.o : huffmanenc.cpp
heap.o : heap.h heap.cpp

.PHONY: clean
clean:
	-rm -f *.o lab10
