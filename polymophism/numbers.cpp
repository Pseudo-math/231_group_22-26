#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Two
{
	double firstBigNumber;
	double secondBigNumber;

public:
	Two(double x, double y) {
		if (x > y) {
			a = x;
			b = y;
		}
		else {
			a = y;
			b = x;
		}
	}

	double study(double x) {
		double minNumber;
		if (x > firstBigNumber) {
      minNumber = secondBigNumber;
      secondBigNumber = firstBigNumber;
      firstBigNumber = x;
		}
		else if (x > secondBigNumber) {
      minNumber = secondBigNumber;
			secondBigNumber = x;
		}
		else minNumber = x;
		return minNumber;
	}

	void print() {
		cout << "a = " << a << " b = " << b;
	}
};


class Three : Two
{
	double c;
public:
	Three(double x, double y, double z) : Two(x, y), c(Two::study(z)) {}

	double study(double x) {
		double minNumber;
		double temp;
		temp = Two::study(x);
		if (temp > c) {
			minNumber = c;
			c = temp;
		}
		else minNumber = temp;
		return minNumber;
	}

	void print() {
		Two::print();
		cout << " c = " << c;
	}
};
