/*
Isabella Felaco, isf4rjk
1-31-2022
ListNode.cpp
*/

#include <iostream>
#include "ListNode.h"
using namespace std;

ListNode::ListNode() {
  value = 0;
  next = NULL;
  previous = NULL;
}
ListNode::ListNode(int v) {
  value = v;
  next = NULL;
  previous = NULL;
}
