#include <iostream>
#include <cstring>

using namespace std;

/// BEGIN  <STUDENT ANSWER>
bool completeNum(int N)
{
    // TODO
    int sum = 1;

    for (int i=2; i*i<=N; i++)
    {
        if (N%i==0)
        {
            if(i*i!=N){
                sum = sum + i + N/i;
            }
            else{
                sum=sum+i;
            }
        }
    }
        if (sum == N && N != 1){
            return 1;
        }
    return 0;
}
/// END  <STUDENT ANSWER>