#include "MyVector.h"
#include "MyContainer.h"
#include "MyContainer.cpp"
#include <iostream>

template <typename T>
MyVector<T>::MyVector()
	:MyContainer<T>()
{
	capacity = 0;
}

template <typename T>
MyVector<T>::MyVector(int n)
	:MyContainer<T>(n)
{
	capacity = n;
}

template <typename T>
MyVector<T>::MyVector(T* arr, int n)
	:MyContainer<T>(arr, n)
{
	capacity = n;
}

template <typename T>
bool MyVector<T>::empty()
{
	return this->n_ele==0;
}

template <typename T>
int MyVector<T>::size()
{
	return this->n_ele;
}

template <typename T>
int MyVector<T>::max_size()
{
	return capacity;
}

template <typename T>
void MyVector<T>::reserve(int new_cap)
{
	if(capacity==new_cap)
	{
		T* tmp = this->obj_arr;
		const int tmpcap = capacity;
		const int updcap = capacity?capacity*2:1;
		this->obj_arr = new T[updcap];
		for(int i=0;i<tmpcap;i++)
		{
			this->obj_arr[i] = tmp[i];
		}
		if(tmp!=nullptr)
		{
			delete[] tmp;
		}
		capacity = updcap;
	}
}

template <typename T>
void MyVector<T>::push_back(T obj)
{
	reserve(this->n_ele);
	++(this->n_ele);
	this->back() = obj;
}

template <typename T>
void MyVector<T>::pop_back()
{
	--(this->n_ele);
}

template <typename T>
T& MyVector<T>::front()
{
	return *(this->obj_arr);
}

template <typename T>
T& MyVector<T>::back()
{
	return *(this->obj_arr+this->n_ele-1);
}
	
template <typename T>
T& MyVector<T>::at(int idx)
{
	return *(this->obj_arr + idx);
}

template <typename T>
T& MyVector<T>::operator[](const int& i)
{
	return at(i);
}

template <typename T>
MyVector<T> MyVector<T>::operator+(const MyVector<T>& rhs)
{
	const int tot = this->n_ele + rhs.n_ele;
	MyVector<T> out(tot);
	for(int i=0;i<this->n_ele;i++)
	{
		out[i] = this->obj_arr[i];
	}
	const int sz = rhs.n_ele;
	for(int i=0;i<sz;i++)
	{
		out[i+this->n_ele] = rhs.obj_arr[i];
	}
	return out;
}