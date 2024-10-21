#include <grupoid.h>

namespace math
{
    int add(int a, int b);

    template <class T>
    Grupoid<T> move(const Grupoid<T> old, T value);
}

#include "../template/math.tpp"