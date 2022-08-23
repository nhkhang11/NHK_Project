#include <iostream>
#include <cstring>

using namespace std;

/// BEGIN  <STUDENT ANSWER>
bool isSpecialNumber(int n) {
    // TODO: Write your code
    bool flag = true;
if (n == 0 || n == 1)
    flag = false;

  for (int i = 2; i <= n / 2; ++i) {
    if (n % i == 0) {
      flag = false;
      break;
    }
  }
  return flag;
}
/// END  <STUDENT ANSWER>