#include "dynamic_cast.h"
#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<B*> objects;
    std::string inp;
    while(true)
    {
        std::cin >> inp;
        if(inp=="0") break;
        if(inp=="B") objects.push_back(new B);
        if(inp=="C") objects.push_back(new C);
        if(inp=="D") objects.push_back(new D);
    }
    for(auto& i:objects)
    {
        C* c = dynamic_cast<C*>(i);
        if(c!=NULL)
        {
            c->test_C();
        }
        D* d = dynamic_cast<D*>(i);
        if(d!=NULL)
        {
            d->test_D();
        }
    }
    return 0;
}