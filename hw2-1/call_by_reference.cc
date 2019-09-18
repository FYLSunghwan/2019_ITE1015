//HW2-1-2 call_by_reference.cc
#include <iostream>

void square(double& dvar)
{
    dvar *= dvar;
}

int main()
{
    double dvar;
    std::cin >> dvar;
    square(dvar);
    std::cout << std::fixed;
    std::cout.precision(6);
    std::cout << dvar;
    return 0;
}