#include <math.h>

int Math::add(int a, int b)
{
    return a + b;
}

Point Math::add(Point p, float num)
{
    return Point(p.getX() + num, p.getY() + num);
}