#include <iostream>
#include "Math.h"

int main()
{
	std::cout << Math::Add(3, 1);
	

	// using int Math::Add(int count, ...)
	std::cout << Math::Add(5, 1, 2, 3, 4, 5);

	return 0;
}