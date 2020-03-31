#include<iostream>
#include "Booleans.h"

#ifndef ARRAY_H
#define ARRAY_H

template <class T = int>
class Array
{
	T* arr = nullptr;
	unsigned int capacity;
    unsigned int current;
public:
	Array(){
		arr = new T[1];
		capacity = 1;
		current = 0;
	}

    // add element at the last
    void push(T data)
    {
        if (current == capacity)
		{
			T* tmp = new T[2 * capacity];
            if (tmp == nullptr)
                throw;
			for (unsigned int i = 0; i < capacity; i++)
			{
				tmp[i] = arr[i];
			}

			delete[] arr;
			capacity *= 2;
			arr = tmp;
		}

		arr[current] = data;
		current++;
    }

    // delete last element 
    T pop()
    {
        current = current - 1;
        if (current < 0) {
            current = 0;
            throw;
        }
        return arr[current];
    }

    // deletes an element from a specific index in the vector
    void remove(unsigned int index)
    {
        if (index > current)
            return;

        current--;

        for (int i = index; i < current; i++)
            arr[i] = arr[i + 1];
    }

    // insert element at any index 
    void insert(T data, unsigned int index)
    {
        if (index > current)
            throw;
        
        if(current == capacity)
        {
            T* tmp = new T[2 * capacity];

            for (unsigned int i = 0; i < capacity; i++)
            {
                tmp[i] = arr[i];
            }

            delete[] arr;
            capacity *= 2;
            arr = tmp;
        }

        for (unsigned int i = capacity; i > index; i--)
        {
            arr[i] = arr[i - 1];
        }

        arr[index] = data;
        current++;
    }

    // sort all elements in the vector
    void sort( bool(*ptr)(T,T) = nullptr)
    {
        if (ptr == nullptr)
            ptr = cmp;
        int j;
        T key;
        for (unsigned int i = 1; i < current; i++)
        {
            key = arr[i];
            j = i - 1;

            /* Move elements of arr[0..i-1], that are
            greater than key, to one position ahead
            of their current position */
            while (j >= 0 && ptr(key, arr[j]))
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

    // extract element at any index 
    T get(unsigned int index)
    {
        if (index < current)
            return arr[index];
        throw;
    }

    // ovewrite a value in array
    void set(T data, unsigned int index)
    {
        if (index < current)
            arr[index] = data;
    }

    // return first index of data acording ptr
    int firstIndexOf(T data, bool(*ptr)(T, T) = nullptr)
    {
        if (ptr == nullptr)
            ptr = eql;
        for (unsigned int i = 0; i < current; i++)
            if (ptr(data, arr[i]))
                return i;
        return -1;
    }

    // get size of the vector 
    unsigned int count()
    {
        return current;
    }

    // function to get capacity of the vector 
    unsigned int getcapacity()
    {
        return capacity;
    }

    // function to print array elements 
    void print()
    {
        for (unsigned int i = 0; i < current; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

#endif
