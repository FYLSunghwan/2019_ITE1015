//HW2-1-1 array_pointer.cc
#include <iostream>

int main()
{
    double douArr[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    double* parr = douArr;
    for(int i=0; i<5; i++) *(parr+i) *= 2;
    std::cout << std::fixed;
    std::cout.precision(6);
    for(int i=0; i<5; i++) std::cout << *(parr+i) << std::endl;
    return 0;
}