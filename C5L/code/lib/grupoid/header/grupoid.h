template <class T>
class Grupoid
{
private:
    T _x;

public:
    Grupoid(T x);

    T getX() const;

    void print() const;
};

#include "../template/grupoid.tpp"

