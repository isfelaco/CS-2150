/**
 * Isabella Felaco, isf4rjk
 * HashTable.cpp
 */

#include "HashTable.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

HashTable::HashTable(unsigned int c) {
    capacity = c;
    size = 0;
    table = vector<list<string>>(capacity);
    V = vector<unsigned long long int>(22); // creates a vector of size max string length
    for (int i = 0; i < 22; i++) { // calculates pow(37,i) so it doesn't have to be
        V[i] = pow(37,i);           // calculated during every insert
    }
}

unsigned long long int HashTable::hashFunc(string s) {
    unsigned long long int h = 0;
    for (int i = 0; i < s.length(); i++) {
        h += s[i]*V[i]; // summation of character times pow(37,i)
    }
    return h % capacity;
}

void HashTable::insertElement(string s) {
    table[hashFunc(s)].push_back(s);    // inserts into index using the strings hash function
    size++;
}

bool HashTable::find(string s) {
    for (list<string>::iterator itr = table[hashFunc(s)].begin(); itr != table[hashFunc(s)].end(); itr++) {
        // creates an iterator that goes from beginning to end of only the list at index hashFunc(s)
        if (*itr == s)
            return true;
    }
    return false;
}