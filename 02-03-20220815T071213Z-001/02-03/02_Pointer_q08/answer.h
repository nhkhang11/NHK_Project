#include <iostream>
#include <cstring>

using namespace std;

/// BEGIN  <STUDENT ANSWER>
int** transposeMatrix(int** matrix, int r, int c) {
    // TODO:
    int **newArr = new int*[c];
    for(int i=0;i<r;i++)
    {
        newArr[i]=new int[r];
    }

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            *(*(newArr+j)+i) = *(*(matrix + i) + j);
        }
        
    }
    return newArr;
}
/// END  <STUDENT ANSWER>