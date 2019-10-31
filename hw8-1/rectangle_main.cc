#include <iostream>
#include "rectangle.h"
#include <string>

int main()
{
    while(true)
    {
        std::string inp;
        int width, height;
        std::cin >> inp;
        if(inp == "square")
        {
            std::cin >> width;
            Square sq(width);
            sq.print();
        }
        if(inp == "nonsquare")
        {
            std::cin >> width >> height;
            NonSquare nsq(width, height);
            nsq.print();
        }
        if(inp == "quit") break;
    }
    return 0;
}