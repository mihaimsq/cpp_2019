#include <stdio.h>
#include <iostream>
using namespace std;

void main() {

	int numarNorocos = 6;


	//printf("\n Numarul norocos este %d", numarNorocos);
	//printf("\n Da-mi un numar nou:");
	//scanf("%d", &numarNorocos);
	//printf("\n Numarul norocos este %d", numarNorocos);
	

	//std::cout << "\n Numarul norocos este " << numarNorocos;
	//cout << std::endl <<"Da-mi un numar nou:";
	//cin >> numarNorocos;
	//std::cout << "\n Numarul norocos este " << numarNorocos;

	//vectori de valori
	//statici

	//1 definire
	int numereNorocoase[6];
	int nrElemente = 6;
	//2 initializare
	for (int i = 0; i < nrElemente; i++) {
		numereNorocoase[i] = 0;
	}
	//COMPLET GRESIT
	//nrElemente += 1;
	//numereNorocoase[nrElemente-1] = 55;
	
	//alternativa
	//int numereNorocoase2[7];

	   
	cout << endl << "Numerele sunt:";
	for (int i = 0; i < nrElemente; i++) {
		cout << numereNorocoase[i] << " , ";
	}

	//vectori dinamici
	//1. definire & alocare spatiu
	int nrNumereLoto = 6;
	int* numereLoto = new int[nrNumereLoto];

	//initializare 
	for (int i = 0; i < nrNumereLoto; i++) {
		numereLoto[i] = 0;
	}

	//afisare
	cout << endl << "Numere loto:";
	for (int i = 0; i < nrNumereLoto; i++) {
		cout << numereLoto[i] << " , ";
	}

	//adaugare element nou
	int * vectorNou = new int[nrNumereLoto + 1];
	//copiem valorile vechi
	for (int i = 0; i < nrNumereLoto; i++) {
		vectorNou[i] = numereLoto[i];
	}
	//initializare element nou
	vectorNou[nrNumereLoto] = 45;

	numereLoto = vectorNou;
	nrNumereLoto += 1;

	cout << endl << "Numere loto dupa adaugare:";
	for (int i = 0; i < nrNumereLoto; i++) {
		cout << numereLoto[i] << " , ";
	}



}