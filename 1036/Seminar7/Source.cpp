
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
	Produs() :cod(nrProduse + 1) {
		nrProduse += 1;
		this->denumire = "Necunoscut";
	}

	Produs(string nume,
		float pret, int stocInitial) :cod(++nrProduse) {
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

	//int*getCantitateFactura() {
	//	return this->cantitatePerFactura;
	//}

	int getNrFacturi() {
		return this->nrFacturi;
	}

	int getCantitateFactura(int index) {
		return this->cantitatePerFactura[index];
	}

	//constructor copiere
	Produs(const Produs& existent):cod(existent.cod) {
		this->denumire = existent.denumire;
		this->pret = existent.pret;
		this->stoc = existent.stoc;

		//NU ASA
		//this->cantitatePerFactura = existent.cantitatePerFactura;

		if (existent.cantitatePerFactura != NULL) {
			this->cantitatePerFactura =
				new int[existent.nrFacturi];
			for (int i = 0; i < existent.nrFacturi; i++)
				this->cantitatePerFactura[i] =
				existent.cantitatePerFactura[i];
			this->nrFacturi = existent.nrFacturi;
		}
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


	//Produs operator+(Produs p, int vb) {
	//	Produs copie = *this;
	//	copie.inregistrareFactura(vb);
	//	return copie;
	//}

	Produs operator=(Produs existent) {
		this->denumire = existent.denumire;
		this->pret = existent.pret;
		this->stoc = existent.stoc;

		//NU ASA
		//this->cantitatePerFactura = existent.cantitatePerFactura;

		if (existent.cantitatePerFactura != NULL) {

			if (this->cantitatePerFactura != NULL)
				delete[] this->cantitatePerFactura;

			this->cantitatePerFactura =
				new int[existent.nrFacturi];
			for (int i = 0; i < existent.nrFacturi; i++)
				this->cantitatePerFactura[i] =
				existent.cantitatePerFactura[i];
			this->nrFacturi = existent.nrFacturi;
		}

		return existent;
	}

	friend void operator<<(
		ostream& consola, Produs& p);
	friend void operator>>(istream& in, Produs& p);



};

int Produs::nrProduse = 0;
int Produs::NR_MAXIM_PRODUSE = 10;

void operator<<(ostream& consola, Produs& p) {
	consola << endl << "----------------";
	consola << endl << p.cod << "-" << p.denumire
		<< " cu pret " << p.pret;
	consola << endl << "Stoc: " << p.stoc;

	if (p.nrFacturi > 0) {
		consola << endl << "Istoric vanzari:";
		for (int i = 0; i < p.getNrFacturi(); i++)
			consola << p.getCantitateFactura(i)
			<< " | ";
	}
	else
	{
		consola << endl << "Nu are istoric vanzari";
	}
}

void operator>>(istream& in, Produs& p) {
	cout << endl << "Noul stoc este";
	in >> p.stoc;
	cout << endl << "Noua denumire este:";
	in >> p.denumire;
	cout << endl << "Noul pret este";
	in >> p.pret;

	cout << endl << "Numarul de facturi este:";
	in >> p.nrFacturi;

	if (p.cantitatePerFactura != NULL)
		delete[] p.cantitatePerFactura;

	p.cantitatePerFactura = new int[p.nrFacturi];
	for (int i = 0; i < p.nrFacturi; i++) {
		cout << endl << "cantitate:";
		in >> p.cantitatePerFactura[i];
	}

}

Produs operator+(Produs p, int vb) {
	Produs copie = p;
	copie.inregistrareFactura(vb);
	return copie;
}

Produs operator+(int nr, Produs p) {
	return p + nr;
}

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


	//apel constructor de copiere
	Produs copie = produs2;
	//copie.afisare();

	cout << copie;		//operator<<(cout,copie)
	cin >> copie;
	cout << copie;

	copie = copie + 10;		//adaugam o factura noua cu 10 produse
	copie = produs1 = produs2;
	copie = 10 + copie;


	cout << endl << "Sfarsit exemplu";
}