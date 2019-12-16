#include <iostream>
#include <string>
using namespace std;

class Produs {
protected:
	char* descriere = NULL;
	float pret = 0;
public:
	void setDescriere(const char* descriere) {
		if (this->descriere != NULL)
			delete[] this->descriere;
		this->descriere = new char[strlen(descriere) + 1];
		strcpy(this->descriere, descriere);
	}

	//Produs() {
	//	cout << endl << "Ctor default Produs";
	//}

	Produs(const char* Descriere, float Pret) {
		this->setDescriere(Descriere);
		this->pret = Pret;
	}

	~Produs() {
		delete[] this->descriere;
	}

	Produs(Produs& p) {
		this->setDescriere(p.descriere);
		this->pret = p.pret;
	}

	void print() {
		cout << endl << "Produsul " << this->descriere
			<< " are pretul " << this->pret;
	}
};

class ProdusAlimentar: public Produs {
	int termenValabilitateInZile;
	char dataProductie[11];	// zz/ll/aaaa
public:
	ProdusAlimentar():Produs("",0) {
		cout << endl << "Apel ctor default ProdusAlimentar";
	}
	ProdusAlimentar(const char* descriere, float pret,
		int termenValabilitate):Produs(descriere,pret) {
		this->termenValabilitateInZile = termenValabilitate;
		strcpy(this->dataProductie, "13/12/2019");

		//this->pret = 0;
	}
};

class Test {

};


int main(int argc, char* args[]) {

	cout << endl << args[1];
	//Produs p1("Biscuiti", 2.5);
	//Produs p2("Laptop", 1200);

	//p1.print();
	//p2.print();

	//Test t;
	ProdusAlimentar pa1;
	pa1.print();
}