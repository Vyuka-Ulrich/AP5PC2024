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