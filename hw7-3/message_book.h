#pragma once
#include <map>
#include <string>
#include <vector>

class MessageBook {
 public:
  void AddMessage(int number, const std::string& message);
  void DeleteMessage(int number);
  std::vector<int> GetNumbers() const;
  const std::string& GetMessage(int number) const;

 private:
  std::map<int, std::string> messages_;
};
