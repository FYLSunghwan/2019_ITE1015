#include "calendar.h"
#include <iostream>
#include <string>

int main()
{
    Date date;
    while(true)
    {
        std::string inp;
        std::cin >> inp;

        if(inp == "set")
        {
            std::cin >> date;
        }
        else if(inp == "next_day")
        {
            date.NextDay(1);
            std::cout << date << std::endl;
        }
        else if(inp == "next")
        {
            int offset;
            std::cin >> offset;
            date.NextDay(offset);
            std::cout << date << std::endl;
        }
        else if(inp == "quit") break;
    }
    return 0;
}