#include <iostream>
#include <cstring>

using namespace std;

void tempMain() {
    /// BEGIN  <STUDENT ANSWER>

     int element;
    cin>>element;
    float max,sum = 0;
    float arr[element];
    for (int i = 1; i <= element ; i++)
    {
        cin>>arr[i];      
    }

    for (int i = 2; i < element; i++)
    {
        max = arr[1];
        if (arr[i] > max)
        {
            max=arr[i];
        }
    }
    
    cout<<"Maximum = "<<max<<endl;
    return;
    

    /// END  <STUDENT ANSWER>
}
