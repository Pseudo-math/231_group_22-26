#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Payment 
{
	string address;

public:
	Payment(string s): address(s) {}
	virtual double calculate() = 0;
	virtual ~Payment() {}
};

class Heat : public Payment 
{
	double areaInMeters2;
  const double CostPerMeters2 = 50;

public:
	Heat(string s, double a): Payment(s), areaInMeters2(a) {}
	double calculate() {
		return CostPerMeters2 * areaInMeters2;
	}
};

class Water : public Payment
{
	int people;
  const double CostPerPerson = 200;

public:
	Water(string s, int p) : Payment(s), people(p) {}
	double calculate() {
		return CostPerPerson * people;
	}
};
class Electricity : public Payment
{
	double kwh;
  const double CostPerKwh = 200;

public:
	Electricity(string s, double k) : Payment(s), kwh(k) {}
	double calculate() {
		return CostPerKwh * kwh;
	}
};
