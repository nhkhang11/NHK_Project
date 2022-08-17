#include <iostream>

using namespace std;

void tempMain() {
    /// BEGIN  <STUDENT ANSWER>
    int totalSale,received;
    cin >> totalSale;

    if (totalSale <= 100)
    {
        received = totalSale * 0.05;
        cout<<"With total sales of "<<totalSale<<" million VND, the commission received is "<<received<<" million VND."<<endl;
    }else if (totalSale <= 300)
    {
        received = totalSale * 0.1;
        cout<<"With total sales of "<<totalSale<<" million VND, the commission received is "<<received<<" million VND."<<endl;
    }else{
        received = totalSale * 0.2;
        cout<<"With total sales of "<<totalSale<<" million VND, the commission received is "<<received<<" million VND."<<endl;
    }
    
    
    /// END  <STUDENT ANSWER>
}
