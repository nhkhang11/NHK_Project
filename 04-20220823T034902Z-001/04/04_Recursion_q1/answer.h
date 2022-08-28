#include <iostream>
#include <cstring>

using namespace std;

	/// BEGIN  <STUDENT ANSWER>
bool checkDuplicate(int* ar,int size)

{
	int *temp = new int[size];
	if (size > 1)
	{
		for (int i = 0; i < size; i++)
		{
			if (ar[0] == ar[i])
			{
				return true;
			}else
			{
				temp[i-1] = ar[i];
			}			
		}
		return checkDuplicate(temp, size);
	}
	return false;
	delete [] temp;
}
