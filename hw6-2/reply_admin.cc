#include "reply_admin.h"
#include <algorithm>

ReplyAdmin::ReplyAdmin()
{
    chats = new std::string[200];
    m_num = 0;
}

ReplyAdmin::~ReplyAdmin()
{
    delete[] chats;
}

void ReplyAdmin::printChats()
{
    if(!m_num) std::cout << "No Existing Chats" << std::endl;
    else
    {
       for(std::size_t i = 0; i<m_num; i++)
       {
          std::cout << i << " " << chats[i] << std::endl;
       }
    }
}

std::size_t ReplyAdmin::getChatCount()
{
    return m_num;
}

bool ReplyAdmin::addChat(std::string _chat)
{
    if(m_num>=NUM_OF_CHAT) return false;
    chats[m_num] = _chat;
    m_num += 1;
    printChats();
    return true;
}

bool ReplyAdmin::removeChat(int _index)
{
    if(_index >= m_num) return false;
    m_num--;
    for(std::size_t i = _index; i<m_num;i++)
    {
        chats[i] = chats[i+1];
    }
    printChats();
    return true;
}

bool ReplyAdmin::removeChat(int _start, int _end)
{
    _start = std::max(0, _start);
    _end = std::min((int)(m_num-1), _end);
    
    bool condition = _start>_end || _end >= m_num;
    if(condition) return false;

    m_num -= (_end - _start + 1);
    for(std::size_t i = _start; i < m_num; i++)
    {
        chats[i] = chats[i+(_end - _start + 1)];
    }
    printChats();
    return true;
}