#pragma once
#include "Function.h"
class Log :public Function
{
public:
	Log(int log_num, shared_ptr<Function> func);
	Log(Log &log_func, double num);
	const double getCalc();
	const string getDimens();
private:
	shared_ptr <Function> m_func;
	int m_log;
	double m_num;
	double m_calc;
};

