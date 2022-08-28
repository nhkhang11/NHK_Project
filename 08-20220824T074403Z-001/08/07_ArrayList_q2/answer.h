#include <iostream>
#include <vector>

using namespace std;

	/// BEGIN  <STUDENT ANSWER>
bool consecutiveOnes(vector<int>& nums) {
    //Implement content in function  here
    // int flag = 0;
    // int reverse = 0;
	// for (int i = 0; i < nums.size(); i++)
    // {
    //     if (nums[i]==1 && nums[i] != 0)
    //     {
    //         for (int j = i+1; j < nums.size(); j++)
    //         {
    //             if (nums[j] == 1)
    //             {
    //                 return false;
    //             }
                
    //         }
    //         return true;
    //     }
    //     return true;
        
    // }

    bool meet = false;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1 && meet == false)
        {
            meet = true;
        }else if (nums[i] == 1 && meet == true && nums[i-1] != 1)
        {
            meet = false;
        }else{
            meet = true;
        }

    }
    return meet;
    
}

	



