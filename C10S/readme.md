### Samostatná práce - abstraktní třídy

- vašim úkolem bude vytvořit "vozový park" a sledovat různé vlastnosti vozidel, při různých atributech.

#### 1. Abstraktní třída `Vehicle`
Vytvořte abstraktní třídu `Vehicle`, která obsahuje:
- **Čistě virtuální metody**:
  - `void print() const`: Vypíše vlastnosti vozidla.
  - `T computeMaxSpeed() const`: Vypočítá maximální rychlost vozidla na základě jeho parametrů.
- **Metoda `estimateTravelTime`**:
  - Vypočítá čas potřebný k ujetí zadané vzdálenosti (`distance`) na základě výsledku `computeMaxSpeed`.

---

#### 2. Třída `Car`
Vytvořte třídu `Car`, která dědí z `Vehicle` a má tyto vlastnosti:
- **Atributy**:
  - `T engineSize`: Velikost motoru v litrech (např. 1.6, 2.0).
  - `int seats`: Počet sedadel.
- **Implementace metod**:
  - `print`: Vypíše velikost motoru a počet sedadel.
  - `computeMaxSpeed`: Maximální rychlost vypočítá vzorcem:  
    `engineSize * 50 - seats * 5`.

---

#### 3. Třída `Motorcycle`
Vytvořte třídu `Motorcycle`, která dědí z `Vehicle` a má tyto vlastnosti:
- **Atributy**:
  - `T aerodynamics`: Aerodynamický koeficient (nižší hodnota = lepší aerodynamika).
  - `int type`: Typ motorky (např. 0 - "sport", 1 - "touring").
- **Implementace metod**:
  - `print`: Vypíše aerodynamický koeficient a typ motorky.
  - `computeMaxSpeed`: Maximální rychlost vypočítá vzorcem:  
    - `200 / aerodynamics` pro sportovní motorku.
    - `150 / aerodynamics` pro cestovní motorku.

---

#### 4. Vytvoření seznamu vozidel
V hlavní funkci:
1. Vytvořte seznam (`std::vector<std::shared_ptr<Vehicle<T>>>`), který obsahuje několik různých aut a motorek s různými parametry (zadané v konstruktoru).
2. Vypište vlastnosti každého vozidla pomocí metody `print`.
3. Pro každé vozidlo spočítejte a vypište jeho maximální rychlost (`computeMaxSpeed`) a odhadovaný čas na cestu dlouhou 100 km (`estimateTravelTime`).
4. Pozorujte, jak se mění odhadovaný čas na cestu s různými parametry vozidel, zadaných v konstruktorech.

---

#### Bonus: Další vozidlo
- Přidejte další typ vozidel - nákladní auta (truck), která mají maximální rychlost závislou na váze nákladu a výkonu motoru.
- implementujte https://en.cppreference.com/w/cpp/algorithm/sort funkci, která bude srovnávat podle max. rychlosi (ASC i DESC)

  


