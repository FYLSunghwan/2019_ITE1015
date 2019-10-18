#include <iostream>
#include <set>
#include <string>
#include "simple_int_set.h"

enum class Operation
{
    NONE,
    UNION,
    DIFFERENCE,
    INTERSECTION
};

int main()
{
    std::set<int> res, set0, set1;
    Operation state = Operation::NONE;
    while(true)
    {
        if(!ParseOperation(std::cin, set0)) break;
        std::string oper;

        std::cin >> oper;
        if(oper == "+") state = Operation::UNION;
        else if(oper == "-") state = Operation::DIFFERENCE;
        else if(oper == "*") state = Operation::INTERSECTION;

        std::cin.clear();
        if(!ParseOperation(std::cin, set1)) break;
        
        if(state == Operation::UNION) res = SetUnion(set0, set1);
        if(state == Operation::DIFFERENCE) res = SetDifference(set0, set1);
        if(state == Operation::INTERSECTION) res = SetIntersection(set0, set1);

        PrintSet(std::cout, res);
    }
    return 0;
}