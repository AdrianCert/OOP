#include "Sort.h"

int main()
{
	/* Demo sort class out of random values within a specific interval (min , max)* /
	Sort a1(10, 200);
	a1.Print();
	//*/

	/* Demo sort class from an initialization list*/ 
	int* v = new int[3] { 10, 20, 30 };
	Sort d{ v,3 };
	d.Print();
	//*/

	Sort string_arrr("14,12,46,13,3");
	string_arrr.Print();

	/* Demo sort class from an existing vector * /
	int v_ex[5][4] = {
		86, 25, 56, 18,
		75, 75, 79, 19,
		53, 97, 75, 65,
		103, 73, 33, 87,
		13, 22, 39, 95
	};
	Sort ex03(4, v_ex[3]); // this one constructor make a copy for the array
	ex03.Print();
	//*/
	Sort TestIS(10, 2990);
	TestIS.QuickSort(true);
	TestIS.Print();

	return 1;
}
