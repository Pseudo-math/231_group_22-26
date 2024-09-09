#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Expression {
public:
	  Expression() {};
	  virtual double evaluate() = 0;
	  virtual ~Expression() {}
};

class Number : public Expression {
	  double value;
public:
	  Number(double x) : value(x) {};
	  double evaluate() { return value; }
};

class BinaryOperation : public Expression {
	  Expression* left,* right;
	  char operation;
public:
	  BinaryOperation(Expression* l, char o, Expression* r): left(l), right(r), operarion(o) {}
	  double evaluate() {
		double x = left->evaluate();
		double y = right->evaluate();
		if (oper == '+') return x + y;
		if (oper == '-') return x - y;
		if (oper == '*') return x * y;
		if (oper == '/') return x / y;
	}
	~BinaryOperation() {
		delete left;
		delete right;
    delete &operation;
	}
};
