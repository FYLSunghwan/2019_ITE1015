#include <iostream>
#include <string>
#include "message_book.h"

int main()
{
    MessageBook mb;
    while(true)
    {
        std::string inp;
        std::cin >> inp;

        if(inp == "add")
        {
            int n;
            std::string inp2;
            std::cin >> n;
            std::cin.ignore(1);
            std::getline(std::cin, inp2);
            mb.AddMessage(n, inp2);
        }
        else if(inp == "print")
        {
            int n;
            std::cin >> n;
            std::cout << mb.GetMessage(n) << std::endl;
        }
        else if(inp == "list")
        {
            std::vector<int> ls;
            ls = mb.GetNumbers();
            for(auto &i:ls)
            {
                std::cout << i << ":" << mb.GetMessage(i) << std::endl;
            }
        }
        else if(inp == "delete")
        {
            int n;
            std::cin>>n;
            mb.DeleteMessage(n);
        }
        else if(inp == "quit")
        {
            break;
        }
    }
    return 0;
}