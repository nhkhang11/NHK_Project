#include "answer.h"
#include "utils.h"

const string CHECKED_FILENAME = "answer.h";
const int NO_IGNORED_LINES = 5;

int main() {
    codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    DLinkedList<int> list;
    int size = 10;
    for(int idx=0; idx < size; idx++){
        list.add(idx);
    }
    cout << list.toString();
    return 0;

    /// END  <TEST CODE>


}