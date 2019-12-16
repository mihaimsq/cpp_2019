#include <iostream>
#include <string>
using namespace std;

class Produs {
protected:
	char* denumire = NULL;
	float pret = 0;
public:
	Produs(const char* Denumire, float Pret) {
		this->denumire = 
			new char[strlen(Denumire) + 1];
		strcpy(this->denumire, Denumire);
		this->pret = Pret;
	}
	~Produs() {
		delete[] this->denumire;
	}

	Produs(const Produs& p) {
		this->pret = p.pret;
		this->denumire =
			new char[strlen(p.denumire) + 1];
		strcpy(this->denumire, p.denumire);
	}

	void print() {
		cout << endl << "Produsul "
			<< this->denumire << " are pretul "
			<< this->pret;
	}
};

class ProdusAlimentar: public Produs {
	char dataFabricatie[11];	//zz/ll/aaaa
	int termenZileExpirare;

public:
	ProdusAlimentar():Produs("Nimic",0) {
		this->dataFabricatie[0] = '\0';
		this->termenZileExpirare = 0;
	}
	ProdusAlimentar(const char* denumire,
		float pret, int termenExpirare)
		:Produs(denumire, pret) {

		//NU ASA
		//genereaza memory leak si e redundant
		/*this->pret = pret;
		this->denumire =
			new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);*/
		this->termenZileExpirare = termenExpirare;
		strcpy(this->dataFabricatie, "12/12/2019");
	}

	~ProdusAlimentar(){
		//delete[] denumire;
	}

	//supradefinire
	void print(){
		//cout << endl << "Produsul "
		//	<< this->denumire << " are pretul "
		//	<< this->pret;

		this->Produs::print();

		cout << endl << "Data productiei: "
			<< this->dataFabricatie;
		cout << endl << "Expira in " <<
			this->termenZileExpirare;
	}
};

class ProdusAlimentarCuDiscount 
	: public ProdusAlimentar {
	float discount;
};

class Test {

};

int main() {
	Produs p1("Biscuiti", 2.4);
	Produs p2("Laptop", 1200);
	p1.print();
	//p2.pret = 0;

	ProdusAlimentar pa1("Salata",7.8,3);
	pa1.print();
	//pa1.print();
	Test t;

	ProdusAlimentarCuDiscount pad;
}