#include <iostream>
#include <vector>
#include "clock_time.h"

int main()
{
    int ticks;
    std::vector<Clock*> clocks;
    clocks.push_back(new SundialClock(0,0,0));
    clocks.push_back(new CuckooClock(0,0,0));    
    clocks.push_back(new GrandFatherClock(0,0,0));
    clocks.push_back(new WristClock(0,0,0));
    clocks.push_back(new AtomicClock(0,0,0));
    std::cin >> ticks;
    std::cout << "Reported clock times after resetting:" << std::endl;
    for(auto& i : clocks)
    {
        i->reset();
        i->displayTime();
    }

    std::cout << "\nRunning the clocks...\n" << std::endl;

    while(ticks--)
    {
        for(auto& i : clocks)
        {
            i->tick();
        }
    }

    std::cout << "Reported clock times after resetting:" << std::endl;
    for(auto& i : clocks)
    {
        i->displayTime();
        delete i;
    }
    return 0;
}