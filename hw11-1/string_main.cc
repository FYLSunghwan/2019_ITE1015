#include "string.h"
#include <iostream>
#include <string>

int main()
{
    std::string inp;
    MyString a;
    MyString b;
    while(true)
    {
        std::cin >> inp;
        if(inp == "new")
        {
            std::cout << "enter a" << std::endl;
            std::cin >> a;
            std::cout << "enter b" << std::endl;
            std::cin >> b;
            continue;
        }
        else if(inp == "quit")
        {
            break;
        }
        else
        {
            std::string rhs, oper;
            std::cin >> oper >> rhs;
            if(oper == "*")
            {
                if(inp == "a")
                {
                    std::cout << a*stoi(rhs);
                }
                if(inp == "b")
                {
                    std::cout << b*stoi(rhs);
                }
            }
            else
            {
                if(inp == "a")
                {
                    if(rhs=="a") std::cout << a+a;
                    if(rhs=="b") std::cout << a+b;
                }
                if(inp == "b")
                {
                    if(rhs=="a") std::cout << b+a;
                    if(rhs=="b") std::cout << b+b;
                }
            }
            std::cout << std::endl;
            
        }
        
    }
    return 0;
}