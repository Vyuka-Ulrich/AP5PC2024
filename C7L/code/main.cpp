#include <iostream>
#include <optional>
#include <concepts>

template <class T>
concept Scalable = requires(T objekt, float s) {
    { objekt *s } -> std::same_as<T>;
};

template <Scalable T>
T scale(T objekt, float scalar)
{
    return objekt * scalar;
};

class Square
{
private:
    float _a;

public:
    Square(float a) : _a(a) {};

    Square operator*(float scalar) const
    {
        return Square(_a * scalar);
    }

    float area() const
    {
        return _a * _a;
    };

    friend std::ostream &operator<<(std::ostream &os, const Square &num)
    {
        os << "Ctverec[a=" << num._a << ",S=" << num.area() << "]";
        return os;
    }
};

class Circle
{
private:
    float _r;

public:
    Circle(float r) : _r(r) {};

    Circle operator*(float scalar) const
    {
        return Circle(_r * scalar);
    }

    float area() const
    {
        return 3.1415 * (_r * _r);
    };

    friend std::ostream &operator<<(std::ostream &os, const Circle &num)
    {
        os << "Kruh[r=" << num._r << ",S=" << num.area() << "]";
        return os;
    }
};

using namespace std;

int main()
{
    auto result = scale(Square(4), 2);

    cout << scale(Circle(1), 1) << endl;
    cout << scale(Circle(1), 2) << endl;
    cout << scale(Circle(1), 4) << endl;

    std::cout << result << std::endl;

    return 0;
}