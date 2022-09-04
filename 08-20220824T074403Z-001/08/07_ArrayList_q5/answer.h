#include <iostream>
#include <vector>

using namespace std;

/// BEGIN  <STUDENT ANSWER>
vector<int> updateArrayPerRange(vector<int>& nums, vector<vector<int>>& operations) {
    // TODO
    int n = operations.size();
    int l = 0, r = 0, x = 0;
    for (int i = 0; i<n;++i){
        l = operations[i][0];
        r = operations[i][1];
        x = operations[i][2];
        for(int j = l; j <= r;++j){
            nums[j]+=x;
        }
    }
    return nums;
}
/// END  <STUDENT ANSWER>
