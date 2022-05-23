/*
Isabella Felaco, isf4rjk
2-7-2022
postfixCalculator.h
*/

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include "Stack.h"
using namespace std;

class postfixCalculator {
public:
  postfixCalculator();
  void add(int x, int y);
  void subtract(int x, int y);
  void multiply(int x, int y);
  void divide(int x, int y);
  void negate(int x);
  int takeInput();
  int getNum();
private:
  Stack *myStack;
};

#endif
