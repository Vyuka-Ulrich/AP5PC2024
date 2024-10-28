### Úkol: Implementace tříd `Point` a `Vector` s přetížením operátorů

**Cíl**: V tomto úkolu vytvoříte třídy `Point` a `Vector`, které reprezentují body a vektory v jednorozměrném prostoru, a přidáte přetížené operátory tak, aby bylo možné provádět sčítání bodu s vektorem a odečítání dvou bodů.

---

#### Podrobnosti zadání

1. **Vytvořte třídu `Point`**:
   - Třída bude šablonová (`template <class T>`) a bude mít jeden soukromý atribut `_x` typu `T`, který představuje souřadnici bodu.
   - Implementujte konstruktor, který inicializuje `_x` hodnotou předanou při vytvoření objektu.
   - Přidejte veřejnou metodu `getX()`, která vrátí hodnotu `_x`.

2. **Vytvořte třídu `Vector`**:
   - Stejně jako třída `Point`, i `Vector` bude šablonová třída s jedním atributem `_x`, který představuje velikost vektoru.
   - Implementujte konstruktor, metodu `getX()` podobně jako v `Point`.

3. **Přetížení operátorů**:
   - **Operátor `+` v `Point`**: Přetěžte operátor `+` tak, aby přijal `Vector` jako argument, přičetl souřadnici `_x` vektoru k `_x` bodu a vrátil nový `Point` s touto souřadnicí.
   - **Operátor `-` v `Point`**: Přetěžte operátor `-` tak, aby přijal jiný `Point` jako argument, vypočítal rozdíl souřadnic `_x` obou bodů a vrátil nový `Vector` s touto velikostí.

4. **Přetížení operátoru `<<`**:
   - Implementujte přetížení operátoru `<<` pro `Point` i `Vector`, aby bylo možné výstup formátovat přímo pomocí `std::cout`. Například pro `Point` by výstup mohl vypadat takto: `Point(5.5)`.

---

#### Příklad použití v `main`:

Váš kód by měl fungovat následovně:

```cpp
const Point<float> point(5.5f);
const Vector<float> vector(2.2f);

const Point<float> np = point + vector;
const Vector<float> newVec = np - point;

std::cout << np << std::endl;    // Výstup: Point(7.7)
std::cout << vector << std::endl; // Výstup: Vector(2.2)
std::cout << newVec << std::endl; // Výstup: Vector(2.2)
```

---

#### Očekávaný výstup

- **Sčítání** (`+`): Když se přičte `Vector` k `Point`, měl by být vytvořen nový bod se souřadnicí odpovídající součtu `_x` bodu a `_x` vektoru.
- **Odečítání** (`-`): Když se odečte jeden `Point` od druhého, měl by být vrácen `Vector`, jehož velikost odpovídá rozdílu mezi oběma body.
- **Výstup**: Každý objekt by měl být možné jednoduše vypsat pomocí `std::cout` ve formátu `Point(x_value)` nebo `Vector(x_value)`.

#### Poznámky:
- Soustřeďte se na správné použití šablon (template) a přetížení operátorů.
- Dbejte na správnou strukturu kódu a na čistotu výstupu dle zadání.
