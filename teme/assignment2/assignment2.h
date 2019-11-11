#include <exception>

#pragma once



class ExceptieAssignment2 : public std::exception {

};


/*
input
- un vector de numere intregi
- dimensiunea vectorului
- o valoare data
return 
- numarul de elemente din vector ce sunt mai mari sau egale cu valoarea data
*/

int numarElementeMaiMari(int* valori, int nrValori, int valoarePrag);

/*
Functia extrage dintr-un vector dat toate elementele ce sunt mai mari sau egale cu o valoare prag data

input
- un vector de numere intregi
- dimensiunea vectorului
- o valoare data
return
- un vector nou (creat in HEAP) ce contine toate elementele mai mari sau egale cu valoarea prag
- NULL daca in vectorul initial nu exista elemente mai mari sau egale
*/

int* filtrareElementeMaiMari(int* valori, int nrValori, int valoarePrag);


/*
Functia extrage dintr-un vector dat toate elementele ce sunt mai mari sau egale cu o valoare prag data

input
- un vector de numere intregi
- dimensiunea vectorului
- o valoare data
return
- un vector nou ce contine toate elementele mai mari sau egale cu valoarea prag; pointerul catre noul vector este primit in lista de argumente
- NULL daca in vectorul initial nu exista elemente mai mari sau egale
*/

void filtrareElementeMaiMari2(int* valori, int nrValori, int valoarePrag, int** valoriMaiMari);

/*
Functia extrage elementul de pe pozitia index 

input
- un vector de numere intregi
- dimensiunea vectorului
- indexul elementului (valoare pentru index trebuie sa fie validata) - daca valoarea pentru index nu este ok atunci se arunca o exceptie de tip
		ExceptieAssignment2 cu "throw new ExceptieAssignment2()"
return
- elementul de pe pozitia index
- exceptie daca indexul nu este valid
*/

int getElement(int* valori, int nrValori, int index);


/*
Functia extrage un subvector din vectorul primit - [index_start, index_final]

input
- un vector de numere intregi
- dimensiunea vectorului
- index start si index final 
	- daca valoarea pentru oricare index nu este ok atunci se arunca o exceptie de tip
		ExceptieAssignment2 cu "throw new ExceptieAssignment2()"
	- daca index start este egal cu index final atunci se returneaza un sub-vector ce contine elementul de pe pozitia index start
	- daca index start este mai mare decat index final atunci se arunca o exceptie de tip ExceptieAssignment2
return
- un vector nou
- dimensiunea vectorului nou este returnata prin referinta dimensiuneSubvector din lista de argumente
- exceptie daca indexul nu este valid
*/

int* slice(int* valori, int nrValori, int indexStart, int indexFinal, int& dimensiuneSubvector);