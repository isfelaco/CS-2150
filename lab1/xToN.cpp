// Isabella Felaco, isf4rjk
// 1-25-2022
// xToN

#include <iostream>
using namespace std;

int xton (int x, int n){
  int counter = n;
  if (counter == 1) return x;
  else return x* xton(x,counter-1);		        		       	
}

int main() {
  int x,n,result;
  cin >> x;
  cin >> n;
  result = xton(x,n);
  cout << "Result: " << result << endl;
  return 0;
}
