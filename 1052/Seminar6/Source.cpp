#include <string>
#include <iostream>
using namespace std;



class Produs {
private:
	std::string denumire ="Nimic";
	float pret = 0;
	int stoc = 0;

	int *cantitatePerFactura = NULL;
	int nrFacturi = 0;
public:
	const int id = 0;
	const int testConstanta;

	static float DISCOUNT_MAXIM;

	//constructorul default/implicit/fara parametri
	Produs():testConstanta(0), nrFacturi(0) {
		cout << endl << "Apel constructor default";
	}

	Produs(int Id, string denumire, 
		float pret, int stocInitial):id(Id),testConstanta(0) {
		this->denumire = denumire;
		this->pret = pret;
		this->stoc = stocInitial;
		//this->id = id;	//nu mai merge - e constant
	}

	void afisare() {

		cout << endl << "-----------------------";
		cout << endl << this->id << " - " << this->denumire;
		cout << endl << "Pret: " << this->pret;
		cout << endl << "Stoc: " << this->stoc;

		if (this->cantitatePerFactura != NULL) {
			cout << endl << "Vanzari anterioare: ";
			for (int i = 0; i < this->nrFacturi; i++) {
				cout << this->cantitatePerFactura[i] << " | ";
			}
		}
		else
			cout << endl << "Nu exista date vanzari";
	}

	void setDiscount(float valoareDiscount) {
		if (valoareDiscount > 0
			&& valoareDiscount <= Produs::DISCOUNT_MAXIM) {
			this->pret -= this->pret * valoareDiscount;
		}
		else
			throw "Discount gresit";
	}

	void inregistrareFactura(int cantitate) {
		int* nou = new int[this->nrFacturi + 1];
		for (int i = 0; i < this->nrFacturi; i++) {
			nou[i] = this->cantitatePerFactura[i];
		}
		nou[this->nrFacturi] = cantitate;
		this->stoc -= cantitate;
		this->nrFacturi += 1;

		delete[] this->cantitatePerFactura;
		this->cantitatePerFactura = nou;
	}
};

float Produs::DISCOUNT_MAXIM = 0.5;

int main() {
	Produs produs1;
	Produs produs2(1, "Biscuiti", 2.3, 1000);

	produs2.setDiscount(0.1);
	produs2.inregistrareFactura(5);
	produs2.inregistrareFactura(10);

	produs1.afisare();
	produs2.afisare();



}