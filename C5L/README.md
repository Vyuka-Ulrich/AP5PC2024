# Cviko 5 - templates a přetěžování operátorů

- const corectness k prostudování: [https://www.youtube.com/watch?v=4fJBrditnJU](youtube)

při použití templates je nutné změnit strukturu tak, abychom mohli importovat definice templates do definice hlavičkových souborů (takto to c++ vyžaduje)
```
.
├── CMakeLists.txt
├── lib
│   ├── CMakeLists.txt
│   ├── math
│   │   ├── CMakeLists.txt
│   │   ├── header
│   │   │   └── math.h
│   │   ├── math.cpp
│   │   └── template
│   │       └── math.tpp
│   └── point
│       ├── CMakeLists.txt
│       ├── header
│       │   └── point.h
│       ├── point.cpp
│       └── template
│           └── point.tpp
└── main.cpp
```

Header file musi dole tedy obsahovat include template file s definicemi funkcí
header/point.h
```c++
#ifndef POINT_H
#define POINT_H

#include <iostream> // For std::cout

// Templated Point class declaration
template <typename T>
class Point
{
    T x;

public:
    // Constructor
    Point(T x_);

    T getX() const;

    // Method to print the coordinates of the Point
    void print() const;
};

// Include the template implementation file
#include "../template/point.tpp"

#endif // POINT_H
```

Template file (specialni přípona .tpp) potom definice **pouze templatovaných** funkcí.
(všimni si, že v point.tpp není include point.h, tento soubor naopak includujeme do point.h)
template/point.tpp
```c++
// Constructor implementation
template<typename T>
Point<T>::Point(T x_) : x(x_) {}

// Definition of the print() method to display the point's coordinates
template<typename T>
void Point<T>::print() const {
    std::cout << "Point(" << x << ")" << std::endl;
}

template <typename T>
T Point<T>::getX() const
{
    return x;
}
```

point.cpp může zůstat prázdné, pokud nemáme **žádné templatované funkce**

point/CMakeLists.txt:
```
add_library(point point.cpp)

target_include_directories(point PUBLIC 
header
template)
```

Pokud budeme chtít implementovat templatované funkce v knihovně math, postupujeme stejně:
math/header/math.h:
```c++
#include <point.h>

namespace Math
{
    int add(int a, int b);

    template<typename T>
    Point<T> posun(const Point<T>& p);
}

#include "../template/math.tpp"

```

math.tpp poté (všimni si, že v math.tpp není include math.h, tento soubor naopak includujeme do math.h):
```c++
template <typename T>
Point<T> Math::posun(const Point<T> &p)
{
    return Point<T>(p.getX() + 2);
}
```

v math.cpp tentokrát máme definici jedné netemplatované funkce z headeru (add)
```c++
#include <math.h>

int Math::add(int a, int b)
{
    return a + b;
}
```
