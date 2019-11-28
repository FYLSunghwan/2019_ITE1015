#include "world_clock.h"

void WorldClock::Tick(int sec)
{
    const int TOTSEC = 86400;
    m_second += sec;
    if(m_second > TOTSEC) m_second -= TOTSEC;
    else if(m_second < 0) m_second += TOTSEC;
}

bool bounded(int n, int lim)
{
    return n>=0 && n < lim;
}

bool WorldClock::SetTime(int h, int m, int s)
{
    const int H = 3600, M = 60;
    if(bounded(h, 24) && bounded(m, 60) && bounded(s, 60))
    {
        m_second = h * H + m * M + s;
        SetValid(true);
        return true;
    }
    SetValid(false);
    std::cout << "Invalid time: " << h << ":" << m <<":" << s << std::endl;

    return false;
}

int WorldClock::hour() const
{
    return m_second / 3600;
}

int WorldClock::minute() const
{
    return (m_second - hour()*3600) / 60;
}

int WorldClock::second() const
{
    return m_second - hour() * 3600 - minute() * 60;
}

void WorldClock::SetValid(bool valid)
{
    m_valid = valid;
}

bool WorldClock::isValid() const
{
    return m_valid;
}

std::ostream& operator<<(std::ostream& os, WorldClock const& clock)
{
    os << clock.hour() << ':' << clock.minute() << ':' << clock.second();
    return os;
}

std::istream& operator>>(std::istream& is, WorldClock& clock)
{
    int hour, minute, second;
    char sep;
    is >> hour >> sep >> minute >> sep >> second;
    clock.SetTime(hour, minute, second);
    return is;
}