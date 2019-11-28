#pragma once
#include <iostream>

class WorldClock {
public:
    WorldClock() : m_valid(true), m_second(0) {}
    void Tick(int seconds);
    bool SetTime(int hour, int minute, int second); 

    int hour() const;
    int minute() const;
    int second() const;

    bool isValid() const;
    void SetValid(bool valid);
private:
    int m_second; // 초 정보만 저장하고 시, 분을 계산 (예: 10000초 = 2 시간 46 분 40 초).
    bool m_valid;
};

std::ostream& operator<<(std::ostream& os, WorldClock const& clock);
std::istream& operator>>(std::istream& is, WorldClock& clock);