#include <iostream>
#include <cstring>

using namespace std;

void tempMain() {
    /// BEGIN  <STUDENT ANSWER>

    int n;
    cin >> n;
    int a1 = 1, a2 = 1;
    if (n == 1 || n == 2)
        return;
    int i = 3, result;
    while (i <= n)
    {
        result = a1 + a2;
        a1 = a2;
        a2 = result;
        i++;
    }
    cout <<"Fibonaci = " << result << endl;
    return;

    /// END  <STUDENT ANSWER>
}
