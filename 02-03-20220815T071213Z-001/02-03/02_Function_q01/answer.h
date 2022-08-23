#include <iostream>
#include <cstring>

using namespace std;

/// BEGIN  <STUDENT ANSWER>

// TODO: Implement calculate factorial function in here


void runTest(int n)
{
    long result = 1;
    // TODO: Call function calculateFactorial in here and assign value to the variable result
    for (int i = 1; i <= n; i++){
        result *= i;
    }
    cout << result << endl;
}
/// END  <STUDENT ANSWER>