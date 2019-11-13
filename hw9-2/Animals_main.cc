#include <iostream>
#include <vector>
#include "Animals.h"

int main()
{
    std::vector<Animal*> animals;
    while(true)
    {
        std::string inp;
        std::cin >> inp;
        if(inp == "z")
        {
            std::string name;
            int age;
            int numStripes;
            std::cin >> name >> age >> numStripes;
            animals.push_back(new Zebra(name, age, numStripes));
        }
        if(inp == "c")
        {
            std::string name;
            int age;
            std::string favoriteToy;
            std::cin >> name >> age >> favoriteToy;
            animals.push_back(new Cat(name, age, favoriteToy));
        }
        if(inp == "0")
        {
            break;
        }
    }
    for(auto& i: animals)
    {
        i->printInfo();
        delete i;
    }
    return 0;
}