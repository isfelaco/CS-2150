/**
 * Isabella Felaco, isf4rjk
 * HashTable.cpp
 */

#include "HashTable.h"
#include <iostream>
#include <string>
using namespace std;

HashTable::HashTable(unsigned int c) {
    capacity = c;
    size = 0;
    table = new List[capacity];
}

int HashTable::getSize() {
    return size;
}

int HashTable::getCapacity() {
    return capacity;
}

int HashTable::hashFunc(char c) {
    return (int)c % capacity;
}

void HashTable::insertElement(string s) {
    char x = s[0];
    table[hashFunc(x)].insertAtTail(s);
    size++;
}

bool HashTable::find(string s) {
    for (int i = 0; i < capacity; i++) {
        ListItr itr = table[i].first();
        for (int j = 0; j < table[i].size(); j++) {
            // if (itr.retrieve().length() == s.length()) {
            //     cout << itr.retrieve() << ", " << s << endl;

            // }
            if (itr.retrieve() == s) {
                return true;
            }
            itr.moveForward();
        }
    }
    return false;
}

void HashTable::printAll() {
    for (int i = 0; i < capacity; i++) {
        ListItr itr = table[i].first();
        for (int j = 0; j < table[i].size(); j++) {
            cout << itr.retrieve() << ", ";
            itr.moveForward();
        }
        cout << endl;
        cout << endl;
    }
}

// int main() {
//     HashTable ht(11);
//     string arr[] = {"aa","bb","cc","dd"};
//     for(int i = 0; i < 4; i++) {
//         ht.insertElement(arr[i]);
//     }

//     cout << "..:: Hash Table ::.." << endl;
//     ht.printAll();
//     return 0;
// }