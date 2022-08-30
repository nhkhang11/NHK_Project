#include <iostream>
#include <cstring>

using namespace std;

/// BEGIN  <STUDENT ANSWER>
class ClockType
{
public:
    ClockType(int hour, int minute, int second);
    ClockType();    
    void printTime() const;
    void setTime(int hour, int minute, int second);
    
    void getTime(int& hours, int& minutes, int& seconds) const;
    

private:
    int hr;
    int min;
    int sec;
};

ClockType::ClockType()
{
    hr = 0;
    min = 0;
    sec = 0;
}

ClockType::ClockType(int hours, int minutes, int seconds)
{
    this->setTime(hours, minutes, seconds);
}

void ClockType::setTime(int hours, int minutes, int seconds)
{
    if (0 <= hours && hours < 24)
        hr = hours;
    else
        hr = 0;
    if (0 <= minutes && minutes < 60)
        min = minutes;
    else
        min = 0;
    if (0 <= seconds && seconds < 60)
        sec = seconds;
    else
        sec = 0;
}
void ClockType::getTime(int &hours, int &minutes, int &seconds) const{
        hours = this->hr;
        minutes = this->min;
        seconds = this->sec;
};

void ClockType::printTime() const
{
   if (hr < 10)
      cout << "0";
   cout << hr << ":";
   if (min < 10)
      cout << "0";
   cout << min << ":";
   if (sec < 10)
      cout << "0";
   cout << sec;
}

// TODO


/// END  <STUDENT ANSWER>