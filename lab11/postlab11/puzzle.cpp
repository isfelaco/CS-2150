#include "puzzle.h"
#include <iostream>
#include <string>
using namespace std;

/**
 * hash table
 * 
 * map the strings onto the distances from the start node you calculated
 * index 0 is going to be the start state
 * if it's a brand new string, calculate the distance and put it in the hash table
 * if it's in the hash table, ignore it and move on
 * 
 */


Puzzle::Puzzle() {
	iterations = -1;
	cases = vector<vector<string>>(50);
}
vector<string> Puzzle::generateNeighbors(string cur) {
	int index = 0;
	for (int i = 0; i < cur.length(); i++) {
		if (cur[i] == '0') {
			index = (int)i;
		}
	}
	string case1, case2, case3, case4;
	switch(index) {
		case 0:		// 1, 3
			case1 = swap(cur,index,1);
			case2 = swap(cur,index,3);
			break;
		case 1:		// 0, 2, 4
			case1 = swap(cur,index,0);
			case2 = swap(cur,index,2);
			case3 = swap(cur,index,4);
			break;
		case 2:		// 1, 5
			case1 = swap(cur,index,1);
			case2 = swap(cur,index,5);
			break;
		case 3:		// 0, 4, or 6
			case1 = swap(cur,index,0);
			case2 = swap(cur,index,4);
			case3 = swap(cur,index,6);
			break;
		case 4:		// 1, 3, 5, 7
			case1 = swap(cur,index,1);
			case2 = swap(cur,index,3);
			case3 = swap(cur,index,5);
			case4 = swap(cur,index,7);
			break;
		case 5:		// 2, 4, 8
			case1 = swap(cur,index,2);
			case2 = swap(cur,index,4);
			case3 = swap(cur,index,8);
			break;
		case 6:		// 3, 7
			case1 = swap(cur,index,3);
			case2 = swap(cur,index,7);
			break;
		case 7:		// 4, 6, 8
			case1 = swap(cur,index,4);
			case2 = swap(cur,index,6);
			case3 = swap(cur,index,8);
			break;
		case 8:		// 5, 7
			case1 = swap(cur,index,5);
			case2 = swap(cur,index,7);
			break;
	}
	string cases[4] = {case1, case2, case3, case4};
	vector<string> neighbors;
	for (int i = 0; i < 4; i++) {
		if (cases[i] != "") {
			neighbors.push_back(cases[i]);
		}
	}
	return neighbors;
}

string Puzzle::swap(string cur, int zero, int target) {
	cur[zero] = cur[target];
	cur[target] = '0';
	return cur;
}

bool Puzzle::checkCorrect(string cur) {
	if (cur == "123456780") {
		return true;
	}
	return false;
}

int Puzzle::solve(string cur, int steps) {
	




	// cases[steps].push_back(cur);
	// if (checkCorrect(cur)) {
	// 	cout << cur << endl;
	// }
	// else {
	// 	string* n;
	// 	n = generateNeighbors(cur);
	// 	steps++;

	// 	for (int i = 0; i < 4; i++) {
	// 		cout << n[i] << endl;
	// 		if (checkCorrect(n[i])) {
	// 			cases[steps].push_back(cur);
	// 			break;
	// 		}
	// 		else if (n[i] != cur && !find(n[i])) {
	// 			cout << "here 2" << endl;
	// 			solve(n[i], steps);
	// 		}
	// 	}
	// }
	
	return steps;
}

// void Graph::unweighted(Vertex s) {
// 	Queue q(NUM_VERTICES);
// 	Vertex v,w;
// 	q.enqueue(s);
// 	s.dist = 0;
	
// 	while (!q.isEmpty()) {
// 		v = q.dequeue();
// 		for each w adjacent to v
// 			// each edge examined at most once, if adjacency lists are used
// 			if (w.dist == INFINITY) {
// 				w.dist = v.dist + 1;
// 				w.path = v;
// 				q.enqueue(w); // each vertex added at most once
// 			}
		
// 	}
// }



bool Puzzle::find(string cur) {
	for (auto x : cases) {
		for (auto y : x) {
			if (y == cur) {
				return true;
			}
		}
	}
	return false;
}