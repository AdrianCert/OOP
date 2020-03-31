#include <iostream>
#include "Array.h"
#include "Conversions.h"

int main()
{
	float a = 300_Kelvin;
	float b = 120.9_Fahrenheit;
    std::cout << "Using literals examples: " << std::endl;
    std::cout << "300 Kelbin in Celsius is " << a << std::endl;
    std::cout << "120 Fahrenheit in Celsius is " << b << std::endl;

    std::cout << "First example ussing Array template " << std::endl;

    Array<> v;
    v.push(10);
    v.push(20);
    v.push(30);
    v.push(40);
    v.push(50);

    std::cout << "Array size : " << v.count() << std::endl;
    std::cout << "Array capacity : " << v.getcapacity() << std::endl;

    std::cout << "Array elements : ";
    v.print();

    v.insert(100, 1);

    std::cout << "\nAfter updating 1st index" << std::endl;

    std::cout << "Array elements : ";
    v.print();

    std::cout << "Element at 1st index : " << v.get(1) << std::endl;

    v.pop();

    std::cout << "\nAfter deleting last element" << std::endl;

    std::cout << "Array size : " << v.count() << std::endl;
    std::cout << "Array capacity : " << v.getcapacity() << std::endl;

    std::cout << "Array elements : ";
    v.print();


    std::cout << "Sorting elements default : ";
    v.sort();
    std::cout << "Array elements : ";
    v.print();

    std::cout << "Sorting elements using a lambda : ";
    v.sort();
    v.sort([](int a, int b) { return a > b; });
    //v.sort([](float a, float b) { return a > b; });
    std::cout << "Array elements : ";
    v.print();
    std::cout << "First index for 40 is: " << v.firstIndexOf(40);
	return 0;
}