/*
Isabella Felaco, isf4rjk
2-7-2022
testPostfixCalc.cpp
*/

#include <iostream>
#include "postfixCalculator.h"
using namespace std;

int main() {
  postfixCalculator *myCalc = new postfixCalculator();  
  cout<<myCalc->takeInput()<<endl;
  return 0;
};
