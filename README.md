# Hash-generator
Maišos funkcija (hash kodų generatorius).
Repositorija skirta Blockchain Technology pratyboms.

## Apie maišos funkciją
Maišos (hash) funkcija pasižymi šiais reikalavimais:

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
x
```

### Input from file
```
x
```

### Comparison
```
x
```

### Collision test
```
x
```

### Difference test
```
x
```


## Programos įdiegimas ir naudojimasis 
* Atsisiūskite naujausią programos versiją iš [Releases](https://github.com/aurimasruk/Hash-generator/releases) ir ją išarchyvuokite
* Komandinėje eilutėje įveskite `g++ functions.cpp includes/md5.cpp includes/sha1.cpp includes/sha256.cpp main.cpp -o2 -o main` ir `./main`.
* Pradėjus veikti programai, įveskite reikalaujamus duomenis ir sekite nurodymus.
