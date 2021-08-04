#pragma once
#include "Function.h"
class Square : public Function
{
public:
	Square(double num = 0);
	const double getValue();
	const double getCalc();
	const string getDimens();
private:
	double m_num;
};

