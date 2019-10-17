#pragma once
#include <vector>
#include <algorithm>

class SortedArray {
public:
 	void AddNumber(int num);

 	std::vector<int> GetSortedAscending() const;
 	std::vector<int> GetSortedDescending() const;
 	int GetMax() const;
 	int GetMin() const;

private:
 	std::vector<int> numbers_;
};
