/**
 * Isabella Felaco, isf4rjk
 * HashTable.h
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

class HashTable {
public:
	HashTable(unsigned int c);
	unsigned long long int hashFunc(string s);
	void insertElement(string s);
	bool find(string s);
private:
	int size;
	int capacity;
	vector<list<string>> table;
	vector<unsigned long long int> V;
};

#endif