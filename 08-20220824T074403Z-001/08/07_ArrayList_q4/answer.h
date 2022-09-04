#include <iostream>
#include <vector>

using namespace std;

/// BEGIN  <STUDENT ANSWER>
int longestSublist(vector<string>& words) {
    // STUDENT ANSWER
    int max = 0, count = 0;
    char rec = words[0][0];
    for(int i = 0; i < words.size();i++){
        if (words[i][0] != rec){
            rec = words[i][0];
            count = 1;
        }
        else ++count;
        if (count > max) max = count;
    }
    return max;
}
/// END  <STUDENT ANSWER>
