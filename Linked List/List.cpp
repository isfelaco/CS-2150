/*
Isabella Felaco, isf4rjk
1-31-2022
List.cpp
*/

#include <iostream>
#include "List.h"
using namespace std;

List::List() {
  head = new ListNode();
  tail = new ListNode();
  head->previous = NULL;    
  tail->next = NULL;  
  head->next = tail;
  tail->previous = head;
  count = 0;
}

List::List(const List& source) {
 head=new ListNode();
 tail=new ListNode();
 head->next=tail;
 tail->previous=head;
 count=0;

 // Make a deep copy of the list
 ListItr iter(source.head->next);
 while (!iter.isPastEnd()) {
  insertAtTail(iter.retrieve());
  iter.moveForward();
 }
}

List::~List() {
  makeEmpty();
  delete head;
  delete tail;
}

List& List:: operator=(const List& source) {
 if (this == &source) {
   // The two are the same list; no need to do anything
   return *this;
 } else {
    // Clear out anything this list contained
    // before copying over the items from the other list
     makeEmpty();
     // Make a deep copy of the list
     ListItr iter(source.head->next);
     while (!iter.isPastEnd()) {
       insertAtTail(iter.retrieve());
       iter.moveForward();
     }
 }
 return *this;
}					  

//Regular methods, with return types
					  
bool List::isEmpty() const {
 // returns true if empty, else if false
  if (count == 0) 
    return true;
  else
    return false;
}

void List::makeEmpty() {
 // removes all items except the dummy head/tail
  while (!isEmpty()) {
    remove(first().retrieve());
  }
}

ListItr List::first() {
  // returns an iterator that points to the first ListNode after the dummy head node
  return ListItr(head->next);
}

ListItr List::last() {
  // returns an iterator that points to the last ListNode before the dummy tail node
  return ListItr(tail->previous);
}

void List::insertAfter(int x, ListItr position) {
  // inserts x after current iterator position
  if (position.current != tail) {
    position.moveForward();
    insertBefore(x, position);
  }
}

void List::insertBefore(int x, ListItr position) {
  // inserts x before current iterator position
  if (position.current != head) {
    ListNode *newNode = new ListNode(x);
    newNode->previous = position.current->previous;
    newNode->next = position.current;    
    position.current->previous->next = newNode;   
    position.current->previous = newNode;
    ++count;
  }
}

void List::insertAtTail(int x) {
  insertBefore(x, ListItr(tail));
}

ListItr List::find(int x) {
  // returns an iterator that points to the first occurrence of x
  ListItr itr = this->first();
  for (int i = 0; i < count; i++) {
    if (itr.retrieve() == x) {
      break;
    }
    else if (itr.retrieve() != x && !itr.isPastEnd())  {
      itr.moveForward();
    }
  }
  return itr;
}

void List::remove(int x) {
  // removes the first occurrence of x
  ListItr itr = this->find(x);
  if (itr.current != head & itr.current != tail) {    
    itr.current->next->previous = itr.current->previous;
    itr.current->previous->next = itr.current->next;
    count--;
    delete itr.current;
  }
}

int List::size() const {
  // returns the number of elements in the list
  return count;
}
void printList(List& source, bool forward) {
  if (!source.isEmpty()) {
    if (forward == true) {
      ListItr itrf = source.first();
      while (!itrf.isPastEnd()) {
	cout<<itrf.retrieve()<<" ";
	itrf.moveForward();
      }
    }
    if (forward == false) {
      ListItr itrb = source.last();
      while (!itrb.isPastBeginning()) {
	cout<<itrb.retrieve()<<" ";
	itrb.moveBackward();
      }
    }
  }
  cout<<endl;
};
