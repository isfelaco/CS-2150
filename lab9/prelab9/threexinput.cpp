#include <iostream>
#include "timer.cpp"
using namespace std;

extern "C" int threexplusone(int x);

int main() {
	int x;
	//cout << "Enter a number: ";
	cin >> x;

	int n;
	//cout << "Enter iterations of subroutine: ";
	cin >> n;

	int steps = threexplusone(x);

	timer *t = new timer();
	t->start();

	for (int i = 0; i < n; i++) {
		threexplusone(x);
	}
	t->stop();
	double time = t->getTime();
	double average = time/n;

	// cout << time << endl;
	// cout << average << endl;

	// cout << "Steps: " << steps << endl;
	cout << steps;

	return 0;
}
