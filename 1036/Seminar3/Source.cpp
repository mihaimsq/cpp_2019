#include <iostream>
using namespace std;

void afisareVector(int* valori, int n) {
	cout << endl << "Valorile sunt: ";
	for (int i = 0; i < n; i++)
	{
		cout << valori[i] << ", ";
	}
}

void initializareVector(
	int* vector, int n, int valoare) {

	for (int i = 0; i < n; i++) {
		vector[i] = valoare;
	}

}

int* creareSiInitializareVector(int * adresaNrElemente) {
	int vectorNou[40];
	int numarElemente;
	int valoareInitiala;

	std::cout << std::endl << "Numar produse: ";
	std::cin >> numarElemente;
	//copiez valoare si in variabila din main
	*adresaNrElemente = numarElemente;

	std::cout << std::endl << "Valoare initiala: ";
	std::cin >> valoareInitiala;

	initializareVector(
		vectorNou, numarElemente, 0);

	return vectorNou;
}

int main() {

	//citim elementele unui vector de la consola
	int preturiProduse[40];
	int numarProduse;

	//varianta fara functie

	//std::cout << std::endl << "Numar produse: ";
	//std::cin >> numarProduse;

	//initializareVector(
	//	preturiProduse, numarProduse, 0);

	//varianta cu functie
	//preturiProduse = creareSiInitializareVector();

	int nrElementeVectorNou;
	int * preturi = creareSiInitializareVector(
		&nrElementeVectorNou);

	afisareVector(preturi, nrElementeVectorNou);

}