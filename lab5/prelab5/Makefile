#MakeFile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g

inlab5: BinaryNode.o BinarySearchTree.o BSTPathTest.o
	$(CXX) $(DEBUG) -o inlab5 BinaryNode.o BinarySearchTree.o BSTPathTest.o
	@echo "Makefile"

BinaryNode.o: BinaryNode.cpp BinaryNode.h

BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h

BSTPathTest.o: BSTPathTest.cpp

.PHONY: clean
clean:
	-rm -f *.o inlab5