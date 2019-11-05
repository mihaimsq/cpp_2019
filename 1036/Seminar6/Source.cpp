
#include <string>
#include <iostream>
using namespace std;

class Produs {

private:
	std::string denumire = "";
	float pret = 0;
	int stoc = 0;

	int* cantitatePerFactura = NULL;
	int nrFacturi = 0;

public:
	const int cod;

private:
	//numarul maxim de produse ce pot fi vandute unui client
	static int NR_MAXIM_PRODUSE;
	static int nrProduse;

public:
	Produs():cod(nrProduse+1) {
		nrProduse += 1;
		this->denumire = "Necunoscut";
	}

	Produs(string nume, 
		float pret, int stocInitial):cod(++nrProduse) {
		this->denumire = nume;
		this->pret = pret;
		this->stoc = stocInitial;
	}

	void afisare() {
		cout << endl << "----------------";
		cout << endl << this->cod << "-" << this->denumire
			<< " cu pret " << this->pret;
		cout << endl << "Stoc: " << this->stoc;

		if (nrFacturi > 0) {
			cout << endl << "Istoric vanzari:";
			for (int i = 0; i < this->nrFacturi; i++)
				cout << this->cantitatePerFactura[i] 
				<< " | ";
		}
		else
		{
			cout << endl << "Nu are istoric vanzari";
		}
	}

	float getPret() {
		return this->pret;
	}

	int getStoc() {
		return this->stoc;
	}

	void setDiscount(float valoareDiscount) {
		this->pret -= this->pret*valoareDiscount;
	}

	~Produs() {
		if (this->cantitatePerFactura != NULL)
			delete[] this->cantitatePerFactura;
	}

	void inregistrareFactura(int cantitateVanduta) {
		if (cantitateVanduta > Produs::NR_MAXIM_PRODUSE)
			throw "Cantitate ce depaseste maxim";
		if (cantitateVanduta > this->stoc)
			throw "Nu exista stoc disponibil";

		int *nou = new int[this->nrFacturi + 1];
		for (int i = 0; i < this->nrFacturi; i++)
			nou[i] = this->cantitatePerFactura[i];

		nou[this->nrFacturi] = cantitateVanduta;
		this->nrFacturi += 1;

		this->stoc -= cantitateVanduta;

		//evitam memory leak pe vectorul vechi
		delete[] this->cantitatePerFactura;

		this->cantitatePerFactura = nou;
	}

};

int Produs::nrProduse = 0;
int Produs::NR_MAXIM_PRODUSE = 10;


int main() {
	Produs produs1;
	Produs produs2("Biscuiti", 2.3, 1000);

	//cout << endl <<
	//	"Codul pentru produsul 1 este " << produs1.cod;

	produs2.inregistrareFactura(4);
	produs2.inregistrareFactura(3);

	produs1.afisare();
	produs2.afisare();

	float valoareStoc = produs2.getPret() * produs2.getStoc();

	cout << endl << "Sfarsit exemplu";
}