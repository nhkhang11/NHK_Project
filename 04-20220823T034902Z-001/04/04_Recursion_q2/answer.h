#include <iostream>
#include <cstring>

using namespace std;

/// BEGIN  <STUDENT ANSWER>
int gcdRecursion(int p, int q)
{
    // BEGIN YOUR IMPLEMENTATION [1]
    // TODO
    return q==0 ? p : gcdRecursion(q,p % q);

    // END YOUR EMPLEMENTATION [1]
}
int gcdIteration(int p, int q)
{
    // BEGIN YOUR IMPLEMENTATION [2]
    // TODO
    int res = p;
    if (q < p)
    {
        res = 0;
    }
    while (res > 0)
    {
        if (p % res == 0 && q% res == 0)
        {
            break;
        }
            res --;
    }
    return res;
    
    // END YOUR EMPLEMENTATION [2]
}
/// END  <STUDENT ANSWER>