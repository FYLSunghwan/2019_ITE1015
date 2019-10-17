#include <algorithm>
#include <functional>
#include "sorted_array.h"

void SortedArray::AddNumber(int num)
{
    numbers_.push_back(num);
    std::sort(numbers_.begin(), numbers_.end());
}

std::vector<int> SortedArray::GetSortedAscending() const
{
    return numbers_;
}

std::vector<int> SortedArray::GetSortedDescending() const
{
    std::vector<int> newnum = numbers_;
    std::reverse(newnum.begin(), newnum.end());
    return newnum;
}

int SortedArray::GetMax() const
{
    return numbers_.back();
}

int SortedArray::GetMin() const
{
    return numbers_.front();
}