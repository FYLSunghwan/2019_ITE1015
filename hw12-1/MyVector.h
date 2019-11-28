#ifndef __MVE_H_
#define __MVE_H_

#include "MyContainer.h"

template <typename T>
class MyVector : public MyContainer<T>
{
	private:
		int capacity;

	public:
		MyVector();
		MyVector(int n);
		MyVector(T* arr, int n);
		bool empty();
		int size();
		int max_size();
		void reserve(int new_cap);
		void push_back(T obj);
		void pop_back();
		T& front();
		T& back();
		T& at(int idx);
		T& operator[](const int& i);
		MyVector<T> operator+(const MyVector<T>& rhs);
};

#endif
