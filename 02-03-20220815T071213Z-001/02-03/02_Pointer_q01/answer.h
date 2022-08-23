#include <iostream>
#include <cstring>

using namespace std;

/// BEGIN  <STUDENT ANSWER>
int calcSum(int *ptr, int n)
{
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum += *(ptr +i);
    }
    return sum;
}
/// END  <STUDENT ANSWER>