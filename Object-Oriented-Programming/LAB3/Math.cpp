#include "Math.h"
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

int Math::Add(int a, int b)
{
	return a + b;
}

int Math::Add(int a, int b, int c)
{
	return a + b + c;
}
int Math::Add(double a, double b)
{
	return a + b;
}
int Math::Add(double a, double b, double c)
{
	return a + b + c;
}
int Math::Mul(int a, int b)
{
	return a * b;
}
int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}
int Math::Mul(double a, double b)
{
	return a * b;
}
int Math::Mul(double a, double b, double c)
{
	return a * b * c;
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
char* Math::Add(const char* a, const char* b)
{
	if(a)
	{
		if (b)
		{
			int n = 1 + strlen(a) + strlen(b);
			char* r = new char[n] { '\0'};
			strcat(r, a);
			strcat(r, b);
			return r;
		}
	}
	return nullptr;
}
