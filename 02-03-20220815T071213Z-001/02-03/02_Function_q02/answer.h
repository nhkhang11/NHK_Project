#include <iostream>
#include <cstring>

using namespace std;

/// BEGIN  <STUDENT ANSWER>
int findMax(int *vals, int numEls) {
    // TODO
    int max= vals[0];

    for (int i = 1; i < numEls; i++)
{
        if (vals[i] > max)
        {
            max=vals[i];
        }
    }
    return max;
}
/// END  <STUDENT ANSWER>