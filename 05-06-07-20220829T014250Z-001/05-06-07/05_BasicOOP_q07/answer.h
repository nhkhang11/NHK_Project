#include <iostream>
#include <cstring>

using namespace std;

/// BEGIN  <STUDENT ANSWER>
// TODO
class Book
{
private:
    char* name;
public:
    Book(const char* );
    void display();
    ~Book();
};

Book::Book(const char* str){
    int size = strlen(str);
    this->name = new char[size];
    strcpy(name,str);
}

void Book::display(){
    cout << "Book:" << name;
}

Book::~Book(){
    delete[] name;
}

/// END  <STUDENT ANSWER>