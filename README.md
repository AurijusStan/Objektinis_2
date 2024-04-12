# Objektinio užduotis 2
  Programa skaičiuojanti galutinį studento rezultatą pagal pateiktus namų darbų ir egzamino rezultatus.

## Funkcionalumas
  - Meniu kuriame galima pasirinkti, ką atsitiktinai generuoti.
  - Duomenų skaitymas iš išankstinio failo.
  - Duomenų įvedimas.
  - Duomenų failo kūrimas. 
  - Galutinio balo skaičiavimas pagal vidurkį ir medianą.
  - Galima skaityti duomenis iš tam tikru formatu pateiktų teksto failų.
  - "Pažengusių" ir "Žlugusių" mokinių išvedimas atskiruose failuose.

## Naudojimosi instrukcijos
  - Įjungti programą.
  - Sekti terminale matomus žingsnius.
  - Jei prašome vesti failo pavadinimą, vesti be ".txt" pabaigoje.
  - Gauti rezultatus.

## Sistemos specifikacijos

- **CPU**: AMD Ryzen 5 5600H 3.30 GHz
- **RAM**: DDR4 16GB
- **HDD**: SSD 512GB

## Failų generavimo greičio testai
| Failas | 1 testas | 2 testas | 3 testas | Vidurkis |
| :--- | ---- | ---- | ---- | ---- |
| stud1000 | 11 | 5 | 10 | 9 |
| stud10000 | 56 | 55 | 51 | 54 |
| stud100000 | 509 | 505 | 493 | 502 |
| stud1000000 | 5130 | 5160 | 5463 | 5251 |
| stud10000000 | 63968 | 55163 | 54541 | 57891 |

## Greičio testai (5 testų vidurkis) ms

#### Vector
| Failas | Skaitymo trukmė | Rūšiavimo trukmė | Skirstymo trukmė |
| :--- | ---- | ---- | ---- |
| stud1000 | 8 | 0 | 0 |
| stud10000 | 87 | 10 | 1 |
| stud100000 | 885 | 147 | 25 |
| stud1000000 | 8888 | 1856 | 282 |
| stud10000000 | 87697 | 23683 | 3211 |

#### List
| Failas | Skaitymo trukmė | Rūšiavimo trukmė | Skirstymo trukmė |
| :--- | ---- | ---- | ---- |
| stud1000 | 8 | 1 | 0 |
| stud10000 | 87 | 7 | 3 |
| stud100000 | 887 | 78 | 44 |
| stud1000000 | 9001 | 1302 | 452 |
| stud10000000 | 92646 | 18116 | 5311 |

#### Deque
| Failas | Skaitymo trukmė | Rūšiavimo trukmė | Skirstymo trukmė |
| :--- | ---- | ---- | ---- |
| stud1000 | 7 | 1 | 0 |
| stud10000 | 92 | 15 | 2 |
| stud100000 | 859 | 198 | 27 |
| stud1000000 | 9022 | 2657 | 330 |
| stud10000000 | 90114 | 32947 | 4149 |

## Skirstymas pagal skirtingas strategijas (3 testų vidurkis) ms

#### Vector
| Failas | 1 strategija | 2 strategija (originali) | 3 strategija |
| :--- | ---- | ---- | ---- |
| stud1000 | 1 | 0 | 0 |
| stud10000 | 1 | 1 | 3 |
| stud100000 | 26 | 25 | 31 |
| stud1000000 | 380 | 282 | 370 |
| stud10000000 | 5580 | 3211 | 4376 |

#### List
| Failas | 1 strategija | 2 strategija (originali) | 3 strategija |
| :--- | ---- | ---- | ---- |
| stud1000 | 1 | 0 | 0 |
| stud10000 | 3 | 3 | 5 |
| stud100000 | 80 | 44 | 62 |
| stud1000000 | 803 | 452 | 618 |
| stud10000000 | 9186 | 5311 | 7511 |

#### Deque
| Failas | 1 strategija | 2 strategija (originali) | 3 strategija |
| :--- | ---- | ---- | ---- |
| stud1000 | 1 | 0 | 1 |
| stud10000 | 4 | 2 | 1 |
| stud100000 | 56 | 27 | 34 |
| stud1000000 | 554 | 330 | 335 |
| stud10000000 | 7495 | 4149 | 4166 |

## Release'ų istorija

- V.pradinė: pirma prelimenati programa, kuri skaičiuoja ranka įvestus mokinio duomeis ir išveda galutinius rezultatus.
- v0.1: nereikia iš anksto nustatyti duomenų kiekio, padarytas atsitiktinės generacijos funkcionalumas. Programa padaryta naudojant vektorius ir, atskirai, naudojant masyvus.
- v0.2: programa gali duomenis priimti iš failo.
- v0.3: programa paskirstyta per kelis failus, pridėtas išimčių valdymas.
- v0.4: programoje galima generuoti naujus failus, duomenys atspausdinami į 2 atskirus failus, atliekama laiko analizė.
- v1.0: atliktas programos testavimas su skirtingais konteineriais, naudotos skirtingos mokinių skirstymo strategijos, padarytos jų efektyvumo strategijos.

## Tyrimas

Buvo atliktas mokinių dalijimo į 2 konteinerius skirtingų strategijų testavimas, kuris padėjo paoptimizuoti greitį naudojant list ir deque, bet sparta naudojant vector sumažėjo. Visais atvejais 1 stratejija buvo pati lėčiausia ir taip pat ji prasčiausia programos naudojamos vietos atžvilgiu. 

## Kompiuterio paruošimas programai

Čia gidas Windows sistemoms.
- Atsisiųskite c++ kompiliatorių. Gidas čia: https://www.geeksforgeeks.org/installing-mingw-tools-for-c-c-and-changing-environment-variable/. 
- Atsisiųskite make. Gidas čia: https://linuxhint.com/install-use-make-windows/.

## Programos diegimas ir paleidimas

1. Atsisiųskite programos kodą iš repozitorijos.
2. Terminale pasiekite atsisiuntimo aplanką.
3. terminale parašykite "make" (pirmą kartą, kai leidžiate programą).
4. Paleiskite programą terminale įvesdami .\prog.exe (Windows) arba .\prog (Linux)