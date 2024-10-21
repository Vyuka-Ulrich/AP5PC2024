#include <point.h>

namespace Math
{
    int add(int a, int b);

    // TODO: AZ BUDE vector
    // template<typename T>
    // Point<T> operator+(const Point<T>& p, const Vector<T>& v);

    template <class T>
    Point<T> posun(const Point<T> &p, T value);
}

#include "../template/math.tpp"
