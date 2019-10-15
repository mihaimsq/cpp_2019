#include <stdio.h>
#include <iostream>
using namespace std;

void main() {

	int numarNorocos;
	numarNorocos = 0;
	//printf("\n Numarul norocos este %d",
	//	numarNorocos);
	//printf("\n Noul numar este:");
	//scanf("%d", &numarNorocos);
	//printf("\n Numarul norocos este %d",
	//	numarNorocos);

	//std::cout << endl << "Numarul norocos este " 
	//	<< numarNorocos;
	//cout << "\n Noul numar este:";
	//cin >> numarNorocos;
	//std::cout << endl << "Numarul norocos este "
	//	<< numarNorocos;

	//vectori numere
	//versiune statica
	int numere6din49[6];

	int ceva = 100;
	cout << endl << "O valoare :" << ceva;

	//initializare
	for (int i = 0; i < 6; i++)
		numere6din49[i] = 0;

	cout << endl << "Cele 6 norocoase sunt: ";
	for (int i = 0; i < 6; i++)
		cout << endl << "Valoarea " << i+1 << ":" 
		<< numere6din49[i];

	//adaugare element nou
	//NU MERGE
	//numere6din49[6] = 0;
	//cout << endl << "Cele 7 norocoase sunt: ";
	//for (int i = 0; i < 7; i++)
	//	cout << endl << "Valoarea " << i + 1 << ":"
	//	<< numere6din49[i];

	//varianta dinamica
	int* numereNorocoase;
	int nrElemente;

	//construim un vector cu 7 elemente
	nrElemente = 7;
	//alocare spatiu
	numereNorocoase = new int[nrElemente];
	//initializare elemente
	for (int i = 0; i < nrElemente; i++)
		numereNorocoase[i] = i+1;


	cout << endl << "Elemente vector dinamic: ";
	for (int i = 0; i < nrElemente; i++) {
		cout << numereNorocoase[i] << ", ";
	}

	//redimensionare
	int* nou  = new int[nrElemente + 3];
	//copiere elemente existente
	for (int i = 0; i < nrElemente; i++)
		nou[i] = numereNorocoase[i];

	//stim ca nu vectorul vechi nu este dezalocat
	numereNorocoase = nou;


}