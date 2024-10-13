#include <iostream>

class Point
{
private:
    float _x, _y;

public:
    Point(float x, float y);

    float getX();

    float getY();

    void print();
};