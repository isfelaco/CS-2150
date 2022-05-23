/*
Isabella Felaco, isf4rjk
2-7-2022
StackNode.h
*/

#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>
using namespace std;

class StackNode {
 public:
  StackNode();
  StackNode(int v);
 private:
  int value;
  StackNode* next;
  StackNode* previous;
  friend class Stack;
};

#endif
