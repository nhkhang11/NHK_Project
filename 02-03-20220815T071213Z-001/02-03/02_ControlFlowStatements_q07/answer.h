#include <iostream>
#include <cstring>

using namespace std;

void tempMain() {
    /// BEGIN  <STUDENT ANSWER>

    int element;
    cin>>element;
    float sum = 0;
    float arr[element];
    for (int i = 1; i <= element ; i++)
    {
        cin>>arr[i];
        sum += arr[i];
    }
    sum = sum/element;
    cout<<"Average = "<<sum<<endl;
    return;
    
    /// END  <STUDENT ANSWER>
}
