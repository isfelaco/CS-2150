/*
Isabella Felaco, isf4rjk
2-7-2022
Stack.cpp
*/

#include <iostream>
#include "Stack.h"
#include "StackNode.h"
using namespace std;

Stack::Stack() {
  head = new StackNode();
  head->previous = NULL;
  count = 0;
}
void Stack::push(int v) {
  StackNode *newNode = new StackNode(v);
  if (!empty()) {   
    newNode->next  = head->next;
    head->next = newNode;   
    newNode->previous = head;
    newNode->next->previous = newNode;
  }
  else {
    newNode->previous = head;
    head->next = newNode;
  }
  count++;
}
void Stack::pop() {
  if (count > 1) { 
    head->next = head->next->next;
    head->next->previous = head;
  }
  else {
    head->next = NULL;
  }
  count--;
}
int Stack::top() {
  return head->next->value;
}
bool Stack::empty() {
  if (count == 0)
    return true;
  else
    return false;
}
