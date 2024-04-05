//chp4ex4.cpp

#include <iostream>
#include <iomanip>
#include <cmath>

const double MAX = 100;

using namespace std;

int main() {
	double i;

	for (i = 1; i <= 100; i++) {
		cout << i << setw(1);
	}

	cout << endl << setw(0);

	for (i = 1; i <= 100; i++) {
		cout << i * i << setw(2);
	}
	cout << endl;

	return 0;

}