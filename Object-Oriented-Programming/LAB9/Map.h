#include <tuple>
#ifndef MY_MAP_H
#define MY_MAP_H

template<class T, class U>
struct Pair {
	T first;
	U second;
	int index;
	Pair<T, U>(T value) : first(value)  {}
	Pair<T, U>() = default;
	Pair<T, U>(Pair<T,U> & old) : first(old.first), second(old.second), index(old.index) {}
	Pair<T, U>(Pair<T, U>&& old) : first(old.first), second(old.second), index(old.index) {}
	~Pair<T, U>() {}
	Pair<T, U>& operator= (const Pair<T, U>& old)
	{
		first = old.first;
		second = old.second;
		index = old.index;
		return *(this);
	} 
};

template<class K, class V>
class Map {
	Pair<K, V>  * colection_;
	unsigned int curent_;
	unsigned int capacity_;

	bool reallocation()
	{
		capacity_ *= 2;
		Pair<K,V> * tmp = new Pair<K, V>[capacity_];
		if (tmp == nullptr)
			return false;
		for (unsigned int i = 0; i < curent_; i++)
		{
			tmp[i] = colection_[i];
		}

		delete[] colection_;
		colection_ = tmp;
		return true;
	}

	int getIndexOf(K key)
	{
		for (unsigned int i = 0; i < curent_; i++)
		{
			if (colection_[i].first == key)
				return i;
		}
		return -1;
	}


public:
	Map()
	{
		colection_ = new Pair<K, V>[1];
		curent_ = 0;
		capacity_ = 1;
	}

	class iterator
	{
		Pair<K, V>* ptr_;
	public:
		iterator(Pair<K, V>* _ptr) : ptr_(_ptr){}

		iterator operator++()
		{
			iterator i = *this;
			ptr_++;
			return i;
		}

		Pair<K,V> & operator*()
		{ 
			return *ptr_;
		}

		Pair<K,V> * operator->()
		{
			return ptr_;
		}

		bool operator==(const iterator& rhs)
		{
			return ptr_ == rhs.ptr_;
		}

		bool operator!=(const iterator& rhs)
		{
			return ptr_ != rhs.ptr_;
		}
	};


	V& operator[] (K key)
	{
		int index = getIndexOf(key);
		if (index != -1) 
			return colection_[index].second;
		
		if (curent_ == capacity_)
			reallocation();
		colection_[curent_].index = curent_;
		colection_[curent_].first = key;
		curent_++;
		return colection_[curent_ - 1].second;
	}

	iterator begin()
	{
		return iterator(colection_);
	}

	iterator end()
	{
		return iterator(colection_ + curent_);
	}

	iterator begin() const
	{
		return iterator(colection_);
	}

	iterator end() const
	{
		return iterator(colection_ + curent_);
	}

	void Set(K& key, V& value)
	{
		int index = getIndexOf(key);
		if (index != -1)
		{
			colection_[index].second = value;
		}
		else
		{
			if (curent_ == capacity_)
				reallocation();
			colection_[curent_].index = curent_;
			colection_[curent_].first = key;
			colection_[curent_].second = value;
			curent_++;
		}
	}

	bool Get(const K& key, V& value)
	{
		int index = getIndexOf(key);
		if (index == -1)
			return false;
		value = colection_[index].second;
		return true;
	}

	unsigned int Count()
	{
		return curent_;
	}

	bool Delete(const K key)
	{
		int index = getIndexOf(key);
		if (index == -1)
			return false;
		curent_--;
		colection_[index] = colection_[curent_];
		colection_[index].index = index;
		return true;
	}

	void Clear()
	{
		delete[] colection_;
		colection_ = new Pair<K, V>[1];
		curent_ = 0;
		capacity_ = 1;
	}

	bool Includes(const Map<K, V>& map)
	{
		for(auto item: map)
			if (getIndexOf(item.first) == -1)
				return false;
		return true;
	}
};

#endif // !MY_MAP_H
