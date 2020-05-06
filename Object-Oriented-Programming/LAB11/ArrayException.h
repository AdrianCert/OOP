#ifndef EXP_ARRAY
#define EXP_ARRAY

#define clean(vector) if (vector != nullptr) delete[] vector

#include <exception>
#include <algorithm>
#include <iostream>
#include <iomanip>

struct bad_alocation : public std::exception
{
	virtual const char* what() const throw() override
	{
		return "Bad allocation";
	}
};

struct out_range : public std::exception
{
	virtual const char* what() const throw() override
	{
		return "The index is out range";
	}
};

struct Compare {
	virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class G>
class Array
{
	G * vector_ = nullptr;
	int current = 0;
	int capacity = 0;
	void reallocation() noexcept(false) {
		G* tmp = new G[capacity ? capacity * 2 : 1];
		if (tmp == nullptr) throw bad_alocation();
		for (int i = 0; i < current; i++)
		{
			tmp[i] = vector_[i];
		}
		clean(vector_);
		capacity = capacity ? capacity * 2 : 1;
		vector_ = tmp;
	}

	bool push_ind(const G & data, int index = -1) noexcept(true) {
		try {
			if (index == -1) index = current;
			if (index > current || index < 0)
				throw out_range();

			if (current == capacity)
				reallocation();

			for (int i = current; i > index; i--)
				vector_[i] = vector_[i - 1];

			vector_[index] = data;
			current++;
			return true;
		}
		catch (std::exception e)
		{
			std::cout << e.what() << std::endl;
			return false;
		}
	}

public:
	Array() {}

	~Array() {
		clean(vector_);
	}

	Array(int _capacity) noexcept(false) {
		vector_ = new G[_capacity];
		if(vector_ == nullptr) throw bad_alocation();
		capacity = _capacity;
	}

	Array(const Array<G> & otherArray) {
		vector_ = new G[otherArray.capacity];
		
		for (int i = 0; i < otherArray.current; i++)
			vector_[i] = otherArray.vector_[i];
		
		current = otherArray.current;
		capacity = otherArray.capacity;
	}

	Array(const Array<G> && otherArray) {
		vector_ = otherArray.vector_;
		current = otherArray.current;
		capacity = otherArray.capacity;
	}

	G& operator[] (int index) noexcept(false) {
		if (index >= current) throw out_range();
		return vector_[index];
	}


	const Array<G> & operator+=(const G & newElem) {
		push_ind(newElem);
		return *this;
	}

	const Array<G> & Insert(int index, const G & newElem) {
		push_ind(newElem, index);
		return *this;
	} 
	
	const Array<G> & Insert(int index, Array<G> otherArray) {
		int align = 0;
		for (auto val : otherArray)
			push_ind(val , index + align);

		return *this;
	}

	const Array<G> & Delete(int index) noexcept(false) {
		if (index >= current)
			throw out_range();
		current--;
		for (int i = index; i < current; i++)
			vector_[i] = vector_[i + 1];

		return *this;
	}
	
	bool operator=(const Array<G> & otherArray) {
		try {
			vector_ = new G[otherArray.capacity];

			for (int i = 0; i < otherArray.current; i++)
				vector_[i] = otherArray.vector_[i];

			current = otherArray.current;
			capacity = otherArray.capacity;

			return true;
		}
		catch (std::exception e) {
			return false;
		}
	}

	bool operator=(const Array<G>&& otherArray) {
		vector_ = otherArray.vector_;
		current = otherArray.current;
		capacity = otherArray.capacity;

		return true;
	}

	void Sort(bool reverse = false) {
		int j;
		G key;
		for (int i = 1; i < current; i++)
		{
			key = vector_[i];
			j = i - 1;

			/* Move elements of arr[0..i-1], that are
			greater than key, to one position ahead
			of their current position */
			while (j >= 0 && (key < vector_[j]) xor reverse)
			{
				vector_[j + 1] = vector_[j];
				j = j - 1;
			}
			vector_[j + 1] = key;
		}
	}

	void Sort(int(*compare)(const G&, const G&)) {
		int j;
		G key;
		for (int i = 1; i < current; i++)
		{
			key = vector_[i];
			j = i - 1;

			/* Move elements of arr[0..i-1], that are
			greater than key, to one position ahead
			of their current position */
			while (j >= 0 && compare( key, vector_[j]) < 0)
			{
			vector_[j + 1] = vector_[j];
			j = j - 1;
			}
			vector_[j + 1] = key;
		}
	}
	
	void Sort(Compare* comparator) {
		int j;
		G key;
		for (int i = 1; i < current; i++)
		{
			key = vector_[i];
			j = i - 1;

			/* Move elements of arr[0..i-1], that are
			greater than key, to one position ahead
			of their current position */
			while (j >= 0 && comparator->CompareElements(&key, &vector_[j]) < 0)
			{
				vector_[j + 1] = vector_[j];
				j = j - 1;
			}
			vector_[j + 1] = key;
		}
	}


	bool BinarySearch(const G& elem) {
		auto first = begin();
		auto last = end();
		first = std::lower_bound(first, last, elem);
		return (!(first == last) && !(elem < *first));
		// return std::binary_search(begin(), end(), elem);
	}

	bool BinarySearch(const G& elem, int(*compare)(const G&, const G&))
	{
		auto first = begin();
		auto last = end();
		first = std::lower_bound(first, last, elem, compare);
		return (!(first == last) && !(compare(elem, *first)));
		//return std::binary_search(begin(), end(), elem, compare);
	}
	bool BinarySearch(const G& elem, Compare* comparator)
	{
		auto first = begin();
		auto last = end();
		first = std::lower_bound(first, last, elem, comparator->CompareElements);
		return (!(first == last) && !(comparator->CompareElements(elem, *first)));
		//return std::binary_search(begin(), end(), elem, comparator);
	}


	int Find(const G& elem) {
		auto rez = std::find(begin(), end(), elem);
		return !(rez == end());
		//return std::find(begin(), end(), elem );
	}

	int Find(const G & elem, int(*compare)(const G&, const G&)) {
		for (auto i : *this)
			if (compare(i, elem) > 0)
				return 1;
		return 0;
		//auto rez = std::find_if(begin(), end(),compare > 0);
		//return !(rez == end());
		//return std::find(begin(), end(), elem, compare);
	}

	int Find(const G& elem, Compare* comparator) {
		for (auto i : *this)
			if (comparator->CompareElements(i, elem) > 0)
				return 1;
		return 0;
		//return std::find(begin(), end(), elem, comparator);
	}


	int GetSize() {
		return current;
	}

	int GetCapacity() {
		return capacity;
	}

	bool Add(const G& newElem) {
		return push_ind(newElem);
	}

	class iterator
	{
		G* ptr_;
	public:
		iterator(G* _ptr) : ptr_(_ptr) {}

		iterator operator++() {
			ptr_++;
			return *this;
		}

		G& operator*() {
			return *ptr_;
		}

		G* operator->() {
			return ptr_;
		}

		/*iterator & operator=(const iterator& a) {
			ptr_ = a.ptr_;
			return *this;
		}

		iterator & operator=(const iterator&& a) {
			ptr_ = a.ptr_;
			return *this;
		}*/

		bool operator==(const iterator& rhs) {
			return ptr_ == rhs.ptr_;
		}

		bool operator!=(const iterator& rhs) {
			return ptr_ != rhs.ptr_;
		}
	};


	iterator begin() {
		return iterator(vector_);
	}

	iterator end() {
		return iterator(vector_ + current);
	}

};

#endif