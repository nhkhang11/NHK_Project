#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

	/// BEGIN  <STUDENT ANSWER>
bool isValidParentheses (string s){
    /*TODO*/
    stack<char> str;
    char c;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '[')
        {
            str.push(s[i]);
        }
        if (s[i] == ']')
        {
            c = str.top();
            str.pop();
            if (c != '[')
            {
                return false;
            }
            break;
        }
        if (s[i] == '(')
        {
            str.push(s[i]);
        }
        if (s[i] == ')')
        {
            c = str.top();
            str.pop();
            if (c != '(')
            {
                return false;
            }
            break;
        }
        if (s[i] == '{')
        {
            str.push(s[i]);
        }
        if (s[i] == '}')
        {
            c = str.top();
            str.pop();
            if (c != '{')
            {
                return false;
            }
            break;
        }       
    }
    if (!str.empty())
    {
        return false;
    }
    return true;
}
