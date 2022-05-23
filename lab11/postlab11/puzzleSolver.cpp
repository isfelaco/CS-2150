#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct node {
	string value;
	int distance;
	node(string v, int d);
};
/**
 * @brief Generates permutations of the current layout
 * 
 * This method takes in a puzzle node and returns all the possible next configurations based on where the empty space is.
 * 
 * @param cur Current state of the puzzle
 * @return Vector of possible next state nodes
 * 
 * @note Implements the swap method
 */
vector<node*> generateNeighbors(node* cur);
/**
 * @brief Swap two positions in a puzzle
 * 
 * This method takes in a string layout of the puzzle and swaps a position into the empty place
 * 
 * @param cur Current state of the puzzle
 * @param zero Index where the empty space is
 * @param target The index to swap the empty space with
 * 
 * @note Used solely in the generateNeighbors() method
 */
node* swap(node* cur, int zero, int target);
/**
 * @brief Solves the puzzle
 * 
 * This method takes in the starting puzzle and determines if there's a solution or if it is impossible to solve
 * 
 * @param cur Current state of the puzzle
 * 
 * @note Drives the main() method
 */
void solve(node* cur);


int main() {
	cout << "Enter puzzle" << endl;

	string temp;
	string s = "";
	while (s.length() < 9) {
		cin >> temp;
		s += temp;
	}
	node* cur = new node(s,0);
	solve(cur);

	return 0;
}

void solve(node* cur) {
	cout << "Solving puzzle" << endl;

	unordered_map<string, int> table;

	queue<node*> q;
	node* v;

	if (cur->value == "123456780") {
		cout << cur->distance << endl;
		return;
	}
	// table.insert(make_pair(cur->value,cur->distance));
	table[cur->value] = cur->distance;		// insert into table so its seen
	q.push(cur);

	while (!q.empty()) {
		v = q.front();
		q.pop();
		for (auto w : generateNeighbors(v)) {
			if (w->value == "123456780") {
				cout << w->distance << endl;
				return;
			}
			if (table.find(w->value) == table.end()) {		// if w is not in the table already
				//table.find(w->value) != table.end()
				//table[w->value] != w->distance
				w->distance = v->distance + 1;
				// table.insert(make_pair(w->value,w->distance));
				table[w->value] = w->distance;
				q.push(w);		// puts w in the queue
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
	return;
}

vector<node*> generateNeighbors(node* cur) {
	int index = 0;
	string s = cur->value;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0') {
			index = (int)i;
			break;
		}
	}
	vector<node*> neighbors;
	switch(index) {
		case 0:		// 1, 3
			neighbors.push_back(swap(cur,index,1));
			neighbors.push_back(swap(cur,index,3));
			break;
		case 1:		// 0, 2, 4
			neighbors.push_back(swap(cur,index,0));
			neighbors.push_back(swap(cur,index,2));
			neighbors.push_back(swap(cur,index,4));
			break;
		case 2:		// 1, 5
			neighbors.push_back(swap(cur,index,1));
			neighbors.push_back(swap(cur,index,5));
			break;
		case 3:		// 0, 4, or 6
			neighbors.push_back(swap(cur,index,0));
			neighbors.push_back(swap(cur,index,4));
			neighbors.push_back(swap(cur,index,6));
			break;
		case 4:		// 1, 3, 5, 7
			neighbors.push_back(swap(cur,index,1));
			neighbors.push_back(swap(cur,index,3));
			neighbors.push_back(swap(cur,index,5));
			neighbors.push_back(swap(cur,index,7));
			break;
		case 5:		// 2, 4, 8
			neighbors.push_back(swap(cur,index,2));
			neighbors.push_back(swap(cur,index,4));
			neighbors.push_back(swap(cur,index,8));
			break;
		case 6:		// 3, 7
			neighbors.push_back(swap(cur,index,3));
			neighbors.push_back(swap(cur,index,7));
			break;
		case 7:		// 4, 6, 8
			neighbors.push_back(swap(cur,index,4));
			neighbors.push_back(swap(cur,index,6));
			neighbors.push_back(swap(cur,index,8));
			break;
		case 8:		// 5, 7
			neighbors.push_back(swap(cur,index,5));
			neighbors.push_back(swap(cur,index,7));
			break;
	}
	return neighbors;
}

node* swap(node* cur, int zero, int target) {
	string s = cur->value;
	s[zero] = s[target];
	s[target] = '0';
	node* n = new node(s, cur->distance + 1);
	return n;
}

node::node(string v, int d) {
	value = v;
	distance = d;
}