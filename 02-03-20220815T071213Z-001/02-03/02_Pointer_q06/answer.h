#include <iostream>
#include <cstring>

using namespace std;

/// BEGIN  <STUDENT ANSWER>
int* flatten(int** matrix, int r, int c) {
    // TODO:
    int count = 0;
    int *newArr = new int[r*c];
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            *(newArr + count) = *(*(matrix+i)+j);
            count++;
        }
        
    }
    return newArr;
}
/// END  <STUDENT ANSWER>