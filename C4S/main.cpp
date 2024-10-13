#include <iostream>
#include <math.h>

int main()
{

    std::cout << Math::add(5, 6) << std::endl;

    Point p(5.2, 4.3);

    Point ne = Math::add(p, 5);

    auto hal = new Point(5.7,4.2);

    hal->print();

    delete(hal);

    ne.print();

    return 0;
}