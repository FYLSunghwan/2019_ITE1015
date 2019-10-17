#include <iostream>
#include <sstream>
#include <string>
#include "sorted_array.h"

void PrintScreen(std::vector<int>&& vec)
{
    for(auto i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void PrintScreen(int k)
{
    std::cout << k << std::endl;
}

std::vector<std::string> tokenize_getline(std::string str)
{
    std::vector<std::string> result;
    std::string token;
    std::stringstream ss(str);

    while(getline(ss, token, ' ')) result.push_back(token);
    return result;
}

int main()
{
    SortedArray sa;
    std::string inp;
    while(true)
    {
        std::getline(std::cin, inp);
        if(inp == "ascend")
        {
            PrintScreen(sa.GetSortedAscending());
        }
        else if(inp == "descend")
        {
            PrintScreen(sa.GetSortedDescending());
        }
        else if(inp == "max")
        {
            PrintScreen(sa.GetMax());
        }
        else if(inp == "min")
        {
            PrintScreen(sa.GetMin());
        }
        else if(inp=="quit")
        {
            break;
        }
        else
        {
            std::vector<std::string> parse;
            parse = tokenize_getline(inp);
            for(auto it:parse)
            {
                sa.AddNumber(std::stoi(it));
            }
        }
        

    }
    return 0;
}