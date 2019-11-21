#pragma once

#include <iostream>
#include <string>

class MyString
{
private:
    int len_;
    char* arr_;
public:
    //Constructor, Destructor
    MyString();
    MyString(int vec);
    ~MyString();
    MyString(MyString const& vec);
    MyString& operator=(MyString&& vec);
    MyString& operator=(MyString const& vec);
    MyString operator+(const MyString & a) const;
    MyString operator*(const int a) const;    
    friend std::ostream& operator << (std::ostream& out, const MyString& b);
    friend std::istream& operator >> (std::istream& in, MyString& b);
};
