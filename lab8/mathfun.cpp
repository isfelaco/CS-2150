// main.cpp

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

extern "C" long product (int, int);
extern "C" long power (int, int);

int  main () {
    int x, y;
    cout << "Enter integer 1:";
    cin >> x;
    cout << "Enter integer 2:";
    cin >> y;
    long p = product(x,y);
    long e = power(x,y);
    cout << "Product: " << p << endl;
    cout << "Power: " << e << endl;

    return 0;
}
