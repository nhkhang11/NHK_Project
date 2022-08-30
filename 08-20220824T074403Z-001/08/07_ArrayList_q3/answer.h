#include <iostream>
#include <vector>

using namespace std;

	/// BEGIN  <STUDENT ANSWER>
int equalSumIndex(vector<int>& nums) {
    //TODO
    int n = sizeof(nums)/sizeof(nums[0]);
	for (int i = 1; i < n; i++)
    {
        int leftSum = 0;
        for (int j = i-1; j  >= 0; j--)
        {
            leftSum += nums[j];
        }
        int rightSum = 0;
        for (int k = i+1; k < n; k++)
        {
            rightSum += nums[k];
        }
        if (leftSum == rightSum)
        {
            return nums[i];
        }
    }
    return -1;
    
}