#include <iostream>
#include <math.h>

class TwoD
{
private:
    float _x, _y;

public:
    TwoD(float x, float y) : _x(x), _y(y) {}

    friend std::ostream &operator<<(std::ostream &os, const TwoD &dt);

    TwoD operator+(TwoD const &obj)
    {

        return TwoD(_x + obj._x, _y + obj._y);
    }
};

std::ostream &operator<<(std::ostream &os, const TwoD &dt)
{
    os << "{" << dt._x << ',' << dt._y << '}';
    return os;
}


int main()
{

    const TwoD td(5.3f, 2.1f);
    std::cout << td << std::endl;

    const Point<float> p(5.1f);
    p.print();

    const Point<int> pint(5);
    pint.print();

    const Point<int> novy = Math::posun(pint, 3);

    novy.print();

    const Point<float> novyfloat = Math::posun(p, 3.2f);

    novyfloat.print();

    const Point<TwoD> ptd(TwoD(5.2f, 3.1f));

    const Point<TwoD> novyptd = Math::posun(ptd, TwoD(1.0f, 5.2f));

    ptd.print();
    novyptd.print();

    const Point<std::string> stary(std::string("Hello"));
    const Point<std::string> novystring = Math::posun(stary, std::string("World"));

    novystring.print();

    return 0;
}
