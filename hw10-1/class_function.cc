#include "class_function.h"
#include <iostream>

void A::test1()
{
    std::cout << "A::test1()" << std::endl;
}

void B::test2()
{
    std::cout << "B::test2()" << std::endl;
}

void C::test1()
{
    std::cout << "C:test1()" << std::endl;
}

void C::test2()
{
    std::cout << "C::test2()" << std::endl;
}

void BB::test1()
{
    std::cout << "BB::test1()" << std::endl;
}