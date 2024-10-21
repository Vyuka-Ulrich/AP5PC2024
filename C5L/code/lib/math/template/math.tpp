template <class T>
Point<T> Math::posun(const Point<T> &p, T value)
{
    return Point<T>(p.getX() + value);
}
