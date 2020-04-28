#include "myVector.h"
#include <stdio.h>

void mVector::reallocation()
{
	capacity *= 2;
	int* tmp = new int[capacity];
	if (tmp == nullptr) throw "Bad alocation";
	for (int i = 0; i < curent; i++)
	{
		tmp[i] = vector_[i];
	}
	delete[] vector_;
	vector_ = tmp;
}

mVector::mVector(int _capacity):capacity(_capacity)
{
	vector_ = new int[capacity];
}

mVector::mVector()
{
	capacity = 1;
	vector_ = new int[capacity];
}

mVector::~mVector()
{
	delete[] vector_;
}

bool mVector::Add(int val)
{
	try {
		if (capacity == curent) reallocation();
		vector_[curent++] = val;
	}
	catch (...) {
		return false;
	}
	return true;
}

bool mVector::Delete(int index)
{
	try {
		if (index < 0) throw;
		if (index >= curent) throw;
		curent--;
		for (int i = index; i < curent; i++) {
			vector_[i] = vector_[i + 1];
		}
	}
	catch (...) {
		return false;
	}
	return true;
}

void mVector::Iterate(void(*f)(int&))
{
	for (int i = 0; i < curent; i++)
		f(vector_[i]);
}

void mVector::Filter(bool(*f)(int))
{
	for (int i = 0; i < curent; i++)
		if (f(vector_[i]))
			Delete(i);
}

void mVector::Print()
{
	for (auto i : *this)
		printf("%d\n", i);
}

mVector::iterator mVector::begin()
{
	return vector_;
}

mVector::iterator mVector::end()
{
	return vector_ + curent;
}

#pragma region iterator

mVector::iterator mVector::iterator::operator++()
{
	iterator i = *this;
	ptr_++;
	return i;
}

 int& mVector::iterator::operator*()
{
	return *ptr_;
}

int* mVector::iterator::operator->()
{
	return ptr_;
}

bool mVector::iterator::operator==(const mVector::iterator& rhs)
{
	return ptr_ == rhs.ptr_;
}

bool mVector::iterator::operator!=(const mVector::iterator& rhs)
{
	return ptr_ != rhs.ptr_;
}
#pragma endregion