#include <iostream>
#include <cstring>

using namespace std;

/// BEGIN  <STUDENT ANSWER>
struct SCP {
    int id;
    int objClass;
    string speConProcedures;
    string description;
    string* addendums;
    int numAddendums;
};

void addAddendum(SCP &obj, string addendum) {
    // Student answer
    string* newAddendums = new string[obj.numAddendums + 1];

    for(int i = 0; i < obj.numAddendums; i++)
    {
        newAddendums[i] = obj.addendums[i];
    }

    delete []obj.addendums;

    newAddendums[obj.numAddendums] = addendum;
    obj.addendums = newAddendums;
    obj.numAddendums++;
}
/// END  <STUDENT ANSWER>