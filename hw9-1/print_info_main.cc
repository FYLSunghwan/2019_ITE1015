#include <iostream>
#include <vector>
#include "print_info.h"

void printObjectTypeInfo1(A* object)
{
    std::cout << object -> getTypeInfo() << std::endl;
}

void printObjectTypeInfo2(A& object)
{
    std::cout << object.getTypeInfo() << std::endl;
}

int main()
{
    std::vector<A*> objs = {new A, new B, new C};
    for(auto &i : objs)
    {
        printObjectTypeInfo1(i);
        printObjectTypeInfo2(*i);
        delete i;
    }
    return 0;
}