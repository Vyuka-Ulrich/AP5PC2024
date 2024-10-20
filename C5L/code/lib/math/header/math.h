#include <point.h>

namespace Math
{
    int add(int a, int b);

    // TODO: AZ BUDE vector
    // template<typename T>
    // Point<T> operator+(const Point<T>& p, const Vector<T>& v);

    template<typename T>
    Point<T> posun(const Point<T>& p);
}

#include "../template/math.tpp"
