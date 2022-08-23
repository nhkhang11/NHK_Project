#include <iostream>
#include <cstring>

using namespace std;

/// BEGIN  <STUDENT ANSWER>
void insertRow(int**& matrix, int r, int c, int* rowArr, int row){
    // TODO
    int i, j, temp=0, rowAbove=0;
    
    
    if (row < r){
        matrix[r] = new int[c];
        for (i=0; i<c; ++i){
            *(*(matrix+r)+i) = *(rowArr+i);
        }
        for (i=r; i>row; --i){
            for (j=0; j<c; ++j){                                                  
                rowAbove = i-1;
                temp = *(*(matrix +rowAbove) +j);
                *(*(matrix+rowAbove)+j) = *(*(matrix+i)+j);
                *(*(matrix+i)+j) = temp;
            }
        }
    }
    else if(row ==r){
        matrix[row] = new int[c];
        for (i=0; i<c; ++i){
            *(*(matrix+row)+i) = *(rowArr+i);
        }
    }
    
    
}
/// END  <STUDENT ANSWER>