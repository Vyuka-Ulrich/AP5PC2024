#include <iostream>

template <class T>
Grupoid<T>::Grupoid(T x) : _x(x)
{
}

template <class T>
T Grupoid<T>::getX() const
{
    return _x;
}


template <class T>
void Grupoid<T>::print() const
{
    std::cout << "[" << _x << "]" << std::endl;
}
