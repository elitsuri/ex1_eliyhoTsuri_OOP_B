#pragma once
#include "Function.h"
class Poly :public Function
{
public:
	Poly() {};
	Poly(int size);
	Poly(const Poly &poly);
	Poly(const Poly &poly,double num);
	double operator[](int index) const { return m_poly[index]; }
	const double getCalc();
	const string getDimens();
	int getSize()const;
private:
	vector <double> m_poly;
	int m_size;
	double m_num;
	double m_calc;
};