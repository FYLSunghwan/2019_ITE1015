#include <iostream>
#include "integer_set.h"

int main()
{
    std::string inp;
    int num;
    IntegerSet intset;

    while(true)
    {
        std::cin >> inp;
        if(inp == "add") 
        {
            std::cin>>num;
            intset.AddNumber(num);
            intset.PrintItem();
        }
        if(inp == "del")
        {
            std::cin>>num;
            intset.DeleteNumber(num);
            intset.PrintItem();
        }
        if(inp == "get")
        {
            std::cin >> num;
            std::cout << intset.GetItem(num) << std::endl;
        }
        if(inp=="quit") break;
    }
    return 0;
}