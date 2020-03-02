#include "NumberList.h"

int main() {
	/* Test number class */
	NumberList x;
	x.Init();
	x.Add(7);
	x.Add(8);
	x.Add(9);
	x.Add(11);
	x.Add(0);
	x.Print();
	x.Sort();
	x.Print();
	/* End Test number class */
	return 1;
}