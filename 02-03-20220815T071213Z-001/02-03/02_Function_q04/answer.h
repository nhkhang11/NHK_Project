#include <iostream>
#include <cstring>

using namespace std;

/// BEGIN  <STUDENT ANSWER>
bool isPalindrome(const char* str) {
    // TODO: Write your code here
    int low = 0;
    int high = strlen(str) - 1;

    while (low < high)
    {
        if(str[low] != str[high])
        {
            return false;
        }
        low++;
        high--;
    }
    return true;
}
/// END  <STUDENT ANSWER>