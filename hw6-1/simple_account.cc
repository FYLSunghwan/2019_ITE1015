#include "simple_account.h"
#include <iostream>

void AccountManager::AddAccount()
{
    if(accAmt>10)
    {
        std::cout << "Overflow" << std::endl;
        return;
    }
    accAmt++;
    std::cout << "Account for user " << accAmt-1 <<" registered" << std::endl;
    GetBalance(accAmt-1);
}

void AccountManager::Deposit(int id, int money)
{
    if(id>=accAmt) {
        std::cout << "Account does not exist" << std::endl;
        return;
    }
    else if(m_account[id].money+money>1000000) std::cout << "Failure: Deposit to user " << id << " " << money << std::endl;
    else
    {
        m_account[id].money+=money;
        std::cout << "Success: Deposit to user " << id << " " << money << std::endl;
    }
    GetBalance(id);
}

void AccountManager::Withdraw(int id, int money)
{
    if(id>=accAmt) {
        std::cout << "Account does not exist" << std::endl;
        return;
    }
    else if(m_account[id].money-money<0) std::cout << "Failure: Withdraw from user " << id << " " << money << std::endl;
    else
    {
        m_account[id].money-=money;
        std::cout << "Success: Withdraw from user " << id << " " << money << std::endl;
    }
    GetBalance(id);
}

void AccountManager::Transfer(int srcid, int tarid, int money)
{
    if(srcid>=accAmt || tarid>=accAmt) {
        std::cout << "Account does not exist" << std::endl;
        return;
    }
    else if(m_account[srcid].money-money <0 || m_account[tarid].money + money > 1000000)
    {
        std::cout << "Failure: Transfer from user " << srcid << " to user " << tarid << " " << money << std::endl;
    }
    else
    {
        m_account[srcid].money-=money;
        m_account[tarid].money+=money;
        std::cout << "Success: Transfer from user " << srcid << " to user " << tarid << " " << money << std::endl;
    }
    GetBalance(srcid);
    GetBalance(tarid);
}

void AccountManager::GetBalance(int id)
{
    if(id>=accAmt) {
        std::cout << "Account does not exist" << std::endl;
        return;
    }
    std::cout << "Balance of user " << id << ": " << m_account[id].money << std::endl;
}

