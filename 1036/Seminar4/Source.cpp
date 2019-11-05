#include <iostream>
#include <string>

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

//varianta gresita
//NU RETURNAM ADRESE DE VECTORI STATICI - sunt pe stiva functiei\

//int* creareSiInitializareVector(int * adresaNrElemente) {
//	int vectorNou[40];
//	int numarElemente;
//	int valoareInitiala;
//
//	std::cout << std::endl << "Numar produse: ";
//	std::cin >> numarElemente;
//	//copiez valoare si in variabila din main
//	*adresaNrElemente = numarElemente;
//
//	std::cout << std::endl << "Valoare initiala: ";
//	std::cin >> valoareInitiala;
//
//	initializareVector(
//		vectorNou, numarElemente, 0);
//
//	return vectorNou;
//}

int* creareSiInitializareVector(int& adresaNrElemente) {
	int* vectorNou = NULL;
	int numarElemente;
	int valoareInitiala;

	std::cout << std::endl << "Numar produse: ";
	std::cin >> numarElemente;
	//copiez valoare si in variabila din main
	adresaNrElemente = numarElemente;
	vectorNou = new int[numarElemente];

	std::cout << std::endl << "Valoare initiala: ";
	std::cin >> valoareInitiala;

	initializareVector(
		vectorNou, numarElemente, valoareInitiala);

	return vectorNou;
}




//definire clasa
class OfertaMagazin {
public:
	int* preturiProduse;
	int nrProduse;
	string *denumireProduse;
	
	char numeMagazin[50];
	char* adresaMagazin;
	string denumireOferta;

};

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
	//pentru varianta cu *
	//int * preturi = creareSiInitializareVector(
	//	&nrElementeVectorNou);

	int * preturi = creareSiInitializareVector(
		nrElementeVectorNou);


	afisareVector(preturi, nrElementeVectorNou);

	//test clasa
	OfertaMagazin ofertaEmag;
	strcpy(ofertaEmag.numeMagazin, "emag");

	std::cout << endl << "Adresa magazin: ";
	char buffer[1000];
	cin >> buffer;
	ofertaEmag.adresaMagazin = new char[strlen(buffer) + 1];
	strcpy(ofertaEmag.adresaMagazin, buffer);

	std::cout << endl << "Denumire oferta: ";
	cin >> ofertaEmag.denumireOferta;

}