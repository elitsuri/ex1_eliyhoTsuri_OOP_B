#pragma once
#include "Function.h"
class Ln : public Function
{
public:
	Ln(double num = 0);
	const double getCalc();
	const string getDimens();
private:
	double m_num;
};

