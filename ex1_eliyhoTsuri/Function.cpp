#include "Function.h"

Function::Function()
{
}

Function::Function(string name)
	:m_name(std::move(name))
{
}

const string & Function::getName() const
{
	return m_name;
}