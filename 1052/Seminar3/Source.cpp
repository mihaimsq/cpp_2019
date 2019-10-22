#include <iostream>
using namespace std;

void afisareVector(int valori[], int n) {
	std::cout << std::endl << "Vectorul este: ";
	for (int i = 0; i < n; i++)
		std::cout << valori[i] << ", ";
 }

int main() {

	//vectori statici
	int preturiProduse[30];
	int nrProduse;

	cout << endl << "Numar produse: ";
	cin >> nrProduse;

	afisareVector(preturiProduse, nrProduse);



}