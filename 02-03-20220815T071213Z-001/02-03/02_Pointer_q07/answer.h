#include <iostream>
#include <cstring>

using namespace std;

/// BEGIN  <STUDENT ANSWER>
char* concatStr(char* str1, char* str2) {
    // TODO:
    char *str = new char[strlen(str1)+strlen(str2)];
    for (int i = 0; i < strlen(str1); i++)
    {
        str[i] = str1[i];
    }
    for (int i = 0; i < strlen(str2); i++)
    {
        str[i+strlen(str1)] = str2[i];
    }
    
    return str;
}
/// END  <STUDENT ANSWER>