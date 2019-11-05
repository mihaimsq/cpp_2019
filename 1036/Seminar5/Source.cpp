#include <string>
#include <iostream>

using namespace std;

class CurierPostal {

	string nume;
	int varsta;

	char nrInmatriculare[11];
	char *firmaCurierat;

	char* *puncteTraseu;
	int nrOrase;

public:

	//constructor implicit
	//constructor default
	//constructor fara parametri
	CurierPostal() {
		cout << endl << "Apel constructor default";
		this->nume = "Necunoscut";
		this->varsta = 0;
		strcpy(this->nrInmatriculare, "B-00-AAA");
		this->firmaCurierat = new char[100];
		strcpy(this->firmaCurierat, "FanCourier");

		this->nrOrase = 0;
		this->puncteTraseu = NULL;

	}
	//constructor cu parametri
	CurierPostal(string nume, int varsta, 
		const char* nrInmatriculare, const char* firma) {
		cout << endl << "Apel constructor cu parametri";

		this->nume = nume;
		this->varsta = varsta;
		strcpy(this->nrInmatriculare, nrInmatriculare);
		this->firmaCurierat = new char[strlen(firma) + 1];
		strcpy(this->firmaCurierat, firma);

		//NU UITATI DE CELELALTE ATRIBUTE
		this->nrOrase = 0;
		this->puncteTraseu = NULL;

	}

	void afisare() {
		cout << endl << "Date sofer: " <<
			this->nume << " cu varsta " << this->varsta;
		cout << endl << "Conduce furgoneta cu numarul "
			<< this->nrInmatriculare << " de la firma "
			<< this->firmaCurierat;
		cout << endl << "Traseu: ";
		for (int i = 0; i < this->nrOrase; i++) {
			cout << this->puncteTraseu[i] << ", ";
		}
	}
};

int main() {

	//instantiere clasa =  creare obiect
	CurierPostal curier1;
	CurierPostal curier2(
		"Gigel", 23, "B-01-FAN", "Fan Courier");



	curier1.afisare();
	curier2.afisare();

	//CurierPostal *adresaObiectCurier;
	//CurierPostal *curieri;

}
