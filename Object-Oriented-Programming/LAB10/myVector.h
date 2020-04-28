#ifndef MY_VECTOR
#define MY_VECTOR

class mVector
{
	int* vector_ = nullptr;
	int curent = 0;
	int capacity = 0;
	void reallocation();
public:
	mVector(int _capacity);
	mVector();
	~mVector();
	bool Add(int); 
	bool Delete(int index);

	class iterator
	{
		int* ptr_;
	public:
		iterator(int* _ptr) : ptr_(_ptr) {}

		iterator operator++();
		int& operator*();
		int* operator->();
		bool operator==(const iterator& rhs);
		bool operator!=(const iterator& rhs);
	};
	iterator begin();
	iterator end();
	void Iterate(void(*f)(int&));
	void Filter(bool(*f)(int));
	void Print();
};
#endif // !MY_VECTOR
