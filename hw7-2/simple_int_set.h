#pragma once

#include <set>
#include <string>

std::set<int> SetIntersection(const std::set<int>& set0, const std::set<int>& set1);
std::set<int> SetUnion(const std::set<int>& set0, const std::set<int>& set1);
std::set<int> SetDifference(const std::set<int>& set0, const std::set<int>& set1);
bool ParseOperation(std::istream& is, std::set<int>& set0);
void PrintSet(std::ostream& os, std::set<int>& set0);