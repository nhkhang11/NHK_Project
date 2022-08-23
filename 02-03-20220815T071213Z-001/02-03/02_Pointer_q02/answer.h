#include <iostream>
#include <cstring>

using namespace std;

/// BEGIN  <STUDENT ANSWER>
int findMax(int *ptr, int n)
{
    int max = *ptr;

    for (int i = 2; i < n; i++)
    {
        if (*(ptr+i) > max)
        {
            max=*(ptr+i);
        }
    }
    
    cout<<"Maximum = "<<max<<endl;
    return max;
}
/// END  <STUDENT ANSWER>