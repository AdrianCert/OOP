#ifndef _MATH_H_
#define _MATH_H_

class Math
{
public:
	// returns the result of gathering the parameters of type int
	static int Add(int, int);
	// returns the result of gathering the parameters of type int
	static int Add(int, int, int);
	// returns the result of gathering the parameters of type double
	static int Add(double, double);
	// returns the result of gathering the parameters of type double
	static int Add(double, double, double);
	// returns the result of multiplying the parameters of type int
	static int Mul(int, int);
	// returns the result of multiplying the parameters of type int
	static int Mul(int, int, int);
	// returns the result of multiplying the parameters of type double
	static int Mul(double, double);
	// returns the result of multiplying the parameters of type double
	static int Mul(double, double, double);
	// sums up a list of integers
	static int Add(int count, ...);
	// will allocate memory that can add the two existing string.
	// if one of the strings is nullptr, this function will return nullptr;
	static char* Add(const char*, const char*);
};

#endif // !_MATH_H_