#include <iostream>
#include <vector>
#include <queue>
using namespace std;

	/// BEGIN  <STUDENT ANSWER>
bool visited(const int &num, const vector<int> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == num)
			return true;
	}
	return false;
}
void bfs(vector<vector<int>> graph, int start)
{
	queue<int> qe;
	vector<int> v;

	qe.push(start);
	cout << start << " ";
	v.push_back(start);

	int num;
	while (qe.size() != 0)
	{
		num = qe.front();
		qe.pop();
		vector<int> prePush = graph[num];

		for (int i = 0; i < prePush.size(); i++)
		{
			if (!visited(prePush[i], v))
			{
				qe.push(prePush[i]);
				v.push_back(prePush[i]);
				cout << prePush[i] << " ";
			}
		}
	}
}
