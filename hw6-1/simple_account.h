#pragma once
#include <vector>

class Account
{
    public:
        int id, money=0;
};

class AccountManager
{
    public:
        AccountManager():accAmt(0) {}
        void AddAccount();
        void Deposit(int id, int money);
        void Withdraw(int id, int money);
        void Transfer(int srcid, int tarid, int money);
        void GetBalance(int id);
    private:
        Account m_account[10];
        int accAmt;
};