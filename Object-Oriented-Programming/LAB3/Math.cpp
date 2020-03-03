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
	return (int)(a + b);
}
int Math::Add(double a, double b, double c)
{
	return (int)(a + b + c);
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
	return (int)(a * b);
}
int Math::Mul(double a, double b, double c)
{
	return (int)(a * b * c);
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
			char r[1000] = { '\n' };
			int r_i = 0;
			for(int i = 0; a[i] != '\0'; i++)
			{
				r[r_i++] = a[i];
			}
			for (int i = 0; b[i] != '\0'; i++)
			{
				r[r_i++] = b[i];
			}
			r[r_i++] = '\0';
			char * rez = new char[r_i];
			for(int i = 0; i < r_i; i++)
			{
				rez[i] = r[i];
			}
			return rez;
		}
	}
	return nullptr;
}
