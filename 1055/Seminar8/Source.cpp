#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Produs {
	string denumire= "";
	float pret = 0;
	int cantitate = 0;

	int* istoricVanzari = NULL;
	int nrFacturi = 0;

public:
	Produs(string denumire, float pret, int stoc)
		:cantitate(stoc), pret(pret) {
		if (denumire.length() >= 3)
			this->denumire = denumire;
		else
			throw "Denumire prea scurta !";

		this->istoricVanzari = NULL;
		this->nrFacturi = 0;
	}

	friend ostream& operator<<(ostream& out, Produs& p);
};

ostream& operator<<(ostream& out, Produs& p) {
	out << endl << "-----------------------";
	out << endl << "Denumire produs: " << p.denumire;
	out << endl << "Pret produs: " << p.pret;
	out << endl << "Cantitate produs: " << p.cantitate;

	if (p.nrFacturi != 0) {
		out << endl << "Istoric vanzari:";
		for (int i = 0; i < p.nrFacturi; i++) {
			out << p.istoricVanzari[i] << " | ";
		}
	}
	return out;
}

int main() {
	Produs produs1("Laptop", 1200, 100);
	Produs produs2("Biscuiti", 2.3, 100);
	cout << produs1 << produs2;
	//cout << produs2;

	//scriere in fisier text
	ofstream raport("raport.txt");
	raport << produs1;
	raport << produs2;

	raport.close();

	//citire din fisier text
	ifstream dateFisier("raport.txt");
	if (dateFisier.is_open()) {
		//citire cu >> - atentie, se opreste pe space
		string linieFisier;
		while (!dateFisier.eof()) {
			dateFisier >> linieFisier;
			cout << endl << "Continut fisier " << linieFisier;
		}
		dateFisier.close();
	}
	else
		cout << endl << "********* Eroare deschidere fisier";


	//citire din fisier text + extragere date
	ifstream dateFisier2("raport.txt");
	if (dateFisier2.is_open()) {
		//citire cu getline
		string linieFisier;
		while (!dateFisier2.eof()) {
			char buffer[100];
			dateFisier2.getline(buffer, 100);
			linieFisier = string(buffer);
			cout << endl << "Continut fisier " << linieFisier;

			//extragem denumirea
			if (linieFisier.find("Denumire") != -1) {
				//am gasit linia cu denumirea produsului
				int indexReper = linieFisier.find(":");
				int indexDenumire = indexReper + 2;
				int nrCaractere = linieFisier.length() - indexDenumire;
				string denumire = linieFisier.substr(
					indexDenumire, nrCaractere);
				cout << endl << "Denumire: " << denumire;
			}

			//extragem pretul
			if (linieFisier.find("Pret") != -1) {
				//am gasit linia cu denumirea produsului
				int indexReper = linieFisier.find(":");
				int indexDenumire = indexReper + 2;
				int nrCaractere = linieFisier.length() - indexDenumire;
				string pret = linieFisier.substr(
					indexDenumire, nrCaractere);
				float pretProdus = stof(pret);
				cout << endl << "Pret: " << pretProdus;
			}

		}
		dateFisier2.close();
	}
	else
		cout << endl << "********* Eroare deschidere fisier";

	cout << endl << "Sfarsit exemplu";
}