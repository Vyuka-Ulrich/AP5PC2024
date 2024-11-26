# Dědičnost, abstraktní třídy


## virtual, override
```c++
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

    // Násobení všech vektorů skalárem 2
    std::transform(vectors.begin(), vectors.end(), vectors.begin(),
        [](std::shared_ptr<Scalable> vec) {
            vec->scale(2); // Násobení skalárem
            return vec;
        });

    for (const auto& vec : vectors) {
        std::cout << *vec << std::endl;
    }

    return 0;
}
```
`std::shared_ptr` automaticky uvolní paměť, když už na ni nikdo neukazuje.

Alternativa: `std::unique_ptr`

Pokud nepotřebujete sdílení vlastnictví (v našem kódu není sdílení nutné), můžete použít `std::unique_ptr`

```c++
std::vector<std::unique_ptr<Scalable>> vectors;
vectors.push_back(std::make_unique<ScalableVector<int>>(5));
vectors.push_back(std::make_unique<ScalableVector<float>>(3.14f));
vectors.push_back(std::make_unique<ScalableVector<Point<int>>>(Point<int>(2, 3)));
```

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


