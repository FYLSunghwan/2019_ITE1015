#include "world_clock.h"
#include <string>

int main()
{
    WorldClock clock;
    while(true)
    {
        std::string inp;
        std::cin >> inp;
        if(inp == "set")
        {
            std::cin >> clock;
            if(clock.isValid()) std::cout << clock << std::endl;
        }
        else if(inp == "tick")
        {
            int s;
            std::cin >> s;
            clock.Tick(s);
            std::cout << clock << std::endl;
        }
        else if(inp == "quit") break;
    }
    return 0;
}