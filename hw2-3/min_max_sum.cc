//HW3-1-1 min_max_sum.cc
#include <iostream>

int main()
{
    int inpArr[5], minNum, maxNum, sumNum=0;
    for(int i=0; i<5; i++) std::cin>>inpArr[i];
    minNum = maxNum = sumNum = inpArr[0];
    for(int i=1; i<5; i++)
    {
        if(inpArr[i] > maxNum) maxNum = inpArr[i];
        if(inpArr[i] < minNum) minNum = inpArr[i];
        sumNum += inpArr[i];
    }
    std::cout << "min: " << minNum << std::endl;
    std::cout << "max: " << maxNum << std::endl;
    std::cout << "sum: " << sumNum << std::endl;
    return 0;
}