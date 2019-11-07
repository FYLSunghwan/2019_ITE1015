#include "print_member.h"
#include <iostream>

A::A(int par)
{
    memberA = new int(par);
    std::cout << "new memberA" << std::endl;
}

B::B(double par) : A(1)
{
    memberB = new double(par);
    std::cout << "new memberB" << std::endl;
}

C::C(std::string par) : B(1.1)
{
    memberC = new std::string(par);
    std::cout << "new memberC" << std::endl;
}

A::~A()
{
    delete memberA;
    std::cout << "delete memberA" << std::endl;
}

B::~B()
{
    delete memberB;
    std::cout << "delete memberB" << std::endl;
}

C::~C()
{
    delete memberC;
    std::cout << "delete memberC" << std::endl;
}

void A::print()
{
    std::cout << "*memberA " <<  *memberA << std::endl;
}

void B::print()
{
    A::print();
    std::cout << "*memberB "<< *memberB << std::endl;
}

void C::print()
{
    B::print();
    std::cout << "*memberC "<< *memberC << std::endl;
}