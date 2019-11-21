#include "MyVector.h"
#include <iostream>
#include <string>

int main()
{
    std::string inp;
    MyVector a;
    MyVector b;
    while(true)
    {
        std::cin >> inp;
        if(inp == "new")
        {
            int size;
            std::cin >> size;
            a = MyVector(size);
            b = MyVector(size);
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
            if(inp=="a")
            {
                if(rhs=="a") std::cout << a+a << std::endl;
                else if(rhs=="b") std::cout << a+b << std::endl;
                else std::cout << a+stoi(rhs) << std::endl;
            }
            else if(inp=="b")
            {
                if(rhs=="a") std::cout << b+a << std::endl;
                else if(rhs=="b") std::cout << b+b << std::endl;
                else std::cout << b+stoi(rhs) << std::endl;
            }            
            
        }
        
    }
    return 0;
}