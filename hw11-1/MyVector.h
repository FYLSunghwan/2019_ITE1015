#pragma once

#include <iostream>

class MyVector
{
private:
    int len_;
    int* arr_;
public:
    //Constructor, Destructor
    MyVector(int len);
    MyVector();
    ~MyVector();
    MyVector(MyVector const& vec);
    MyVector& operator=(MyVector&& vec);
    MyVector& operator=(MyVector const& vec);
    MyVector operator+(const MyVector & a) const;
    MyVector operator-(const MyVector & a) const;
    MyVector operator+(const int a) const;
    MyVector operator-(const int a) const;
    friend std::ostream& operator << (std::ostream& out, const MyVector& b);
    friend std::istream& operator >> (std::istream& in, MyVector& b);
};
