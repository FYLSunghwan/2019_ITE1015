#pragma once
#include <vector>
#include <algorithm>

class IntegerSet {
	public:

		void AddNumber(int num);
		void DeleteNumber(int num);
        void PrintItem();

		int GetItem(int pos) const;

	private:
		std::vector<int> numbers_;
};