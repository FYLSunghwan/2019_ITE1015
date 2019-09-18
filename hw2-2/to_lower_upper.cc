//HW2-2-2 to_lower_upper.cc
#include <iostream>

int main()
{
    char inpStr[10];
    std::cin >> inpStr;
    for(int i=0; inpStr[i]; i++)
    {
        if(inpStr[i]<97) inpStr[i] += 'a'-'A';
        else inpStr[i] -= 'a'-'A';
    }
    std::cout << inpStr << std::endl;
    return 0;
}