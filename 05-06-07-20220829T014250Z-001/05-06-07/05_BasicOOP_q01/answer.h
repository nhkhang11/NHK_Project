#include <iostream>
#include <cstring>

using namespace std;

/// BEGIN  <STUDENT ANSWER>
class Integer {
private:
    int val;

public:
    Integer(int value){
        this->val = value;
    };
    void setValue(int value){
        val = value;
    }
    int getValue(int value){
        return value;
    }
    // ~Integer();
};
/// END  <STUDENT ANSWER>