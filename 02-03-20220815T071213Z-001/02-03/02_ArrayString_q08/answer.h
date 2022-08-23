#include <iostream>
#include <string>

using namespace std;

void deleteWord(string s, string s1){
    //TO DO
    while(true){
       
    if(s.find(s1) == string::npos){
        cout << s << endl;
        return;
    }
    s.erase(s.find(s1),3);
    
    }
    
}