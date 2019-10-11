#pragma once

#include <string>
#include <iostream>

constexpr int NUM_OF_CHAT = 200;

class ReplyAdmin
{
 public:
    ReplyAdmin();                          // chats를 NUM_OF_CHAT(header에 200으로 define)만큼 초기화
    ~ReplyAdmin();                         // chats를 delete

    std::size_t getChatCount();            // chats에 들어있는 chat의 갯수를 반환
    bool addChat(std::string _chat);       // _chat을 chats에 추가 (추가 실패시 false 리턴)
    bool removeChat(int _index);           //_index 에 있는 chat 삭제 (_index 가 없을 시 false 리턴)
    bool removeChat(int _start, int _end); // _start 부터 _end 까지 chat을 모두 삭제
    void printChats();
    
 private:
    std::string* chats;
    std::size_t m_num;
};