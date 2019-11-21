#include "MyVector.h"

MyVector::MyVector() : len_(0), arr_(nullptr) 
{
    // Do Nothing
}

MyVector::MyVector(int len)
{
    len_ = len;
    arr_ = new int[len];
}

MyVector::MyVector(MyVector const& vec) : MyVector(vec.len_)
{
    for (size_t i = 0; i < len_; ++i) {
        arr_[i] = vec.arr_[i];
    }
}

MyVector::~MyVector()
{
    if(arr_ != nullptr)
        delete[] arr_;
}

MyVector& MyVector::operator=(MyVector const& vec) {
    if (arr_ != nullptr) {
        delete[] arr_;
    }

    len_ = vec.len_;
    arr_= new int[len_];

    for (size_t i = 0; i < len_; ++i) {
        arr_[i] = vec.arr_[i];
    }

    return *this;
}

MyVector& MyVector::operator=(MyVector&& vec)
{
    if (arr_ != nullptr) {
        delete[] arr_;
    }

    len_ = vec.len_;
    arr_ = vec.arr_;
    vec.arr_ = nullptr;

    return *this;
}

MyVector MyVector::operator+(const MyVector& a) const
{
    MyVector vec(len_);
    for(int i=0;i<len_;i++)
    {
        vec.arr_[i] = arr_[i] + a.arr_[i];
    }
    return vec;
}

MyVector MyVector::operator-(const MyVector& a) const
{
    MyVector vec(len_);
    for(int i=0;i<len_;i++)
    {
        vec.arr_[i] = arr_[i] - a.arr_[i];
    }
    return vec;
}

MyVector MyVector::operator+(const int a) const
{
    MyVector vec(len_);
    for(int i=0;i<len_;i++)
    {
        vec.arr_[i] = arr_[i] + a;
    }
    return vec;
}

MyVector MyVector::operator-(const int a) const
{
    MyVector vec(len_);
    for(int i=0;i<len_;i++)
    {
        vec.arr_[i] = arr_[i] - a;
    }
    return vec;
}

std::ostream& operator<<(std::ostream& out, const MyVector& b)
{
    for(int i=0;i<b.len_;i++)
    {
        out << b.arr_[i] << " ";
    }
    return out;
}

std::istream& operator>>(std::istream& in, MyVector& b)
{
    for(int i=0;i<b.len_;i++)
    {
        in >> b.arr_[i];
    }
    return in;
}