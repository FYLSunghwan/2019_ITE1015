#include "integer_set.h"
#include <algorithm>
#include <iostream>

void IntegerSet::AddNumber(int num)
{
    for(auto it : numbers_)
    {
        if(it == num) return;
    }
    numbers_.push_back(num);
    std::sort(numbers_.begin(), numbers_.end());
}

void IntegerSet::PrintItem()
{
    for(auto it:numbers_)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

void IntegerSet::DeleteNumber(int num)
{
    for(auto it = numbers_.begin(); it != numbers_.end();)
    {
        if(*it == num) it = numbers_.erase(it);
        else it++;
    }
}

int IntegerSet::GetItem(int pos) const
{
    if(pos>=numbers_.size()) return -1;
    else return numbers_[pos];
}