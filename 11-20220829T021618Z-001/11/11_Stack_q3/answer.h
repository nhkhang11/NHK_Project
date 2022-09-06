#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
#include <list>
using namespace std;

	/// BEGIN  <STUDENT ANSWER>
string removeDuplicates(string s){
    /*TODO*/
    stack<char> str;
    char c;

    for (int i = 0; i < s.length(); i++)
    {
        if (!str.empty())
        {
            c = str.top();
            if (c == s[i])
            {
                str.pop();
            }else
            {
                str.push(s[i]);
            }
        }else
        {
            str.push(s[i]);
        }
    }
    
    int size = str.size();
    char* ptr = new char[size + 1];
    for (int i = 0; i < size; i++)
    {
        ptr[size - i - 1] = str.top();
        str.pop();
    }
    ptr[size] = '\0';
    string result = ptr;
    delete [] ptr;
    return result;
}
