#pragma once
#include <string>

class A
{
 public:
    A(int par);
    virtual ~A();
    virtual void print();
 private:
    int* memberA;
};

class B : public A
{
 public:
    B(double par);
    virtual ~B();
    virtual void print();
 private:
    double* memberB;
};

class C : public B
{
 public:
    C(std::string par);
    virtual ~C();
    virtual void print();
 private:
    std::string* memberC;
};

