#include "class_function.h"
#include <vector>
#include <iostream>
#include <string>

int main()
{
    std::vector<A*> objects;
    std::string inp;
    while(true)
    {
        std::cin >> inp;
        if(inp=="0") break;
        if(inp=="B") objects.push_back(new B);
        if(inp=="C") objects.push_back(new C);
        if(inp=="BB") objects.push_back(new BB);
    }
    for(auto& i:objects)
    {
        i->test1();
        i->test2();
        delete i;
    }
    return 0;
}