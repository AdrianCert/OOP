#include <iostream>
#include "Math.h"
#include "Canvas.h"

int main()
{
	/* Demo for Math.h * /
	double ex_01 = 3147483647;
	double ex_02 = 1147483647;
	double ex_03 = 2;

	// calling Math::Add(int, int);
	std::cout << " call: static int Add(int, int) --> ";
	std::cout << Math::Add(3, 5) << std::endl;

	// calling Math::Add(int, int, int);
	std::cout << " call: static int Add(int, int, int) --> ";
	std::cout << Math::Add(4, 4, 2) << std::endl;

	// calling Math::Add(double, double);
	std::cout << " call: static int Add(double, double) --> ";
	std::cout << Math::Add(ex_02, double(2)) << std::endl;

	// calling Math::Add(double, double, double);
	std::cout << " call: static int Add(double, double, double) --> ";
	std::cout << Math::Add(ex_01, ex_01, ex_03) << std::endl;

	// calling Math::Mul(int, int);
	std::cout << " call: static int Mul(int, int) --> ";
	std::cout << Math::Mul(4, 3) << std::endl;
	
	// calling Math::Mul(int, int, int);
	std::cout << " call: static int Mul(int, int, int) --> ";
	std::cout << Math::Mul(12, 10, 1) << std::endl;
	
	// calling Math::Mul(double, double);
	std::cout << " call: static int Mul(double, double) --> ";
	std::cout << Math::Mul(ex_01, ex_02) << std::endl;
	
	// calling Math::Mul(double, double, double);
	std::cout << " call: static int Mul(double, double, double) --> ";
	std::cout << Math::Mul(ex_01, ex_02,ex_03) << std::endl;

	// calling Math::Add(int count, ...); // sums up a list of integers
	std::cout << " call: static int Add(int count, ...) --> ";
	std::cout << Math::Add(5, 1, 2, 3, 4, 5) << std::endl;
	
	// calling Math::Add(const char*, const char*);
	std::cout << " call: static char* Add(const char*, const char*) --> ";
	std::cout << Math::Add("Ana are", " Mere") << std::endl;

	/* End Demo for Math.h */
	/* New ddd */
	Canvas m(50,50);

	m.FillCircle(20, 20, 10, 'x');
	//m.FillRect(2, 2, 20, 20, '*');
	//m.DrawRect(2, 2, 20, 20, '#');
	m.Print();
	//*/
	return 0;
}