#include <iostream>
#include <cstring>

using namespace std;

void tempMain() {
    /// BEGIN  <STUDENT ANSWER>

    int element;
    cin>>element;
    int pos = 0, neg =0;
    float arr[element];
    for (int i = 1; i <= element ; i++)
    {
        cin>>arr[i];
    }
    for (int i = 1; i <= element; i++)
    {
        if (arr[i]>=0)
        {
            pos++;
        }else
        {
            neg ++;
        }      
    }

    cout<<"Number of positive elements: "<<pos<<endl;
    cout<<"Number of negative elements: "<<neg<<endl;
    
    /// END  <STUDENT ANSWER>
}
