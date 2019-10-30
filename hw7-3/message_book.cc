#include "message_book.h"

void MessageBook::AddMessage(int number ,const std::string& message)
{
    messages_[number] = message;
}

void MessageBook::DeleteMessage(int number)
{
    if(messages_.find(number) != messages_.end())
        messages_.erase(number);
}

std::vector<int> MessageBook::GetNumbers() const
{
    std::vector<int> out;
    for(auto& it : messages_)
    {
        out.push_back(it.first);
    }
    return out;
}

const std::string& MessageBook::GetMessage(int number) const
{
    static std::string emp = " ";
    if(messages_.find(number) == messages_.end()) return emp;
    else return messages_.at(number);
}