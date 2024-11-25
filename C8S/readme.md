Minule jsme si vytvořili templatovaný Point a Vektor.

Dnes je vylepšíme o koncepty:
- přidej koncept, který zamezí substituci T za něco co by se nedalo sčítat
- pak demonstruj sečtení dvou čísel pomocí součtu Point<int> + Vektor<int>
- pak demonstruj koncepty tak, že se pokusíš sečíst Point<TřidaBez+> + Vektor<Trida> (tyto třídy stačí mít v main.cpp)
- nakonec vytvoř dvě třídy (stačí v main.cpp, případně test.cpp)

**Pak**
- třída Time, která bude reprezentovat bod (Rok, Měsíc, den, hodina, minuta)
- třída Duration, která bude reprezentovat vektor (minuty)
- V mainu demonstruj, jak vytvoříš bod, který obsahuje aktuální čas a přidej k němu různý počet minut
- je nezbytné respektovat přechody! 🕢 + 30m = 🕗
- ([2024 12.11. 7:30] + 30m = [2024 12.11. 8:00]),
- ([2024 12.11. 23:40] + 40m = [2024 13.11. 00:20])
- každý měsíc má 30 dnů, rok má 12 měsíců

- testy jsou za bod navíc
