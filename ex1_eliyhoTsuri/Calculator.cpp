#include "Calculator.h"
#include "Ln.h"
#include "Square.h"
#include "Multiple.h"
#include "Add.h"
#include "Compos.h"
#include "Log.h"
#include "Poly.h"


Calculator::Calculator()
{
	run();
	
}

void Calculator::run()
{
	vector <shared_ptr <Function>> v_Func;

	v_Func.push_back(std::make_shared<Ln>());
	v_Func.push_back(std::make_shared<Square>());
	int num_func, num;
	int func1, func2, size_poly;
	bool flag = false;
	string command;

	cout << "Calculator \n";

	do
	{
		print_manu(v_Func, flag);
		if (flag)
		{
			int p = v_Func.size() - 1;
			v_Func.erase(v_Func.begin() + p);
			flag = false;
		}
		cin >> command;
		std::transform(command.begin(), command.end(), command.begin(), ::toupper);
		if (command == "EVAL")
		{
			flag = true;
			cin >> num_func >> num;
			if (v_Func.size() <= (unsigned)num_func)
			{
				cout << "There is no such function \n";
				break;
			}			if (num_func == 0)
				v_Func.push_back(make_shared <Ln>(num));
			if (num_func == 1)
				v_Func.push_back(make_shared <Square>(num));
			if (Function *f = dynamic_cast <Multiple*>(&(*v_Func[num_func])))
			{
				Multiple *m = dynamic_cast <Multiple*>(&(*v_Func[num_func]));
				Multiple &mul = *m;
				v_Func.push_back(make_shared <Multiple>(mul, num));
			}
			if (Function *f = dynamic_cast <Add*>(&(*v_Func[num_func])))
			{
				Add *m = dynamic_cast <Add*>(&(*v_Func[num_func]));
				Add &mul = *m;
				v_Func.push_back(make_shared <Add>(mul, num));
			}
			if (Function *f = dynamic_cast <Compos*>(&(*v_Func[num_func])))
			{
				Compos *c = dynamic_cast <Compos*>(&(*v_Func[num_func]));
				Compos &compos = *c;
				v_Func.push_back(make_shared <Compos>(compos, num));
			}
			if (Function *f = dynamic_cast <Poly*>(&(*v_Func[num_func])))
			{
				Poly *p = dynamic_cast <Poly*>(&(*v_Func[num_func]));
				Poly &poly = *p;
				v_Func.push_back(make_shared <Poly>(poly, num));
			}
			if (Function *f = dynamic_cast <Log*>(&(*v_Func[num_func])))
			{
				Log *l = dynamic_cast <Log*>(&(*v_Func[num_func]));
				Log &log = *l;
				v_Func.push_back(make_shared <Log>(log, num));
			}
		}
		if (command == "POLY")
		{
			cin >> size_poly;
			v_Func.push_back(make_shared <Poly>(size_poly));
		}
		if (command == "REV")
		{
			cin >> num_func;
			if (Poly *p = dynamic_cast <Poly*>(&(*v_Func[num_func])))
			{
				Poly &poly = *p;
				v_Func.push_back(make_shared <Poly>(poly));
			}
			else
				cout << "This function is not polynomial\n";
		}
		if (command == "MUL")
		{
			cin >> func1 >> func2;
			v_Func.push_back(make_shared<Multiple>(v_Func[func1], v_Func[func2]));
		}
		if (command == "ADD")
		{
			cin >> func1 >> func2;
			v_Func.push_back(make_shared<Add>(v_Func[func1], v_Func[func2], num));
		}
		if (command == "COMP")
		{
			cin >> func1 >> func2;
			v_Func.push_back(make_shared<Compos>(v_Func[func1], v_Func[func2]));
		}
		if (command == "LOG")
		{
			cin >> num >> func1;
			v_Func.push_back(make_shared<Log>(num, v_Func[func1]));
		}

		if (command == "DEL")
		{
			cin >> num_func;
			if (v_Func.size() - 1 <(unsigned)num_func)
			{
				cout << "There is no such function \n";
				exit(EXIT_FAILURE);
			}
			else
				v_Func.erase(v_Func.begin() + num_func);
		}
		if (command == "HELP")
			print_help();
	} while (command != "EXIT");
	cout << "\nGoodbye :-) \n";
}


// ----------------------------------------------------------------

void Calculator::print_manu(vector<shared_ptr<Function>> v_Func, bool & flag)
{
	int p = v_Func.size() - 1;
	if (flag)
	{
		cout << '\n' << v_Func[p]->getName() << v_Func[p]->getDimens()
			<< " = " << v_Func[p]->getCalc() << "\n\n";
		v_Func.erase(v_Func.begin() + p);
	}
	int i = 0;
	cout << "\nThis is the functions list: \n";

	for (auto &p : v_Func)
		cout << i++ << ": " << p->getDimens() << '\n';
	cout << "Please enter a command ('help' for command list):\n";
}
// ----------------------------------------------------------------

bool Calculator::is_poly(vector<shared_ptr<Function>> v_Func, int num_func)
{
	bool is_poly = false;
	for (auto &i : v_Func)
	{
		if (i->getName() == "Poly")
		{
			is_poly = true;
			break;
		}
	}
	return is_poly;
}
// ----------------------------------------------------------------

void Calculator::print_help()
{
	cout << "\nThis is the manu function :\n"
		R"(eval(uate) num x - Evaluates function #num on x
poly(nomial) N c0 c1 ... cN - 1 - Creates a polynomial with N coefficients.
rev(erse) num - Creates a polynomial with N coefficients in reverse order.	
mul(tiply) num1 num2 - Creates a function that is the multiplication of function #num1 and function #num2.
add num1 num2 - Creates a function that is the sum of function #num1 and function #num2.
comp(osite) num1 num2 - Creates a function that is the composition of function #num1 and function #num2.
log N num - Log N of function #num.
del(ete) num - Deletes function #num from function list.
help - Prints this help screen.
exit - Exits the program)" << '\n';
}
