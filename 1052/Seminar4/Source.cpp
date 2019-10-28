#include <iostream>
using namespace std;

void afisareVector(int vector[], int n) {
	cout << endl << "Valorile sunt: ";
	for (int i = 0; i < n; i++) {
		cout << vector[i] << ", ";
	}
}

void initializareVector(int* vector, int n, int valoareInitiala) {
	for (int i = 0; i < n; i++)
		vector[i] = valoareInitiala;
}

int* creareSiInitializareVector(int* adresaVariabilaDinMain) {
	//int preturiProduse[50];
	int* preturiProduse;
	int nrProduse;
	int valoareInitiala;

	cout << endl << "Numar produse: ";
	cin >> nrProduse;

	preturiProduse = new int[nrProduse];

	*adresaVariabilaDinMain = nrProduse;

	cout << endl << "Valoare initiala: ";
	cin >> valoareInitiala;

	initializareVector(preturiProduse, nrProduse, valoareInitiala);

	return preturiProduse;
}

void schimbaValoareVariabila(int* vb) {
	*vb = 100;
}

void schimbaValoareVariabila2(int& vb) {
	vb = 100;
}

int main() {

	int preturiProduse[50];
	int nrProduse;

	//cout << endl << "Numar produse: ";
	//cin >> nrProduse;
	//initializareVector(preturiProduse, nrProduse, 0);

	int* vectorNou;
	//preturiProduse = creareSiInitializareVector();
	vectorNou = creareSiInitializareVector(&nrProduse);

	afisareVector(vectorNou, nrProduse);

}