#include <iostream>
#include <cstring>

using namespace std;

/// BEGIN  <STUDENT ANSWER>
class ClockType
{
   public:
      ClockType(int hr, int min, int sec){ //constructor with parameters
        this->hr = hr;
        this->min = min;
        this->sec = sec;
      }
      ClockType(); //default constructor
      
      void printTime() const;

   private:
      int hr;
      int min;
      int sec;
};

void ClockType::printTime() const { 
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

//TODO


/// END  <STUDENT ANSWER>