/*
 * Filename: List.h
 * Description: List class definition
 * 	also includes the prototype for non-member function printList()
 */
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "ListNode.h"
#include "ListItr.h"
using namespace std;

class ListItr;

class List {
public:
    List();
    List(const List& source);
    ~List();
    List& operator=(const List& source);
    bool isEmpty() const;
    void makeEmpty();
    ListItr first();
    ListItr last();
    void insertAfter(int x, ListItr position);
    void insertBefore(int x, ListItr position);
    void insertAtTail(int x);
    ListItr find(int x);
    void remove(int x);
    int size() const;
private:
    ListNode* head;
    ListNode* tail;
    int count;
};
void printList(List& source, bool forward);

#endif
