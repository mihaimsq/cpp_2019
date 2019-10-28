#include <iostream>
#include <string>
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

//NU MERGE
//Vectorul este creat pe stiva functiei si il vom pierde
//int* creareSiInitializareVector(int* N) {
//	int vectorNou[30];
//	int numarElemente;
//	int valoareInitiala;
//
//	std::cout << std::endl << "Numarul de elemente este:";
//	std::cin >> numarElemente;
//	*N = numarElemente;
//
//	std::cout << std::endl << "Valoare initiala:";
//	std::cin >> valoareInitiala;
//
//	initializareVector(
//		vectorNou, numarElemente, valoareInitiala);
//
//	return vectorNou;
//}


int* creareSiInitializareVector(int* N) {
	int* vectorNou = NULL;
	int numarElemente;
	int valoareInitiala;

	std::cout << std::endl << "Numarul de elemente este:";
	std::cin >> numarElemente;
	*N = numarElemente;
	vectorNou = new int[numarElemente];

	std::cout << std::endl << "Valoare initiala:";
	std::cin >> valoareInitiala;

	initializareVector(
		vectorNou, numarElemente, valoareInitiala);

	return vectorNou;
}

struct OfertaMagazin {

	int* preturiProduse;
	int numarProduse;
	string *numeProduse;
	//char* *numeProduse;


	char numeMagazin[50];
	char* adresa;
	string denumireOferta;
};

void main() {

	int listaPreturi[30];
	int numarProduse;

	//std::cout << std::endl << "Numarul de produse este:";
	//std::cin >> numarProduse;

	//initializareVector(listaPreturi, numarProduse, 0);
	//afisareVector(listaPreturi, numarProduse);

	//NU O SA MEARGA
	//listaPreturi = creareSiInitializareVector();

	//int nrElemente = 0;
	//int *vectorNou = creareSiInitializareVector(&nrElemente);
	//afisareVector(vectorNou, nrElemente);

	//initializare articol oferta magazin
	OfertaMagazin oferta;

	//initializare preturi
	oferta.preturiProduse = creareSiInitializareVector(&oferta.numarProduse);
	afisareVector(oferta.preturiProduse, oferta.numarProduse);
	//initializare nume produse
	oferta.numeProduse = new string[oferta.numarProduse];
	cout << endl << "Numele produselor: ";
	for (int i = 0; i < oferta.numarProduse; i++) {
		cout << endl << "Denumire produs " << i + 1 << ":";
		cin >> oferta.numeProduse[i];
	}


}