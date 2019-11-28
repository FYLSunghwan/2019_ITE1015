#include "calendar.h"
#include <iostream>
#include <string>

Date::Date() : year_(0), month_(0), day_(0)
{
    // Do Nothing
}

Date::Date(int y, int m, int d) : year_(y), month_(m), day_(d)
{
    // Do Nothing
}

void Date::NextDay(int n)
{
    int days = ComputeDaysFromYearStart(year_, month_, day_) + n;
    while(days<1) {days += GetDaysInYear(--year_);}
    while(days>GetDaysInYear(year_)) {days-=GetDaysInYear(year_++);}

    int totmonth = 0;
    for(int m=1; m<=12; m++)
    {
        int md = GetDaysInMonth(year_, m);
        if(totmonth < days && days <= totmonth + md)
        {
            month_ = m;
            day_ = days - totmonth;
            break;
        }
        totmonth += md;
    }
}

bool bounded(int n, int lim)
{
    return n>=1 && n<=lim;
}

bool Date::SetDate(int y, int m, int d)
{
    if(y>=0 && bounded(m, 12)&& bounded(d, GetDaysInMonth(y, m)))
    {
        year_ = y;
        month_ = m;
        day_ = d;
        return true;
    }
    std::cout << "Invalid date: ";
    std::cout << y << "." << m << "." << d << std::endl;
    return false;
}

int Date::year() const 
{
    return year_;
}

int Date::month() const 
{
    return month_;
}

int Date::day() const 
{
    return day_;
}

int Date::GetDaysInYear(int y)
{
    if(y%400 == 0 || (y%4==0 && y%100 !=0)) return 366;
    return 365;
}

int Date::GetDaysInMonth(int y, int m)
{
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(GetDaysInYear(y) == 366 && m==2) return 29;
    return days[m];
}

int Date::ComputeDaysFromYearStart(int y, int m, int d)
{
    for (int i = 1; i < m; ++i) {
        d += GetDaysInMonth(y, i);
    }
    return d;
}

std::ostream& operator<<(std::ostream& os, Date const& date)
{
    os << date.year() << '.' << date.month() << '.' << date.day();
    return os;
}

std::istream& operator>>(std::istream& is, Date& date)
{
    int y, m, d;
    char sep;
    is >> y >> sep >> m >> sep >> d;
    if(date.SetDate(y, m, d))
    {
        std::cout << date << std::endl;
    }
    return is;
}