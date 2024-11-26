# Dědičnost, abstraktní třídy


## virtual, override
```c++
#include <iostream>
using namespace std;

// Základní třída
class Base {
public:
    // Virtuální metoda
    virtual void show() const {
        cout << "Base class show method\n";
    }

    // Nevirtuální metoda
    void nonVirtualShow() const {
        cout << "Base class non-virtual method\n";
    }
};

// Odvozená třída
class Derived : public Base {
public:
    void show() const override {
        cout << "Derived class show method\n";
    }

    void nonVirtualShow() const {
        cout << "Derived class non-virtual method\n";
    }
};

int main() {
    // Vytvoření instance odvozené třídy
    Derived derived;

    // Ukázka upcastingu (přiřazení Derived objektu do Base ukazatele)
    Base* basePtr = &derived;

    // Virtuální metoda volána přes ukazatel na základní třídu
    cout << "Calling virtual method:\n";
    basePtr->show(); // Volá se "Derived class show method" díky virtual

    // Nevirtuální metoda volána přes ukazatel na základní třídu
    cout << "Calling non-virtual method:\n";
    basePtr->nonVirtualShow(); // Volá se "Base class non-virtual method"

    return 0;
}
```

## moznosti ukazatelu v mainu 
TODO


`std::shared_ptr` automaticky uvolní paměť, když už na ni nikdo neukazuje.

Alternativa: `std::unique_ptr`

Pokud nepotřebujete sdílení vlastnictví (v našem kódu není sdílení nutné), můžete použít `std::unique_ptr`

Surové ukazatele:
**JE POTŘEBA RUČNĚ UVOLNIT!**
```c++
std::vector<Scalable*> vectors;
vectors.push_back(new ScalableVector<int>(5));
vectors.push_back(new ScalableVector<float>(3.14f));
vectors.push_back(new ScalableVector<Point<int>>(Point<int>(2, 3)));

// Ruční uvolnění paměti
for (auto& vec : vectors) {
   delete vec;
}
```

## Abstraktní třída (interface)
Vytvoření abstraktní třídy
```c++
class Scalable {
public:
    virtual ~Scalable() = default;
    virtual void scale(double scalar) = 0;
    virtual void print(std::ostream& os) const = 0;
};
```

Vytvoření konceptu:
```c++
template <typename T>
concept ScalableType = requires(T a, double scalar) {
    { a * scalar } -> std::convertible_to<T>;
};
```

Podědění:
```c++
template <ScalableType T>
class ScalableVector : public Scalable {
public:
    T value;

    ScalableVector(T value = T{}) : value(value) {}

    void scale(double scalar) override {
        value = value * static_cast<T>(scalar);
    }

    void print(std::ostream& os) const override {
        os << value;
    }
};
```

## Kompletní příklad:

```c++
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <concepts>

// Třída Point
template <typename T>
class Point {
public:
    T x;
    T y;

    Point(T x = 0, T y = 0) : x(x), y(y) {}

    Point operator*(T scalar) const {
        return Point(x * scalar, y * scalar);
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }
};

// Abstraktní třída Scalable
class Scalable {
public:
    virtual ~Scalable() = default;
    virtual void scale(double scalar) = 0;
    virtual void print(std::ostream& os) const = 0;
};

inline std::ostream& operator<<(std::ostream& os, const Scalable& obj) {
    obj.print(os);
    return os;
}

// Koncept pro typy podporující násobení skalárem
template <typename T>
concept ScalableType = requires(T a, double scalar) {
    { a * scalar } -> std::convertible_to<T>;
};

// Šablona ScalableVector
template <ScalableType T>
class ScalableVector : public Scalable {
public:
    T value;

    ScalableVector(T value = T{}) : value(value) {}

    void scale(double scalar) override {
        value = value * static_cast<T>(scalar);
    }

    void print(std::ostream& os) const override {
        os << value;
    }
};

int main() {
    // Vytvoření seznamu vektorů různých typů
    std::vector<std::shared_ptr<Scalable>> vectors;
    vectors.push_back(std::make_shared<ScalableVector<int>>(5));
    vectors.push_back(std::make_shared<ScalableVector<float>>(3.14f));
    vectors.push_back(std::make_shared<ScalableVector<Point<int>>>(Point<int>(2, 3)));

    // Násobení všech vektorů skalárem 2 pomocí std::transform
    std::transform(vectors.begin(), vectors.end(), vectors.begin(),
        [](std::shared_ptr<Scalable> vec) {
            vec->scale(2); // Násobení skalárem
            return vec;
        });

    // Výpis výsledků
    for (const auto& vec : vectors) {
        std::cout << *vec << std::endl;
    }

    return 0;
}
```


