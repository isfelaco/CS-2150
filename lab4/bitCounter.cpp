/*
Isabella Felaco, isf4rjk
2-16-2022
bitCounter.cpp
*/

#include <iostream>
#include <string>
#include <stack>
#include <math.h>
using namespace std;

string convert(string n, int startBase, int endBase) {
  // convert string to numbers and place on stack
  stack<int> *myStack = new stack<int>;
  for (int i = 0; i < n.length(); i++) {
    if (n[i] != '0' && n[i] != '1' && n[i] != '2' && n[i] != '3' && n[i] != '4' && n[i] != '5' && n[i] != '6' && n[i] != '7' && n[i] != '8' && n[i] != '9')
      myStack->push(int(n[i])-55);
    else
      myStack->push(int(n[i])-48);  
  }
  // convert to base 10
  int baseTen = 0;
  int size = myStack->size();
  for (int i = 0; i < size; i++) {
    baseTen += (myStack->top())*pow(startBase,i);
    myStack->pop();
  }
  // convert to endBase
  myStack->empty();
  string s = "";
  if (endBase != 10) {
    while (baseTen / endBase != 0) {
      myStack->push(baseTen % endBase);
      baseTen = baseTen / endBase;
    }
    myStack->push(baseTen % endBase);
    size = myStack->size();
    for (int i = 0; i < size; i++) {
      s += to_string(myStack->top());
      myStack->pop();
    }
    return s;
  }
  else
    return to_string(baseTen);
}

int count(int n) {
  // recursive function that returns the number of 1s in the binary representation of n
  int counter = 0;
  if (n % 2 == 0) {
    return count(n/2);
  }
  else {
    string binary = convert(to_string(n), 10, 2);
    for (int i = 0; i < binary.length(); i++) {
      if (binary[i] == '1')
	counter += 1;
    }
  }
  return counter;
}


int main(int argc, char **argv) {
  int bitCount = stoi(argv[1]);
  int startBase = stoi(argv[3]);
  int endBase = stoi(argv[4]);
  cout << bitCount << " has " << count(bitCount) << " bit(s)" << endl;
  cout << argv[2] << " (base " << startBase << ") = " << convert(argv[2],startBase,endBase) << " (base " << endBase << ")" << endl;
  return 0;
}
