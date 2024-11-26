#include <iostream>
#include <memory>
#include <list>
#include <vector>

using namespace std;

class Base
{
public:
    virtual void show() const
    {
        cout << "ja jsem Base VIRTUAL";
    }

    void nonvirtualshow() const
    {
        cout << "ja jsem Base NONVIRTUAL";
    }
};

class Derived : public Base
{
    void show() const override
    {
        cout << "ja jsem Derived";
    }

    void nonvirtualshow() const
    {
        cout << "ja jsem Derived nonvirtual";
    }
};

template <class T>
concept Scalable = requires(T a, double scalar) {
    { a *scalar } -> std::convertible_to<T>;
};

class AbstractScalable
{
public:
    virtual ~AbstractScalable() = default;
    virtual std::unique_ptr<AbstractScalable> scale(double scalar) const = 0;
    virtual void print() const = 0;
};

template <Scalable T>
class Square : public AbstractScalable
{
    T _value;

public:
    Square(T value) : _value(value) {};

    T getValue() const
    {
        return _value;
    }

    T getArea() const
    {
        return _value * _value;
    }

    std::unique_ptr<AbstractScalable> scale(double scalar) const override
    {
        return std::make_unique<Square>(Square(_value * scalar));
    }

    void print() const override
    {
        cout << "Square:" << _value;
    }
};

template <Scalable T>
class Circle : public AbstractScalable
{
    T _value;

public:
    Circle(T val) : _value(val) {}

    T getValue() const
    {
        return _value;
    }

    T getArea() const
    {
        return 3.1415 * _value * _value;
    }

    std::unique_ptr<AbstractScalable> scale(double scalar) const override
    {
        return std::make_unique<Circle>(Circle(_value * scalar));
    }

    void print() const override
    {
        cout << "Circle:" << _value;
    }
};

template <class T>
class Rectangle
{
public:
    T _x;
    Rectangle(T x) : _x(x) {}
};

int main()
{

    // std::unique_ptr<Base> s = std::make_unique<Derived>(Derived());
    // s->show();
    // s->nonvirtualshow();

    // auto s = std::make_unique<Square<float>>(Square(5.2f));
    // cout << s->getArea();


    std::vector<std::unique_ptr<AbstractScalable>> v;
    v.push_back(std::make_unique<Circle<int>>(Circle(5)));
    v.push_back(std::make_unique<Square<int>>(Square(6)));
    v.push_back(std::make_unique<Circle<int>>(Circle(6)));

    // jina moznost, ale musime deletovat!!
    // std::vector<AbstractScalable*> v;
    // v.push_back(new Circle(5));
    // v.push_back(new Square(6));


    for (auto &item : v)
    {   cout << "stary:";
        item->print();
        item->
        cout << " novy:";
        (item->scale(5))->print();
        cout << endl;
    }

    // v.print();

    return 0;
}