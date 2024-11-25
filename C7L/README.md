# Pokročilé funkce c++ 20 - Koncepty a Optional

Příklad jednoduché funkce, která očekává, že co vložíme se dá sčítat a porovnávat s integerem:

```c++
#include <iostream>
#include <concepts>
#include <optional>
#include <string>

// Koncept Addable zajistí, že typ T podporuje operátor +
template <typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::same_as<T>;
};

// Koncept ComparableWithZero zajišťuje, že typ T lze porovnat s nulou
template <typename T>
concept ComparableWithZero = requires(T a) {
    { a > 0 } -> std::convertible_to<bool>;
};

// Funkce addIfPositive sčítá dvě kladné hodnoty typu T, pokud splňují koncepty Addable a ComparableWithZero
template <Addable T>
    requires ComparableWithZero<T>
std::optional<T> addIfPositive(T a, T b) {
    // Kontrola, zda jsou obě hodnoty kladné
    if (a > 0 && b > 0) {
        // Vracíme výsledek sčítání zabalený v std::optional
        return a + b;
    } else {
        // Pokud není podmínka splněna, vrátíme prázdný std::optional
        return std::nullopt;
    }
}

int main() {
    // Testování s typem int - funguje správně
    auto result1 = addIfPositive(3, 7);
    if (result1.has_value()) {
        std::cout << "Výsledek sčítání 3 + 7 je: " << result1.value() << std::endl;
    } else {
        std::cout << "Sčítání 3 + 7 nebylo možné." << std::endl;
    }

    // Testování s typem std::string - způsobí chybu při kompilaci
    auto result2 = addIfPositive(std::string("Hello, "), std::string("world!"));
    if (result2.has_value()) {
        std::cout << "Výsledek sčítání řetězců: " << result2.value() << std::endl;
    } else {
        std::cout << "Sčítání řetězců nebylo možné." << std::endl;
    }

    return 0;
}

```

Koncepty můžeme chainovat, někdy je však lepší zgrupovat pod společný koncept:

```c++
// Kombinovaný koncept pro zjednodušení
template <typename T>
concept Calculable = Addable<T> && ComparableWithZero<T>;

// Funkce calculateAndConvert s použitím kombinovaného konceptu
template <Calculable T>
std::optional<T> addIfPositive(T a, T b) {
    // Kontrola, zda jsou obě hodnoty kladné
    if (a > 0 && b > 0) {
        // Vracíme výsledek sčítání zabalený v std::optional
        return a + b;
    } else {
        // Pokud není podmínka splněna, vrátíme prázdný std::optional
        return std::nullopt;
    }
}
```

Můžeme definovat vlastní typ (`CustomNumber`) a vyzkoušet jestli taky funguje s funkcí `addIfPositive`:

```c++
#include <iostream>
#include <concepts>
#include <optional>

// Koncept Addable zajistí, že typ T podporuje operátor +
template <typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::same_as<T>;
};

// Koncept ComparableWithZero zajišťuje, že typ T lze porovnat s nulou
template <typename T>
concept ComparableWithZero = requires(T a) {
    { a > 0 } -> std::convertible_to<bool>;
};

// Vlastní typ CustomNumber, který podporuje operátory + a >
class CustomNumber {
private:
    int value;

public:
    // Konstruktor
    CustomNumber(int v) : value(v) {}

    // Přetížení operátoru +
    CustomNumber operator+(const CustomNumber& other) const {
        return CustomNumber(value + other.value);
    }

    // Přetížení operátoru >
    bool operator>(int other) const {
        return value > other;
    }

    // Přetížení operátoru << pro výpis
    friend std::ostream& operator<<(std::ostream& os, const CustomNumber& num) {
        os << num.value;
        return os;
    }
    
    // Getter pro hodnotu (pro kontrolu)
    int getValue() const {
        return value;
    }
};

// Funkce addIfPositive sčítá dvě kladné hodnoty typu T, pokud splňují koncepty Addable a ComparableWithZero
template <Addable T>
    requires ComparableWithZero<T>
std::optional<T> addIfPositive(T a, T b) {
    // Kontrola, zda jsou obě hodnoty kladné
    if (a > 0 && b > 0) {
        // Vracíme výsledek sčítání zabalený v std::optional
        return a + b;
    } else {
        // Pokud není podmínka splněna, vrátíme prázdný std::optional
        return std::nullopt;
    }
}

int main() {
    // Testování s naším vlastním typem CustomNumber
    CustomNumber num1(10);
    CustomNumber num2(5);

    auto result = addIfPositive(num1, num2);
    if (result.has_value()) {
        std::cout << "Výsledek sčítání num1 + num2 je: " << result.value() << std::endl;
    } else {
        std::cout << "Sčítání num1 + num2 nebylo možné." << std::endl;
    }

    // Testování s negativní hodnotou
    CustomNumber num3(-3);
    auto result2 = addIfPositive(num1, num3);
    if (result2.has_value()) {
        std::cout << "Výsledek sčítání num1 + num3 je: " << result2.value() << std::endl;
    } else {
        std::cout << "Sčítání num1 + num3 nebylo možné." << std::endl;
    }

    return 0;
}

```

