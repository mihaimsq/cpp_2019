#include <string>
#include <iostream>
using namespace std;

class Produs {
private:
	std::string denumire = "Fara denumire";
	float pret = 0;
	int cantitate = 0;

	int *inregistrariVanzari = NULL;
	int nrFacturi = 0;

public:

	Produs(string denumire, float pret, int cantitate) {
		this->denumire = denumire;
		this->pret = pret;
		this->cantitate = cantitate;
	}

	void afisareInfoProdus() {
		cout << endl << " -------------------- ";
		cout << endl << "Denumire: " << this->denumire;
		cout << endl << "Pret: " << this->pret;
		cout << endl << "Stoc: " << this->cantitate;
		if (this->nrFacturi != 0) {
			cout << endl << "Istoric vanzari: ";
			for (int i = 0; i < this->nrFacturi; i++) {
				cout << this->inregistrariVanzari[i] << " | ";
			}
		}
		else
			cout << endl << "Nu are istoric vanzari";

	}

	float getPret() {
		return this->pret;
	}
	float getCantitate() {
		return this->cantitate;
	}
	float getValoareStoc() {
		return this->cantitate * this->pret;
	}

	void setDiscount(float valoareDiscount) {
		if (valoareDiscount > 0.0 && valoareDiscount < 1) {
			this->pret -= this->pret*valoareDiscount;
		}
		else {
			throw "Valoare discount gresita";
		}
	}

	void vanzare(int cantitate) {

		if (cantitate <= 0 && cantitate > this->cantitate)
			throw "Nu se poate inregistra vanzarea";

		int* nou = new int[this->nrFacturi + 1];
		for (int i = 0; i < this->nrFacturi; i++) {
			nou[i] = this->inregistrariVanzari[i];
		}
		nou[this->nrFacturi] = cantitate;
		//evitam un memory leak
		delete[] this->inregistrariVanzari;
		this->inregistrariVanzari = nou;

		this->cantitate -= cantitate;
		this->nrFacturi += 1;
	}

};

int main() {

	//Produs produs1;	//nu mai avem constructor default
	Produs produs1("Biscuiti", 2.7, 1000);
	float valoareStoc = produs1.getValoareStoc();
	cout << endl << "Valoare stoc: " << valoareStoc;

	produs1.vanzare(23);
	produs1.vanzare(10);

	produs1.afisareInfoProdus();
}