/**
 * Isabella Felaco, isf4rjk
 * HashTable.h
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include "List.h"
using namespace std;

class HashTable {
public:
	HashTable(unsigned int c);
	int getSize();
	int getCapacity();
	int hashFunc(char c);
	void insertElement(string s);
	bool find(string s);
	void printAll();
private:
	int size;
	int capacity;
	List *table;
};

#endif