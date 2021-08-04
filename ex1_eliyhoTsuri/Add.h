#pragma once
#include "Function.h"
class Add : public Function
{
public:
	Add(std::shared_ptr<Function> func1, std::shared_ptr<Function> func2, double num);
	Add(const Add &add, double num);
	const double getValue();
	const double getCalc();
	const string getDimens();
private:
	std::shared_ptr <Function> m_func1;
	std::shared_ptr <Function> m_func2;
	double m_num;
	double m_calc;
};

