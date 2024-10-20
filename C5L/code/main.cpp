#include <iostream>
#include <math.h>


int main()
{

    std::cout << Math::add(5, 6) << std::endl;

    Point<double> p(5.2);

    p.print();

    Point<double> novy = Math::posun(p);

    novy.print();

    return 0;
}