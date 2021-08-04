#pragma once
#include <vector>
#include <iostream>
#include <memory>
#include <string>
#include <algorithm>
#include <sstream>
#include "Function.h"
class Calculator
{
public:
	Calculator();
	void run();
private:
	vector <shared_ptr <Function>> v_Func;
	void print_manu(vector <shared_ptr <Function>> v_Func, bool &flag);
	bool is_poly(vector <shared_ptr <Function>> v_Func, int num_func);
	void print_help();
};