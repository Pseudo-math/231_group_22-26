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
			firstBigNumber = x;
			secondBigNumber = y;
		}
		else {
			firstBigNumber = y;
			secondBigNumber = x;
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
		cout << "firstBigNumber = " << firstBigNumber << " secondBigNumber = " << secondBigNumber;
	}
};


class Three : public Two
{
	double thirdBigNumber;
public:
	Three(double x, double y, double z) : Two(x, y) { thirdBigNumber = Two::study(x); };

	double study(double x) {
		double minNumber;
		double temp;
		temp = Two::study(x);
		if (temp > thirdBigNumber) {
			minNumber = thirdBigNumber;
			thirdBigNumber = temp;
		}
		else minNumber = temp;
		return minNumber;
	}

	void print() {
		Two::print();
		cout << " thirdBigNumber = " << thirdBigNumber;
	}
};
