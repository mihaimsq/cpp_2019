#include <string>
#include <iostream>
using namespace std;

class CurierPostal {
public:
	std::string nume = "Anonim";
private:
	int varsta = 0;

	char companieCurierat[50];
	char* adresa = NULL;
public:
	int nrOrase = 0;
	string *puncteTraseu = NULL;

	//constructor
	//constructor default/implicit/fara parametri
	CurierPostal() {
		cout << endl << "Salut ! Eu sunt constructorul implicit !";
		strcpy(this->companieCurierat, "ACME Inc");
		this->adresa = new char[100];
		strcpy(this->adresa, "Bucuresti");
	}

	int getVarsta() {
		return this->varsta;
	}

	void setVarsta(int valoareNoua) {
		if (valoareNoua >= 18 && valoareNoua <= 80)
			this->varsta = valoareNoua;
		else
			throw "Varsta e gresita";
	}

	void print() {
		cout << endl << "Date curier:";
		cout << endl << this->nume << " cu varsta " << this->varsta;
		
		if (this->adresa != NULL) {
			cout << endl << this->companieCurierat << " cu adresa "
				<< this->adresa;
		}
		else
		{
			cout << endl << this->companieCurierat;
		}
		cout << endl << "Traseu: ";
		for (int i = 0; i < this->nrOrase; i++) {
			cout << this->puncteTraseu[i] << ", ";
		}
	}
};



int main() {

	//instantiere clasa
	//definire obiect
	CurierPostal curier1;
	CurierPostal curier2;

	curier1.setVarsta(23);
	curier2.setVarsta(22);
	//primim exceptie
	//curier1.setVarsta(-23);

	cout << endl << "Numele curierului este " << curier1.nume;
	cout << endl << "Varsta curierului este " 
		<< curier1.getVarsta();
	cout << endl << "Varsta curierului este "
		<< curier2.getVarsta();

	curier1.print();

}