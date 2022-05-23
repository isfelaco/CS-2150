/*
Isabella Felaco, isf4rjk
1-31-2022
ListItr.cpp
*/

#include <iostream>
#include "ListItr.h"
using namespace std;


ListItr::ListItr() {
  current = new ListNode();
}

ListItr::ListItr(ListNode* theNode) {
  current = theNode;
}

bool ListItr::isPastEnd() const {
  // returns true if the iterator is currently pointing past the end position in the list
  if (current->next == NULL)
    return true;
  else
    return false;
}

bool ListItr::isPastBeginning() const {
  // returns true is the iterator is currently pointing past the first position in the list
  if (current->previous == NULL)
    return true;
  else
    return false;
}

void ListItr::moveForward() {
  // advance current to the next position in the list
  if (!isPastEnd())
    current = current->next;
}

void ListItr::moveBackward() {
  // moves current back to the previous position in the list
  if (!isPastBeginning())
    current = current->previous;
}

int ListItr::retrieve() const {
  // returns the value of the item in the current position of the list
  return current->value;
}
