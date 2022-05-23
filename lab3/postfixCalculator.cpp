/*
Isabella Felaco, isf4rjk
2-7-2022
postfixCalculator.cpp
*/

#include <iostream>
#include "postfixCalculator.h"
using namespace std;

postfixCalculator::postfixCalculator() {
  myStack = new Stack();
}
int postfixCalculator::takeInput() {
  string mystr;
  while (cin >> mystr) {
    if (mystr != "+" & mystr != "-" & mystr != "*" & mystr != "/" & mystr != "~") {
      myStack->push(stoi(mystr));
	// stoi is a non-member function of string which converts a string to a signed int
	// source: cppreference.com : std:: basic_string
    }
    else if (!myStack->empty()) {
      if (mystr == "+") {
        add(getNum(),getNum());
      }
      else if (mystr == "-") {
        subtract(getNum(), getNum());
      }
      else if (mystr == "*") {
        multiply(getNum(), getNum());
      }
      else if (mystr == "/") {
        divide(getNum(), getNum());
      }
      else if (mystr == "~") {
        negate(getNum());
      }
    }
  }
  return myStack->top();
}
int postfixCalculator::getNum() {
  int x = myStack->top();
  myStack->pop();
  return x;
}
void postfixCalculator::add(int x, int y) { 
  myStack->push(x+y);
}
void postfixCalculator::subtract(int x, int y) {
  myStack->push(y-x);
}
void postfixCalculator::multiply(int x, int y) {
  myStack->push(x*y);
}
void postfixCalculator::divide(int x, int y) {
  myStack->push(y/x);
}
void postfixCalculator::negate(int x) {
  myStack->push(x*(-1));
}

