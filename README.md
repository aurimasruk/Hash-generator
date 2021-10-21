# Hash-generator
Maišos funkcija (hash kodų generatorius).
Repositorija skirta Blockchain Technology pratyboms.

## Apie maišos funkciją
Maišos (hash) funkcija atitinka šiuos reikalavimus:

* Maišos funkcijos įėjimas (angl. input) gali būti bet kokio dydžio simbolių eilutė (angl. string).
* Maišos funkcijos išėjimas (angl. output) visuomet yra to paties, fiksuoto, dydžio rezultatas (64 simbolių hex'as).
* Maišos funkcija yra deterministinė.
* Maišos funkcijos reikšmė/kodas (hash‘as) bet kokiai input'o reikšmei yra apskaičiuojamas greitai - efektyviai.
* Iš hash funkcijos rezultato (output'o) praktiškai neįmanoma atgaminti pradinio įvedimo (input'o).
* Maišos funkcija yra atspari "kolizijai" (angl. collision resistance).


## Maišos funkcijos veikimo principas
Algoritmas turi pradinį seed'ą, su kuriuo yra modifikuojamas pradinio įvedimo simbolių eilutė ją pasivertus į `int` tipą. Gavus initial_hash, jis yra paverčiamas į `string`, kuriame yra apskaičiuojamas gautojo initial_hash size. Susikūrus papildomą random_variable yra vykdoma galutinė hash funkcija, kuri išveda hex 64 simbolių eilutę.

## Programos veikimas
[Atsidarius programą](#programos-įdiegimas-ir-naudojimasis), naudotojas gali rinktis iš jam duotų 5 variantų:
1. Input in console
2. Input from file
3. Comparison
4. Collision test
5. Difference test

### Input in console
```
Your input: abc
3e54b6b8a582724cf7722ffafc100885a9ebb3a77279c9911bbaa998a5833035
```

### Input from file
```
Select file: 
---------------
1. a.txt
2. b.txt
3. randomText1.txt
4. randomText2.txt
5. 1500symbols_1.txt
6. 1500symbols_2.txt
7. empty.txt
8. konstitucija.txt
9. all files
----------------
1
a4d6714df92bc6913dd66008a4d66009b5e7714df92ab55df9922cc571a33dd5
```

### Comparison
```
Comparing different hashing algorithm times:
----------------------------------------------
Custom hash time: 1.763s.
Md5 hash time: 2.078s.
Sha1 hash time: 2.852s.
Sha256 hash time: 3.07s.
----------------------------------------------
```

### Collision test
```
Starting collision test:
------------------------
Collisions: 1 out of 100'000 tests
```

### Difference test
```
Starting difference test
------------------------
                               hex     bits
Minimum difference in pairs:   43      61
Maximum difference in pairs:   64      174
Average difference in pairs:   93.8%   50.1%
```

## Programos įdiegimas ir naudojimasis 
* Atsisiųskite naujausią programos versiją iš [Releases](https://github.com/aurimasruk/Hash-generator/releases) ir ją išarchyvuokite
* Komandinėje eilutėje įveskite `g++ functions.cpp includes/md5.cpp includes/sha1.cpp includes/sha256.cpp main.cpp -o2 -o main` ir `./main`.
* Pradėjus veikti programai, įveskite reikalaujamus duomenis ir sekite nurodymus.
