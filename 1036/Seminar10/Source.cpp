#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class ProdusAlimentar {
public:
	string nume = "";
	char descriere[100];
	char* continut;

	float pret;
	int* stocuri;
	int nrMagazine;
	int istoricVanzariLunaCurenta[31];
	int nrZile;

	ProdusAlimentar(string nume,
		const char* descriere, const char* continut,
		float pret, int* stocuri, int nrMagazine,
		int* istoric, int nrInregistrari) {

		if (nrInregistrari > 31 || nrInregistrari < 0)
			throw new exception("Istoric invalid !");
		if (strlen(descriere) > 99)
			throw new exception("Descriere invalida");
		if (pret < 0 || pret > 10000)
			throw new exception("Pret invalid");

		this->nume = nume;
		strcpy(this->descriere, descriere);
		this->continut = new char[strlen(continut) + 1];
		strcpy(this->continut, continut);

		this->pret = pret;
		this->nrMagazine = nrMagazine;
		this->stocuri = new int[nrMagazine];
		for (int i = 0; i < nrMagazine; i++) {
			this->stocuri[i] = stocuri[i];
		}

		this->nrZile = nrInregistrari;

		for (int i = 0; i < nrInregistrari; i++)
			this->istoricVanzariLunaCurenta[i] = istoric[i];
	}

	void salvareDateObiect(ofstream& fisier) {
		int nrCaractereNume = this->nume.size();
		//scriu numarul de caractere
		fisier.write((char*)&nrCaractereNume, sizeof(int));
		//scriu numele cu \0
		fisier.write(this->nume.c_str(), nrCaractereNume + 1);
		//scriu descrierea
		fisier.write(this->descriere, sizeof(this->descriere));
		//scriu continutul ca vector de 1000 de caractere
		char buffer[1000];
		strcpy(buffer, this->continut);
		fisier.write(buffer, sizeof(buffer));
		//scriu pretul
		fisier.write((char*)&this->pret, sizeof(float));
		//scriu numarul de magazine
		fisier.write((char*)&this->nrMagazine, sizeof(int));
		//scriu stocurile
		fisier.write((char*)this->stocuri, sizeof(int)*this->nrMagazine);
		//scriu numarul de zile
		fisier.write((char*)&this->nrZile, sizeof(int));
		//scriu istoricul - DOAR elementele folosite - > nrZile
		fisier.write((char*)this->istoricVanzariLunaCurenta,
			this->nrZile * sizeof(int));

	}
};

void operator<<(ostream& out, ProdusAlimentar& pa) {
	out << endl << "----------------";
	out << endl << "Denumire: " << pa.nume;
	out << endl << "Descriere: " << pa.descriere;
	out << endl << "Pret: " << pa.pret;
	out << endl << "Continut: " << pa.continut;
	out << endl << "Stocuri: ";

	for (int i = 0; i < pa.nrMagazine; i++)
		out << pa.stocuri[i] << " | ";

	out << endl << "Istoric vanzari: ";

	int nrElementeIstoric =
		sizeof(pa.istoricVanzariLunaCurenta) / 
		sizeof(pa.istoricVanzariLunaCurenta[0]);

	for (int i = 0; i < pa.nrZile; i++)
		out << pa.istoricVanzariLunaCurenta[i] << " | ";
}

int main() {

	int dateIstoric[] = { 10,20,30 };
	int dateStocuri[] = { 50,60,290,100 };

	//ProdusAlimentar *produse;
	//produse = new ProdusAlimentar[2];

	ProdusAlimentar* *produse;
	produse = new ProdusAlimentar*[2];

	produse[0] = new ProdusAlimentar("Biscuiti",
		"Biscuiti cu unt", "Faina, Unt, etc", 2.56,
		dateStocuri, 4, dateIstoric, 3);

	produse[1] = new ProdusAlimentar("Lapte",
		"Lapte", "Lapte de vaca", 9.50,
		dateStocuri, 4, dateIstoric, 3);

	int nrProduse = 2;

	for (int i = 0; i < nrProduse; i++) {
		cout << endl << *produse[i];
	}

	//salvare in fisier binar
	ofstream fisier("produse.bin", ios::out | ios::binary);
	//scriu numarul de produse
	fisier.write((char*)&nrProduse, sizeof(int));
	for (int i = 0; i < nrProduse; i++) {
		produse[i]->salvareDateObiect(fisier);
	}
	fisier.close();

	cout << endl << "Sfarsit";

}