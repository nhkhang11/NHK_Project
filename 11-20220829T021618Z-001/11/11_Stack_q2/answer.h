#include <iostream>
#include <stack>
#include <vector>

using namespace std;

	/// BEGIN  <STUDENT ANSWER>


vector<int> nextGreater(vector<int>& arr){
    vector<int> result(arr);
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = i+1; j < arr.size(); j++)
		{
			if (arr[j]>arr[i])
			{
				result[i]=arr[i];
				break;
			}
			result[i]=-1;
		}
		result[i+1]=-1;
	}
	return result;
}
