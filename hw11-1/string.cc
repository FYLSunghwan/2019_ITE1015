#include "string.h"

MyString::MyString() : len_(0), arr_(nullptr) 
{
    // Do Nothing
}

MyString::MyString(int len)
{
    len_ = len;
    arr_ = new char[len];
}

MyString::MyString(MyString const& vec) : MyString(vec.len_)
{
    for (size_t i = 0; i < len_; ++i) {
        arr_[i] = vec.arr_[i];
    }
}

MyString::~MyString()
{
    if(arr_ != nullptr)
        delete[] arr_;
}

MyString& MyString::operator=(MyString const& vec) {
    if (arr_ != nullptr) {
        delete[] arr_;
    }

    len_ = vec.len_;
    arr_= new char[len_];

    for (size_t i = 0; i < len_; ++i) {
        arr_[i] = vec.arr_[i];
    }

    return *this;
}

MyString& MyString::operator=(MyString&& vec)
{
    if (arr_ != nullptr) {
        delete[] arr_;
    }

    len_ = vec.len_;
    arr_ = vec.arr_;
    vec.arr_ = nullptr;

    return *this;
}

MyString MyString::operator+(const MyString& a) const
{
    MyString vec(len_+a.len_);
    for(int i=0;i<len_;i++)
    {
        vec.arr_[i] = arr_[i];
    }
    for(int i=0;i<len_;i++)
    {
        vec.arr_[i+len_] = a.arr_[i];
    }
    vec.arr_[len_+a.len_] = '\n';
    return vec;
}

MyString MyString::operator*(const int a) const
{
    MyString vec = *this;
    MyString tmp = *this;
    for(int i=0;i<a-1;i++)
    {
        vec = vec + tmp;
    }
    return vec;
}

std::ostream& operator<<(std::ostream& out, const MyString& b)
{
    for(int i=0;i<b.len_;i++)
    {
        out << b.arr_[i];
    }
    return out;
}

std::istream& operator>>(std::istream& in, MyString& b)
{
    std::string inp;
    in >> inp;
    if(b.arr_ != nullptr) delete b.arr_;
    b.arr_ = new char[inp.size()+1];
    b.len_ = inp.size();
    for(int i=0;i<inp.size();i++)
    {
        b.arr_[i] = inp[i];
    }
    b.arr_[inp.size()] = '\n';
    return in;
}