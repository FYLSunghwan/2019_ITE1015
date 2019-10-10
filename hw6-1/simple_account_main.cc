#include <iostream>
#include "simple_account.h"

int main()
{
    AccountManager acm;
    while(true)
    {
        char c;
        std::cout << "\nJob?\n";
        std::cin >> c;
        
        if(c=='Q') break;
        if(c=='N') acm.AddAccount();
        if(c=='D')
        {
            int id, money;
            std::cin>>id>>money;
            acm.Deposit(id, money);
        }
        if(c=='W')
        {
            int id, money;
            std::cin>>id>>money;
            acm.Withdraw(id, money);
        }
        if(c=='T')
        {
            int srcid, tarid, money;
            std::cin>>srcid>>tarid>>money;
            acm.Transfer(srcid, tarid, money);
        }
    }
    return 0;
}