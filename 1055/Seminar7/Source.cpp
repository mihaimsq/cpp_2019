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

	static int contor;
	const static int MAXIM_PRODUSE;

public:

	const int id;

	Produs(string denumire, float pret, int cantitate):id(Produs::contor) {
		this->denumire = denumire;
		this->pret = pret;
		this->cantitate = cantitate;
		Produs::contor += 1;
	}

	//destructorul
	~Produs() {
		if (this->inregistrariVanzari != NULL)
			delete[] this->inregistrariVanzari;
		Produs::contor -= 1;
	}

	//constructor copiere
	Produs(Produs& existent):id(Produs::contor) {
		Produs::contor += 1;
		this->pret = existent.pret;
		this->cantitate = existent.cantitate;
		this->denumire = existent.denumire;

		//NU ASA
		//this->inregistrariVanzari = existent.inregistrariVanzari;
		this->nrFacturi = existent.nrFacturi;
		this->inregistrariVanzari = new int[existent.nrFacturi];
		for (int i = 0; i < this->nrFacturi; i++)
			this->inregistrariVanzari[i] = existent.inregistrariVanzari[i];
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

		if (cantitate > Produs::MAXIM_PRODUSE)
			throw "Cantitatea depaseste maximul admis";

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

	Produs operator+(int valoare) {
		Produs rezultat = *this;
		rezultat.vanzare(valoare);
		return rezultat;
	}

	friend void operator<<(ostream& out, Produs p);
	friend void operator>>(istream& in, Produs& p);

};

int Produs::contor = 1;
const int Produs::MAXIM_PRODUSE = 100;

void operator<<(ostream& out, Produs p) {
	out << endl << " -------------------- ";
	out << endl << "Denumire: " << p.denumire;
	out << endl << "Pret: " << p.getPret();
	out << endl << "Stoc: " << p.getCantitate();
	if (p.nrFacturi != 0) {
		out << endl << "Istoric vanzari: ";
		for (int i = 0; i < p.nrFacturi; i++) {
			out << p.inregistrariVanzari[i] << " | ";
		}
	}
	else
		out << endl << "Nu are istoric vanzari";
}

void operator>>(istream& in, Produs& p) {
	cout << endl << "Noua denumire:";
	in >> p.denumire;
	cout << endl << "Noul pret:";
	in >> p.pret;
	cout << endl << "Noua cantitate:";
	in >> p.cantitate;

	cout << endl << "Numar facturi:";
	in >> p.nrFacturi;

	//evitam un memory leak
	if (p.inregistrariVanzari != NULL)
		delete[] p.inregistrariVanzari;

	p.inregistrariVanzari = new int[p.nrFacturi];
	for (int i = 0; i < p.nrFacturi; i++) {
		cout << endl << "Cantitate factura: ";
		in >> p.inregistrariVanzari[i];
	}
}

//Produs operator+(Produs p, int valoare) {
//	Produs rezultat = p;
//	rezultat.vanzare(valoare);
//	return rezultat;
//}


//va apela constructorul de copiere pentru a-l construi pe p
void oFunctie(Produs& p) {

}

//va apela constructorul de copiere pentru a returna rezultatul
Produs oAltaFunctie() {
	Produs produs1("Biscuiti", 2.7, 1000);
	produs1.vanzare(23);
	produs1.vanzare(10);
	return produs1;
}

int main() {

	//Produs produs1;	//nu mai avem constructor default
	Produs produs1("Biscuiti", 2.7, 1000);
	float valoareStoc = produs1.getValoareStoc();
	cout << endl << "Valoare stoc: " << valoareStoc;

	produs1.vanzare(23);
	produs1.vanzare(10);

	produs1.afisareInfoProdus();

	oFunctie(produs1);

	//apel constructor de copiere
	Produs copie = produs1;

	int vb1 = 10;
	vb1 = vb1 + 20;		//operator+(vb1,20)

	cout << endl << "Test operatori !";

	cout << produs1;	//void operator<<(ostream&,Produs)
	cin >> copie;		//void operator>>(istream&,Produs)

	cout << copie;

	//copie = copie + 10; //Produs operator+(Produs, int)
	//copie = 5 + copie; //Produs operator+(int, Produs)



}