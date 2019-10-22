#include <iostream>
using namespace std;

void afisareVector(int vector[], int n) {
	cout << endl << "Vectorul este: ";
	for (int i = 0; i < n; i++) {
		cout << vector[i] << ", ";
	}
}

void initializareVector(
	int* vector, int n, int valoareInitiala) {
	for (int i = 0; i < n; i++)
		vector[i] = valoareInitiala;
}

int* creareSiInitializareVector(int* N) {
	int vectorNou[30];
	int numarElemente;
	int valoareInitiala;

	std::cout << std::endl << "Numarul de elemente este:";
	std::cin >> numarElemente;
	*N = numarElemente;

	std::cout << std::endl << "Valoare initiala:";
	std::cin >> valoareInitiala;

	initializareVector(
		vectorNou, numarElemente, valoareInitiala);
	
	return vectorNou;
}

void main() {

	int listaPreturi[30];
	int numarProduse;

	//std::cout << std::endl << "Numarul de produse este:";
	//std::cin >> numarProduse;

	//initializareVector(listaPreturi, numarProduse, 0);
	//afisareVector(listaPreturi, numarProduse);

	//NU O SA MEARGA
	//listaPreturi = creareSiInitializareVector();

	int nrElemente = 0;
	int *vectorNou = creareSiInitializareVector(&nrElemente);
	afisareVector(vectorNou, nrElemente);

}