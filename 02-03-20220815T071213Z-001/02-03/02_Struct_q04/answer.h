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

string convertToString(SCP obj) {
    // Student answer
    string resultStr = "Item #: SCP-";
    int countIdDigits = 0;
    char* idStr;
    int cpyId = obj.id;
    string objClassStr[] = {"Safe", "Euclid", "Keter"};

    for (int i = cpyId; i != 0; i /= 10)
    {
        countIdDigits++;
    }

    if(countIdDigits < 3)
    {
        countIdDigits = 3;
    }

    idStr = new char[countIdDigits];
    for (int i = countIdDigits - 1; i >= 0;i--)
    {
        idStr[i] = cpyId % 10 + 48;
        cpyId /= 10;
    }

    resultStr += idStr;

    resultStr += "\nObject Class: ";
    resultStr += objClassStr[obj.objClass];

    resultStr += "\nSpecial Containment Procedures: ";
    resultStr += obj.speConProcedures;

    resultStr += "\nDescription: ";
    resultStr += obj.description;
    
    for(int i = 0; i < obj.numAddendums; i++)
    {
        resultStr += "\n";
        resultStr += obj.addendums[i];
    }

    return resultStr;
}
/// END  <STUDENT ANSWER>