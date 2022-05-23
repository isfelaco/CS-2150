/*
Isabella Felaco, isf4rjk
2-13-2022
prelab4.cpp
*/

#include <iostream>
#include <stack>
using namespace std;

void sizeOfTest() {
  cout  << "Size of int: " << sizeof(int) << endl;
  cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
  cout << "Size of float: " << sizeof(float) << endl;
  cout << "Size of double: " << sizeof(double) << endl;
  cout << "Size of char: " << sizeof(char) << endl;
  cout << "Size of bool: " << sizeof(bool) << endl;
  cout << "Size of int*: " << sizeof(int*) << endl;
  cout << "Size of char*: " << sizeof(char*) << endl;
  cout << "Size of double*: " << sizeof(double*) << endl;
}

void overflow() {
  unsigned int max_number = 4294967295;
  cout << max_number << " + 1 = " << max_number + 1 << endl;
}

void outputBinary(unsigned int x) {
  stack<int> *myStack = new stack<int>();
  while (x / 2 != 0) {
    myStack->push(x%2);
    x = x / 2;
  }
  myStack->push(x%2);
  if (myStack->size() != 21) {
    for (int i = 32 - myStack->size(); i > 0; i--) {
      myStack->push(0);
    }
  }
  int c = 0;
  for (int i = myStack->size(); i > 0; i--) {
    cout << myStack->top();
    c++;
    myStack->pop();
    if (c == 4) {
      cout << " ";
      c = 0;
    }
  }
  cout << '\n';
}

int main() {
  unsigned int x;
  cin >> x;

  sizeOfTest();
  overflow();
  outputBinary(x);
  
  return 0;
}
