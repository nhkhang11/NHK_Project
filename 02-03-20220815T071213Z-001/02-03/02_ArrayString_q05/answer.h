#include <iostream>
#include <cstring>

using namespace std;

// Student may implement another function as need

void process(char str[], char outstr[]) {
    // TODO
    int n = strlen(str);
    int j=0;
    for (int i = 0; i < n; i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == ' ')
        {
            outstr[j]=str[i];
            j++;
        }
        
    }
    for (int i = 0; i < j; i++)
    {
        outstr[i]=tolower(outstr[i]);
    }
    outstr[0]=toupper(str[0]);
    for (int i=1;i<j;i++)
    {
        if(outstr[i]==' '){
            outstr[i+1]= toupper(outstr[i+1]); 
    }
    }
    
}