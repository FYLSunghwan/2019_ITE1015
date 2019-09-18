//HW3-1-2 rotate_integer.cc
#include <iostream>

void rotateLeft(int* pa, int* pb, int* pc)
{
    int t = *pa;
    *pa = *pb;
    *pb = *pc;
    *pc = t;
}

void rotateRight(int* pa, int* pb, int* pc)
{
    int t = *pc;
    *pc = *pb;
    *pb = *pa;
    *pa = t;
}

int main(void)
{
    int a=10, b=20, c=30, inpNum=1;
    while(1)
    {
        std::cout << a << ":" 
                  << b << ":"
                  << c << ":"
                  << std::endl;
        std::cin >> inpNum;
        if(inpNum == 1) rotateLeft(&a, &b, &c);
        else if(inpNum == 2) rotateRight(&a, &b, &c);
        else break;
    }
    return 0;
}