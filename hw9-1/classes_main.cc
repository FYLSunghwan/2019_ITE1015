#include <iostream>
#include <vector>
#include "classes.h"

int main()
{
    std::vector<A*> objs = {new A, new B, new C};
    for(auto &i : objs)
    {
        i->test();
        delete i;
    }
    return 0;
}