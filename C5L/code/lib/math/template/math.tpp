template <class T>
Grupoid<T> math::move(const Grupoid<T> old, T value)
{
    return Grupoid<T>(old.getX() + value);
}