#include <iostream>
// #include "utils.h"
#include <cstring>

using namespace std;

/// BEGIN  <STUDENT ANSWER>
void deleteMatrix(int**& matrix, int r) {
    // TODO:

    for (int i = 0; i < r; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    matrix = NULL;
    if (matrix == NULL)
    {
    cout << "Successfully \n";
        
    }
    
}
/// END  <STUDENT ANSWER>