#include "NumberList.h"
#include <iostream>


// count will be 0
void NumberList::Init()
{
	count = 0;
}
// adds X to the numbers list and increase the data member count.
// if count is bigger or equal to 10, the function will return false
bool NumberList::Add(int x)
{
	if (count == 10)
		return false;
	numbers[count] = x;
	count++;
	return true;
}
// will sort the numbers vector
void NumberList::Sort() 
{
	bool ok;
	do
	{
		ok = false;
		for (int j = 1; j < count; j++)
		{
			if (numbers[j -1] > numbers[j])
			{
				int temp = numbers[j];
				numbers[j] = numbers[j - 1];
				numbers[j - 1] = temp;
				ok = true;
			}
		}
	}while(ok);
}
// will print the current vector
void NumberList::Print()
{
	for (int i = 0; i < count; i++) {
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;
}