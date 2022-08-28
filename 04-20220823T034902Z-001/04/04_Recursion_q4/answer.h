#include <iostream>
#include <cstring>

using namespace std;

/// BEGIN  <STUDENT ANSWER>
int recursiveSearch(int& n , int m, int arr[], int index)
{
    static int temp = -1;

    if (index == n)
    {
        if (temp != -1)
        {
            n -= 1;
            int ret = temp;
            temp = -1; // reset temp before return
            return ret;
        }
        else
            return temp;
    }
    if ((arr[index] == m) && (temp == -1))
    {
        temp = index;
        return recursiveSearch(n, m, arr, index + 1);
    }
    else
    {
        if (temp != -1)
        {
            arr[index - 1] = arr[index];
        }
        return recursiveSearch(n, m, arr, index + 1);
    }

}
/// END  <STUDENT ANSWER>