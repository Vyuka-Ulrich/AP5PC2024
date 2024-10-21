#include <iostream>
#include <math.h>

class TwoD
{
private:
    float _x, _y;

public:
    TwoD(float x, float y) : _x(x), _y(y) {}

    TwoD operator+(const TwoD &other) const
    {
        return TwoD(_x + other._x, _y + other._y);
    }

    friend std::ostream &operator<<(std::ostream &os, const TwoD &bod);
};

std::ostream &operator<<(std::ostream &os, const TwoD &bod)
{
    os << "{" << bod._x << "," << bod._y << "}";
    return os;
}

class ThreeD
{
private:
    float _x, _y, _z;

public:
    ThreeD(float x, float y, float z) : _x(x), _y(y), _z(z) {}

    ThreeD operator+(const ThreeD &other) const
    {
        return ThreeD(_x + other._x, _y + other._y, _z * other._z);
    }

    friend std::ostream &operator<<(std::ostream &os, const ThreeD &bod);
};

std::ostream &operator<<(std::ostream &os, const ThreeD &bod)
{
    os << "{" << bod._x << "," << bod._y << "," << bod._z << "}";
    return os;
}

int main()
{
    const Grupoid<float> g(5.6f);
    const Grupoid<float> n = math::move(g, 1.1f);
    n.print();

    const Grupoid<std::string> s("ahoj");
    const Grupoid<std::string> ns = math::move(s, std::string("svete"));
    ns.print();

    const Grupoid<TwoD> td(TwoD(1.0f, 3.2f));
    const Grupoid<TwoD> tds = math::move(td, TwoD(1.0f, 1.2f));
    tds.print();

    const Grupoid<ThreeD> td3(ThreeD(1.0f, 3.2f, 1.2f));
    const Grupoid<ThreeD> tds3 = math::move(td3, ThreeD(1.0f, 1.2f, 2.0f));
    tds3.print();

    return 0;
}