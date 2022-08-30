#include <iostream>
#include <cstring>

using namespace std;

/// BEGIN  <STUDENT ANSWER>
// TODO
class Coordinate
{
private:
    float x;
    float y;
public:
    Coordinate(float x = 0, float y= 0){
        this->x= x;
        this->y=y;
    };
    float setX(float x);
    float setY(float y);
    float getX();
    float getY();
    float distanceTo(const Coordinate &other);
};

float Coordinate::setX(float x){
        this->x = x;

    }
    
float Coordinate::setY(float y){
        this->y= y;

    }
    
float Coordinate::getX(){
        return x;
    }
float Coordinate::getY(){
        return y;
    }

float Coordinate::distanceTo(const Coordinate &other){
        float res=0;
        res = abs(this->x - other.x) + abs(this->y - other.y);
        return res;
    };

/// END  <STUDENT ANSWER>