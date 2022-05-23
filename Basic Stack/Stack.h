/*
Isabella Felaco, isf4rjk
2-7-2022
Stack.h
*/

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "StackNode.h"
using namespace std;

class Stack {
public:
  Stack();
  void push(int v);
  void pop();
  int top();
  bool empty();
private:
  StackNode* head;
  int count;
};

#endif
