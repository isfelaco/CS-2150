#MakeFile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g

postlab5: AVLNode.o AVLTree.o AVLPathTest.o
	$(CXX) $(DEBUG) -o postlab5 AVLNode.o AVLTree.o AVLPathTest.o
	@echo "Makefile"

AVLNode.o: AVLNode.cpp AVLNode.h

AVLTree.o: AVLTree.cpp AVLTree.h

AVLTest.o: AVLPathTest.cpp

.PHONY: clean
clean:
	-rm -f *.o postlab5