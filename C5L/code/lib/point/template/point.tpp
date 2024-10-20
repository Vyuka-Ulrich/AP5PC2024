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