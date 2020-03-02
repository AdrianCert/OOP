#include "Math.h"
#include <stdarg.h>

int Math::Add(int, int)
{

}
int Math::Add(int, int, int)
{

}
int Math::Add(double, double)
{

}
int Math::Add(double, double, double)
{

}
int Math::Mul(int, int)
{

}
int Math::Mul(int, int, int)
{

}
int Math::Mul(double, double)
{

}
int Math::Mul(double, double, double)
{

}
// sums up a list of integers
int Math::Add(int count, ...)
{
	int rezult = 0;
	va_list variable_list;
	va_start(variable_list, count);
	for (int i = 0; i < count; i++)
	{
		int parm = va_arg(variable_list, int);
		rezult += parm;
	}
	va_end(variable_list);
	return rezult;
}
char* Math::Add(const char*, const char*)
{

}