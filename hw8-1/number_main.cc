#include "number.h"
#include <iostream>
#include <string>

int main()
{
    while(true)
    {
        std::string inp;
        int n;
        std::cin >> inp >> n;
        if(inp == "number")
        {
            Number numObj;
            numObj.setNumber(n);
            std::cout << "getNumber(): " << numObj.getNumber() << std::endl;
        }
        if(inp == "square")
        {
            Square sqObj;
            sqObj.setNumber(n);
            std::cout << "getNumber(): " << sqObj.getNumber() << std::endl;
            std::cout << "getSquare(): " << sqObj.getSquare() << std::endl;            
        }        
        if(inp == "cube")
        {
            Cube cubObj;
            cubObj.setNumber(n);
            std::cout << "getNumber(): " << cubObj.getNumber() << std::endl;
            std::cout << "getSquare(): " << cubObj.getSquare() << std::endl; 
            std::cout << "getCube(): " << cubObj.getCube() << std::endl;  
        }
        if(inp == "quit") break;
    }
    return 0;
}