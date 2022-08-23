#include <iostream>
#include <cstring>

using namespace std;

// Student may implement another function as need

void process(char str[], char outstr[]) {
    // TODO
    int n =strlen(str);
    
    for (int i=0; i<n; i++){
        outstr[i] = toupper(str[i]);
    }
}