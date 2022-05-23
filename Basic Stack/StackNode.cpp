/*
Isabella Felaco, isf4rjk
2-7-2022
StackNode.cpp
*/

#include <iostream>
#include "StackNode.h"
using namespace std;

StackNode::StackNode() {
  value = 0;
  next = NULL;
  previous = NULL;
}
StackNode::StackNode(int v) {
  value = v;
  next = NULL;
  previous = NULL;
}
