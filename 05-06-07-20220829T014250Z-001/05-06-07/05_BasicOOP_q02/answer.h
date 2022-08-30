#include <iostream>
#include <cstring>

using namespace std;

/// BEGIN  <STUDENT ANSWER>
class Room
{
private:
    int length;
    int breadth;
    int height;
public:
    Room(int Nlength, int Nbreadth, int Nheight){
        this->length = Nlength;
        this->length = Nbreadth;
        this->length = Nheight;
    };
    int calculateArea(int Nlength, int Nbreadth, int Nheight){
        int Area = 0;
        Area = Nlength * Nbreadth;
        return Area;
    }
    int calculateVolume(int Nlength, int Nbreadth, int Nheight){
        int Vol = 0;
        Vol = Nlength * Nbreadth * Nheight;
        return Vol;
    }
    
    // ~Room();
};


/// END  <STUDENT ANSWER>