### Pokročilé
Můžeme definovat funkci, která funguje obecně na jakémkoli objektu, za přepokladu že objekt něco splňuje:
Zde funkce scaleObject umí škálovat jakýkoli ojekt, pro který však platí, že je škálovatelný (dá se násobit s číslem).
Pozor, koncept nyní používáme jako `Scalable<T, int>`, protože jsme definovali i typ.

```c++
#include <iostream>
#include <concepts>

// Definice konceptu Scalable, který zajišťuje, že typ T podporuje operátor * s typem ScaleType
template <typename T, typename ScaleType>
concept Scalable = requires(T obj, ScaleType factor) {
    { obj * factor } -> std::same_as<T>;
};

// Třída Rectangle
template <typename T>
class Rectangle {
private:
    T width;
    T height;

public:
    // Konstruktor
    Rectangle(T width, T height) : width(width), height(height) {}

    // Getter pro šířku a výšku
    T getWidth() const { return width; }
    T getHeight() const { return height; }

    // Přetížení operátoru * pro škálování
    Rectangle operator*(T scaleFactor) const {
        return Rectangle(width * scaleFactor, height * scaleFactor);
    }

    // Přetížení operátoru << pro výpis
    friend std::ostream& operator<<(std::ostream& os, const Rectangle& rect) {
        os << "Rectangle(width=" << rect.width << ", height=" << rect.height << ")";
        return os;
    }
};

// Třída Square
template <typename T>
class Square {
private:
    T side;

public:
    // Konstruktor
    Square(T side) : side(side) {}

    // Getter pro stranu
    T getSide() const { return side; }

    // Přetížení operátoru * pro škálování
    Square operator*(T scaleFactor) const {
        return Square(side * scaleFactor);
    }

    // Přetížení operátoru << pro výpis
    friend std::ostream& operator<<(std::ostream& os, const Square& sq) {
        os << "Square(side=" << sq.side << ")";
        return os;
    }
};

// Funkce, která škáluje objekt typu T, pokud splňuje koncept Scalable
template <Scalable<T, int> T>
T scaleObject(const T& obj, int factor) {
    return obj * factor;
}

int main() {
    Rectangle<int> rect(4, 5);
    Square<int> sq(6);

    std::cout << "Původní " << rect << std::endl;
    std::cout << "Původní " << sq << std::endl;

    auto scaledRect = scaleObject(rect, 2);
    auto scaledSquare = scaleObject(sq, 3);

    std::cout << "Škálovaný obdélník: " << scaledRect << std::endl;
    std::cout << "Škálovaný čtverec: " << scaledSquare << std::endl;

    return 0;
}

```

## Pokročilé 2: Rozdílné T a S

```c++
#include <iostream>
#include <concepts>
#include <type_traits>

template <class T, class S>
concept Scalable = requires(T a, S b) {
    { a *b } -> std::same_as<T>;
};

// template <class T, class S>
// concept FloatingPofloat = std::is_arithmetic_v<S>;

template <class T, class S>
concept Affine = std::is_arithmetic_v<S> && Scalable<T, S>;

template <class T, class S>
    requires Affine<T, S>
T scale(T a, S b)
{
    return a * b;
}

class Rectangle
{
    float _a, _b;

public:
    Rectangle(float a, float b) : _a(a), _b(b) {}

    float getArea() const
    {
        return _a * _b;
    }

    Rectangle operator*(float scalar) const
    {
        return Rectangle(_a * scalar, _b * scalar);
    }

    friend std::ostream &operator<<(std::ostream &os, const Rectangle &rec)
    {
        os << "Rectangle(" << rec._a << "," << rec._b << ")";
        return os;
    }
};

class Square
{
    float _a;

public:
    Square(float a) : _a(a)
    {
    }

    float getArea() const
    {
        return _a * _a;
    }

    Square operator*(float scalar) const
    {
        return Square(_a * scalar);
    }

    friend std::ostream &operator<<(std::ostream &os, const Square &rec)
    {
        os << "Square(" << rec._a << ")";
        return os;
    }
};

int main()
{

    std::cout << Rectangle(5, 6) << std::endl;
    std::cout << Square(5) << std::endl;

    std::cout << scale(Rectangle(2.1, 3.5), 2).getArea() << std::endl;

    const auto ctverec = Square(1);
    std::cout << scale(ctverec, 4) << std::endl;
    std::cout << ctverec.getArea() << std::endl;
    const auto bigger = scale(ctverec, 3);
    std::cout << bigger.getArea() << std::endl;

    return 0;
}
```
