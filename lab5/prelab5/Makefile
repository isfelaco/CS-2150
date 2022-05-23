#MakeFile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g

lab5: TreeCalc.o TreeNode.o TreeCalcTest.o
	$(CXX) $(DEBUG) TreeCalc.o TreeNode.o TreeCalcTest.o
	@echo "Makefile"

TreeCalc.o: TreeCalc.cpp TreeCalc.h

TreeNode.o: TreeNode.cpp TreeNode.h

TreeCalcTest.o: TreeCalcTest.cpp

.PHONY: clean
clean:
	-rm -f *.o lab5
