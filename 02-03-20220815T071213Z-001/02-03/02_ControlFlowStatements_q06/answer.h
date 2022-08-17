#include <iostream>
#include <cstring>

using namespace std;

void tempMain() {
    /// BEGIN  <STUDENT ANSWER>
    float n,x;
    float result = 1;
    do
    {
        cin >> n;
    } while (n<0);
    cin >> x;
    for (int i = 1; i <= n; i++)
    {
        result *= x;
    }
    cout<<"Result of x^n = "<<result<<endl;
    result = 1;
    for (int j = 1; j <=n; j++)
    {
        result *= 1/x;
    }
    cout<<"Result of x^(-n) = "<<result<<endl;
    return;

    
    /// END  <STUDENT ANSWER>
}
