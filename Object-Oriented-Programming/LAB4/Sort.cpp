#include "Sort.h"
#include <stdarg.h>
#include <iostream>
#include <time.h>

Sort::Sort(int _min, int _max)
{
	srand((unsigned)time(0));
	this->count = rand() % 1000;
	this->array = new int[this->count];
	int dif = _max - _min;
	for(int i = 0; i < count; i++)
	{
		this->array[i] = rand() % dif + _min;
	}
}

Sort::Sort(int* init, int _count) : array(init), count(_count) {}

Sort::Sort(int _count,int* _array)
{
	this->count = _count;
	this->array = new int[_count];
	for (int i = 0; i < _count; i++) {
		this->array[i] = _array[i];
	}
}
Sort::Sort(int _count, ...)
{
	this->array = new int[_count];
	
	va_list variable_list;
	va_start(variable_list, _count);

	for (int i = 0; i < _count; i++)
	{
		int parm = va_arg(variable_list, int);
		this->array[i] = parm;
	}
	va_end(variable_list);
}
Sort::Sort(const char* _string)
{
	int comming_count = 1;
	for (int i = 0; i < _string[i] != '\0' ; i++) {
		if (_string[i] == ',') {
			comming_count++;
		}
	}
	this->count = comming_count;
	this->array = new int[comming_count + 1];
	this->array[0] = 0;
	int k = 0;
	for (int i = 0; _string[i] != '\0'; i++)
	{
		if (_string[i] != ',') 
		{
			array[k] = array[k] * 10 + _string[i] - '0';
		}
		else
		{
			k++;
			array[k] = 0;
		}
	}
	// move on heap the array
}


void Sort::InsertSort(bool _reverse) 
{
	int i, key, j;
	for (i = 1; i < count; i++)
	{
		key = array[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && integer_evaluation(key, array[j], _reverse))
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
}
void Sort::QuickSort(bool _reverse)
{
	this->_reversing = _reverse;
	internal_quickSort(0, count - 1);
}
void Sort::BubbleSort(bool _reverse)
{
	bool again;
	do {
		again = false;
		for (int i = 1; i < count; i++)
		{
			if (integer_evaluation(array[i], array[i - 1], _reverse))
			{
				again = true;
				int tmp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = tmp;
			}
		}
	} while (again);
}
void Sort::Print()
{
	for (unsigned int i = 0; i < count; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}
int	Sort::GetElementsCount()
{
	return this->count;
}
int	Sort::GetElementFromIndex(int _index)
{
	return this->array[_index];
}

void Sort::internal_quickSort(int left, int right) {

	int i = left, j = right;
	int pivot = array[(left + right) / 2];
	
	/* partition */
	while (i <= j) {
		while (integer_evaluation(array[i], pivot, _reversing))
		{
			i++;
		}
		while (integer_evaluation(pivot, array[j], _reversing))
		{
			j--;
		}
		if (i <= j)
		{
			int tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			i++;
			j--;
		}
	}

	/* recursion */
	if (left < j)
	{
		internal_quickSort(left, j);
	}
	if (i < right)
	{
		internal_quickSort(i, right);
	}
}

// return a b 
bool integer_evaluation(int a, int b, bool reverse) {
	if (reverse)
		return a > b ? true: false;
	return a < b ? true: false;
}