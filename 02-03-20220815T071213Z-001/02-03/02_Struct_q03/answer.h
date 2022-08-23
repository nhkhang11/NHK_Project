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

SCP createSCP(int id, int objClass, string speConProcedures, string description, string* addendums, int numAddendums) {
    // Student answer
    SCP newScp;
    newScp.id = id;
    newScp.objClass = objClass;
    newScp.speConProcedures = speConProcedures;
    newScp.description = description;
    newScp.addendums = addendums;
    newScp.numAddendums = numAddendums;
    return newScp;
}
/// END  <STUDENT ANSWER>