#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

	/// BEGIN  <STUDENT ANSWER>
int baseballScore(string ops){
	/*TODO*/
	stack<int> q;
	
	for (int i = 0; i < ops.length(); i++)
	{
		if (ops[i] >= '0' && ops[i] <= '9')
		{
			q.push(ops[i]);
		}
		else if (ops[i] == 'C')
		{
			q.pop();
		}
		else if (ops[i] == 'D')
		{
			int db = 0;
			db = 2*q.top();
			q.push(db);
		}
		else if (ops[i] == '+')
		{
			int temp = q.top();
			q.pop();
			int temp1 = q.top();
			q.push(temp);
			q.push(temp1 + temp);
		}
	}
	int sum = 0;
	while (!q.empty())
	{
		sum+=q.top();
		q.pop();
	}
	return sum;
}
