#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

	/// BEGIN  <STUDENT ANSWER>
int sumOfMaxSubarray(vector<int>& nums, int k) {
    // STUDENT ANSWER
    int sum = 0;
    int count = 0;
    deque<int> q;
    for (int i = 0; i < k; i++)
    {
        q.push_back(nums[i]);
        count++;
        
    }
    while (count <= nums.size())
    {
        int max = q.front();
        for (int i = 0; i < q.size(); i++)
        {
            if (q.at(i) > max)
            {
                max = q.at(i);
            }
        }
        sum +=max;
        count++;
        q.pop_front();
        q.push_back(nums[count-1]);
    }
    
    return sum;
}
