#include <iostream>
#include <iomanip>

using namespace std;

void tempMain() {
    /// BEGIN  <STUDENT ANSWER>
     int n;
    cin >> n;
    int a1 = 0, a2 = 1;
    if (n == 1 || n == 2)
        return;
        int result= 0;
    for (int i = 1; i <= n; i++)
    {
        result = a1 + a2;
        a1 = a2;
        a2 = result;
    }
    
    cout <<"Fibonaci = " << result << endl;
    return;
    /// END  <STUDENT ANSWER>
}
