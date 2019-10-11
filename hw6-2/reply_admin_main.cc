#include <iostream>
#include "reply_admin.h"

int main()
{
    ReplyAdmin rep;
    while(true)
    {
        std::string inputs;
        getline(std::cin, inputs);

        if(inputs == "#quit") break;
        else if(inputs.find("#remove") != std::string::npos)
        {
            if(inputs.find("-") != std::string::npos)
            {
                int idx_st = inputs.find("ve")+ 3;
                int idx_mid = inputs.find("-");
                int start = std::stoi(inputs.substr(idx_st, idx_mid - idx_st));
                int ed = std::stoi(inputs.substr(idx_mid + 1));
                if(!rep.removeChat(start, ed)) std::cout << "Remove Failed" << std::endl;
            }
            else
            {
                int idx_st = inputs.find("ve") + 3;
                int idx = std::stoi(inputs.substr(idx_st));
                if(!rep.removeChat(idx)) std::cout << "Remove Failed" << std::endl;
            }
        }
        else
        {
            if(!rep.addChat(inputs)) std::cout << "Add Failed" << std::endl;
        }
    }
    return 0;
}