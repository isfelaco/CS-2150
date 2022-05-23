#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include <vector>
using namespace std;

class Puzzle {
public:
	Puzzle();
	vector<string> generateNeighbors(string cur);
	bool checkCorrect(string cur);
	string swap(string cur, int zero, int target);
	int solve(string cur, int steps);
	bool find(string cur);
private:
	int iterations;
	vector<vector<string>> cases;
};

#endif