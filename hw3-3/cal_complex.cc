#include <iostream>
using namespace std;

struct Comp
{
    double real;
    double comp;
    Comp operator+ (const Comp &rhs) const
    {
        Comp newdata;
        newdata.real = real + rhs.real;
        newdata.comp = comp + rhs.comp;
        return newdata;
    }
    Comp operator* (const Comp &rhs) const
    {
        Comp newdata;
        newdata.real = real*rhs.real - comp*rhs.comp;
        newdata.comp = real*rhs.comp + comp*rhs.real;
        return newdata;
    }
};

void printComplex(const Comp &a)
{
    cout << std::fixed;
    cout.precision(6);
    cout << a.real << " + " << a.comp << "i" << endl;
}

void printMulComp(const Comp &front, const Comp &back)
{
    Comp mul = front * back;
    printComplex(mul);
}

void printAddComp(const Comp &front, const Comp &back)
{
    Comp add = front + back;
    printComplex(add);
}

int main()
{
    Comp a, b;
    cin >> a.real >> a.comp >> b.real >> b.comp;
    for(int i=1; i<=2; i++)
    {
        cout << "복소수 " << i << ":" << endl;
        printComplex(a);
    }
    cout << "두 복소수의 합:" << endl;
    printAddComp(a, b);

    cout << "두 복소수의 곱:" << endl;
    printMulComp(a, b);

    return 0;
}