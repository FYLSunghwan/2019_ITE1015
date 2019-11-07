#include "print_member.h"
#include <iostream>
#include <string>
#include <vector>

int main()
{
    int par1;
    double par2;
    std::string par3;

    std::cin >> par1 >> par2 >> par3;
    A* a = new A(par1);
    A* b = new B(par2);
    A* c = new C(par3);

    std::vector<A*> objs = {a, b, c};

    for(auto& i : objs)
    {
        i->print();
    }
    for(auto& i : objs)
    {
        delete i;
    }
    return 0;
}