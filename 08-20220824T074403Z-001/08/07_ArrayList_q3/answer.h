#include <iostream>
#include <vector>

using namespace std;

	/// BEGIN  <STUDENT ANSWER>
int equalSumIndex(vector<int>& nums) {
    //TODO
    int i=0, size=nums.size();
    int totalSum=0, leftSum=0, rightSum=0;

    for (i=0; i<size; ++i){
        totalSum+=nums[i];
    }
    for (i=0; i<size; ++i){
        rightSum=totalSum-leftSum-nums[i];
        if (leftSum==rightSum){
            return i;
        }
        leftSum=leftSum+nums[i];
    }
	return -1;
}
