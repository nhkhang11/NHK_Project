#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void tempMain() {
    /// BEGIN  <STUDENT ANSWER>
    int num1,num2,num3;
    cin >>num1;
    cin>>num2;
    cin>>num3;
    if (num1>0 && num2 > 0 && num3 > 0)
    {
        if ((pow(num1,2) + pow(num2,2)) == pow(num3,2) || (pow(num2,2) + pow(num3,2)) == pow(num1,2) || (pow(num1,2) + pow(num3,2)) == pow(num2,2))
    {
        cout<<"This is Right-angled triangle \n";
    }else if (num1 == num2 == num3)
    {
        cout<<"This is Equilateral triangle \n";
    }else if (num1 == num2 || num2 == num3 ||num3 == num1)
    {
        cout<<"This is Isoceles triangle \n";
    }else{
        cout<<"This is Scalene triangle \n";
    }
    }else
    {
        cout<<"Not a Triangle!!\n";
    }
    
    
    
    
    
    /// END  <STUDENT ANSWER>
}
