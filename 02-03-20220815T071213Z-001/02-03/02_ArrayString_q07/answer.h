#include <iostream>
#include <string>

using namespace std;

void findAllIndex(string s1, string s2){
    // TO DO
    int n=0;
    while(true){
       
    if(s1.find(s2) == string::npos){
        return;
    }
    cout<< n+s1.find(s2)<<'\t';
    n=n+s1.find(s2) +1;
    s1 = s1.substr(s1.find(s2)+1);
    }
    
    
    
    
        
}