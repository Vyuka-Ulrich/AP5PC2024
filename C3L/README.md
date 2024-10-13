## Samostudium struktur/tříd a modifikátorů přístupu

Třída, defaultní modifikátory private:

```cpp
class Point
{
private: // neni potreba, private je default
    float _x, _y;

public:
    Point(float x, float y);

    float getX();

    float getY();

    void print();
};
```

Stuktura, defaultně vše public:

```cpp
struct Point
{
// default je public:
    Point(float x, float y);

    float getX();

    float getY();

    void print();

private: // je potreba, zmena na private!
    float _x, _y;
};
```

main:

```cpp
int main()
{
  // alokace na zasobniku:
  Point p(5.6,2.3);

  // alokace na halde:
  auto hal = new Point(5.7,4.2);
  hal->print();
  delete(hal); // !!!

  return 0;
}
```

