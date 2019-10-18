#include "simple_int_set.h"
#include <iostream>

std::set<int> SetIntersection(const std::set<int>& set0, const std::set<int>& set1)
{
    std::set<int> ret;
    for(auto it : set0)
    {
        if(set1.find(it) != set1.end()) ret.emplace(it);
    }
    return ret;
}

std::set<int> SetUnion(const std::set<int>& set0, const std::set<int>& set1)
{
    std::set<int> ret(set0);
    for(auto it : set1)
    {
        ret.emplace(it);
    }
    return ret;
}

std::set<int> SetDifference(const std::set<int>& set0, const std::set<int>& set1)
{
    std::set<int> ret(set0);
    for(auto& it : set1)
    {
        if(ret.find(it) != ret.end()) ret.erase(it);
    }
    return ret;
}

bool ParseOperation(std::istream& is, std::set<int>& set0)
{
    std::string inp;
    is >> inp;
    if(inp != "{") return false;
    while(true)
    {
        int num;
        is >> num;
        if(is.fail()) break;

        set0.emplace(num);
    }
    is.clear();
    is >> inp;
    if(inp != "}") return false;
    return true;  
}

void PrintSet(std::ostream& os, std::set<int>& set0)
{
    if(!set0.size())
    {
        os << std::endl;
        return;
    }
    os << "{ ";
    for(auto it:set0)
    {
        os << it << " ";
    }
    os << "}" << std::endl;
}