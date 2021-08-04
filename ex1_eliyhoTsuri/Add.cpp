#include "Add.h"
#include "Ln.h"
#include "Square.h"

Add::Add(std::shared_ptr<Function> func1, std::shared_ptr<Function> func2, double num)
	: m_func1(func1), m_func2(func2), m_num(num),
	Function(string().append(func1->getName()).append(func1->getDimens())
			 .append(" * ").append(func2->getDimens()))
{
}

Add::Add(const Add & add, double num)
	:m_num(num),m_calc(0)
{
	m_func1 = add.m_func1;
	m_func2 = add.m_func2;
	Ln ln(num);
	Square square(num);
	//Function *f = dynamic_cast <Ln *> (&ln))
	m_calc = ln.getCalc();
	//Function *f = dynamic_cast <Square *> (&square))
	m_calc += square.getCalc();
}

const double Add::getValue()
{
	return m_num;
}

const double Add::getCalc()
{
	return m_calc;
}

const string Add::getDimens()
{
	std::ostringstream osString;
	osString << '(' << m_func1->getDimens() << ") + (" << m_func2->getDimens() << ')' ;
	return osString.str();
}
