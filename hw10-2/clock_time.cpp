#include <iostream>
#include <iomanip>
#include "clock_time.h"

using namespace::std;

ClockTime::
ClockTime ()
: hour_(0),
  minute_(0),
  second_(0),
  secondsPerTick_(1),
  deltaTime_(0)
{
  recordStartTime();
}

ClockTime::
ClockTime (int hour, int minute, int second, int secondsPerTick)
: hour_(hour),
  minute_(minute),
  second_(second),
  secondsPerTick_(secondsPerTick),
  deltaTime_(0)
{
  recordStartTime();
}

void ClockTime::
reset ()
// The purpose of this method is to reset the time to the recorded
// start time.
{
  unsigned int temp = startTime_;

  hour_  = temp / (MINUTES_PER_HOUR * SECONDS_PER_MINUTE);
  temp  -= hour_ * (MINUTES_PER_HOUR * SECONDS_PER_MINUTE);

  minute_  = temp / SECONDS_PER_MINUTE;
  temp    -= minute_* SECONDS_PER_MINUTE;

  second_ = temp;
}

void ClockTime::
increment ()
// The purpose of this method is to increment the clock time by the number
// of seconds by which the time is to advance per tick.
{
  deltaTime_ += secondsPerTick_;

  // Compute the new time in terms of seconds.
  int seconds = hour_   * MINUTES_PER_HOUR * SECONDS_PER_MINUTE +
                minute_ * SECONDS_PER_MINUTE                    +
                second_                                         + 
                secondsPerTick_;

  // If the new time is greater than the number of seconds in a day, adjust
  // the new time to reflect the number of seconds past midnight.
  if (seconds > (HOURS_PER_DAY * MINUTES_PER_HOUR * SECONDS_PER_MINUTE))
    seconds -= (HOURS_PER_DAY * MINUTES_PER_HOUR * SECONDS_PER_MINUTE);

  hour_ = seconds  / (MINUTES_PER_HOUR * SECONDS_PER_MINUTE);
  seconds -= hour_ * (MINUTES_PER_HOUR * SECONDS_PER_MINUTE);

  minute_ = seconds / SECONDS_PER_MINUTE;
  seconds -= minute_ * SECONDS_PER_MINUTE;

  second_ = seconds;
}

void ClockTime::
display () const
// The purpose of this method is to display the values stored in
// an instance of simulation time.
{
  cout << right << setw(2) << setfill('0') << hour_   << ":"
       << right << setw(2) << setfill('0') << minute_ << ":" 
       << right << setw(2) << setfill('0') << second_;
}

void ClockTime::       // Private method
recordStartTime ()
// The purpose of this method is to compute and record the start time.
{
  startTime_ = hour_   * MINUTES_PER_HOUR * SECONDS_PER_MINUTE +
               minute_ * SECONDS_PER_MINUTE                    +
               second_;
}

Clock::Clock(int hour, int minute, int second, double driftPerSecond)
:_driftPerSecond(driftPerSecond)
{
  // Do Nothing
}

void Clock::reset()
{
  _clockTime.reset();
  _totalDrift = 0;
}

void Clock::tick()
{
  _clockTime.increment();
  _totalDrift += _driftPerSecond;
}

NaturalClock::NaturalClock(int hour, int minute, int second, double driftPerSecond)
:Clock(hour, minute, second, driftPerSecond)
{
  // Do Nothing
}

MechanicalClock::MechanicalClock(int hour, int minute, int second, double driftPerSecond)
:Clock(hour, minute, second, driftPerSecond)
{
  // Do Nothing
}

DigitalClock::DigitalClock(int hour, int minute, int second, double driftPerSecond)
:Clock(hour, minute, second, driftPerSecond)
{
  // Do Nothing
}

QuantumClock::QuantumClock(int hour, int minute, int second, double driftPerSecond)
:Clock(hour, minute, second, driftPerSecond)
{
  // Do Nothing
}

SundialClock::SundialClock(int hour, int minute, int second)
:NaturalClock(hour, minute, second, 0.0)
{
  // Do Nothing
}

CuckooClock::CuckooClock(int hour, int minute, int second)
:MechanicalClock(hour, minute, second, 0.000694444)
{
  // Do Nothing
}

GrandFatherClock::GrandFatherClock(int hour, int minute, int second)
:MechanicalClock(hour, minute, second, 0.000347222)
{
  // Do Nothing
}

WristClock::WristClock(int hour, int minute, int second)
:DigitalClock(hour, minute, second, 0.000034722)
{
  // Do Nothing
}

AtomicClock::AtomicClock(int hour, int minute, int second)
:QuantumClock(hour, minute, second, 0.0)
{
  // Do Nothing
}

void SundialClock::displayTime()
{
  std::cout << "SundialClock ";
  _clockTime.display();
  std::cout << ", total drift: " << _totalDrift << std::endl;
}

void CuckooClock::displayTime()
{
  std::cout << "CuckooClock ";
  _clockTime.display();
  std::cout << ", total drift: " << _totalDrift << std::endl;
}

void GrandFatherClock::displayTime()
{
  std::cout << "GrandFatherClock ";
  _clockTime.display();
  std::cout << ", total drift: " << _totalDrift << std::endl;
}

void WristClock::displayTime()
{
  std::cout << "WristClockClock ";
  _clockTime.display();
  std::cout << ", total drift: " << _totalDrift << std::endl;
}

void AtomicClock::displayTime()
{
  std::cout << "AtomicClock ";
  _clockTime.display();
  std::cout << ", total drift: " << _totalDrift << std::endl;
}