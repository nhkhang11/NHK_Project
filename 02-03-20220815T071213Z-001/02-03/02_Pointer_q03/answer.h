#include <iostream>
#include <cstring>

using namespace std;

/// BEGIN  <STUDENT ANSWER>
void reverse(int *ptr, int n)
{
    int temp =0;
    for (int i = 0; i < n/2; i++)
    {
        temp = *(ptr+i);
        *(ptr+i) = *(ptr+n-i-1);
        *(ptr+n-i-1) = temp;
    }
    
}
/// END  <STUDENT ANSWER>