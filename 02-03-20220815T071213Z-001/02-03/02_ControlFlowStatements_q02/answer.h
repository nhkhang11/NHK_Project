#include <iostream>

using namespace std;

void tempMain() {
    /// BEGIN  <STUDENT ANSWER>
    float num1,num2,num3;
    cin>>num1;
    cin>>num2;
    cin>>num3;
    float max = num1;
    if (max < num2 && num3<num2)
    {
        cout<<num2<<" is max \n";   
    }else if (max < num3)
    {
        cout<<num3<<" is max \n";
    }else{
        cout<<num1<<" is max \n";
    }
    
    
    /// END  <STUDENT ANSWER>
}
