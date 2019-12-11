#include <string>
#include <iostream>
using namespace std;

class Produs {
public:
	char* denumire;
protected:
	float pret;
public:
	Produs(const char* Denumire, float Pret) {
		this->denumire = new char[strlen(Denumire) + 1];
		strcpy(this->denumire, Denumire);
		this->pret = Pret;
	}

	//Produs(){

	//}
	~Produs() {
		delete[] this->denumire;
	}
	Produs(const Produs& prod) {
		this->denumire = new char[strlen(prod.denumire) + 1];
		strcpy(this->denumire, prod.denumire);
		this->pret = prod.pret;
	}
	void afisare() {
		cout << endl << "Produsul " << this->denumire << " are pretul "
			<< this->pret;
	}

	//discount de la 1% la 99%
	void aplicaDiscount(int procentDiscount) {
		this->pret *= 1 - (procentDiscount / 100);
	}

	friend void operator<<(ostream& out, Produs p);
};

void operator<<(ostream& out, Produs p) {
	out << endl << "Produsul " << p.denumire << " are pretul "
		<< p.pret;
}

class ProdusAlimentar : public Produs {
	int termenExpirareInZile;
	char dataProductie[11];	//pentru a stoca zz/ll/aaaa

public:
	ProdusAlimentar():Produs("Nimic",0) {
		this->termenExpirareInZile = 0;
		strcpy(dataProductie, "10/12/2019");
	}
	ProdusAlimentar(const char* denumire, float pret,
		int termenExpirare):Produs(denumire,pret) {
		//this->denumire = new char[strlen(denumire) + 1];
		//strcpy(this->denumire, denumire);
		//this->pret = pret;
		this->termenExpirareInZile = termenExpirare;
	}
	~ProdusAlimentar() {

	}

	//supradefinire metoda din baza
	void afisare() {
		//cout << endl << "Produsul " << this->denumire << " are pretul "
		//	<< this->pret;
		this->Produs::afisare();
		cout << endl << "Expira in " << this->termenExpirareInZile;
	}

	//supraincarcare
	void aplicaDiscount(int procentDiscount, bool cuVanzareRapida) {
		if (cuVanzareRapida && this->termenExpirareInZile < 2)
			this->pret *= 0.5;
		else
			this->Produs::aplicaDiscount(procentDiscount);
	}

	friend void operator<<(ostream& out, ProdusAlimentar pa);
};

void operator<<(ostream& out, ProdusAlimentar pa) {
	out << (Produs)pa;
	out << " si expira in " << pa.termenExpirareInZile << " zile";
}

class Test {

};

class ProdusAlimentarVegan : public ProdusAlimentar {
	bool nuContineProduseDeOrigineAnimala;
};

int main() {
	Produs prod1("Biscuiti", 23.6);
	prod1.afisare();
	cout << endl << prod1.denumire;
	Test t;
	ProdusAlimentar pa1;
	ProdusAlimentar pa2("Lapte", 7.5, 10);
	//pa2.afisare();
	cout << pa2;

	ProdusAlimentarVegan pag;
}