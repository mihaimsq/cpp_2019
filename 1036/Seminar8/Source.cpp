#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Produs {
public:
	string denumire = "";
	float pret  = 0;
	int stoc = 0;
	int* cantitatePerFactura = NULL;
	int nrFacturi = 0;

public:
	Produs(string denumire, float pret, int stoc) {
		this->denumire = denumire;
		this->stoc = stoc;
		this->pret = pret;
		this->cantitatePerFactura = NULL;
		this->nrFacturi = 0;
	}

	Produs() {
		//initializate mai sus
	}

	~Produs() {
		cout << endl << "Apel destructor !";
		if (this->cantitatePerFactura != NULL)
			delete[] this->cantitatePerFactura;
	}

	friend ostream& operator<<(ostream& out, Produs& p);
};

ostream& operator<<(ostream& out, Produs& p) {
	out << endl << " ---------------------- ";
	out << endl << "Nume produs: " << p.denumire;
	out << endl << "Pret produs: " << p.pret;
	out << endl << "Stoc produs: " << p.stoc;

	out << endl << "Istoric vanzari: ";
	if (p.cantitatePerFactura != NULL) {
		for (int i = 0; i < p.nrFacturi; i++) {
			out << p.cantitatePerFactura[i] << " | ";
		}
	}

	return out;

}


void oFunctie() {
	Produs produs("Laptop", 1200, 100);
}


int main() {
	Produs produs1("Laptop", 1200, 100);
	Produs produs2("Biscuiti", 2.5, 100);
	cout << produs1 << produs2;

	//test destructor
	oFunctie();

	Produs *p = new Produs("Test", 1, 1);
	delete p;

	//vectori de obiecte
	//Produs lista[5];	//are nevoie de constructor default
	Produs listaProduse[2] = { produs1, produs2 };
	int nrProduse = 2;

	//vector de pointeri de Produse
	Produs* lista1[5];
	Produs* *lista2;
	lista2 = new Produs*[5];

	//salvare date produse in fisierul text
	ofstream raport("Produse.txt");
	if (raport.is_open()) {
		for (int i = 0; i < nrProduse; i++) {
			raport << listaProduse[i];
		}
		raport.close();
	}
	else
		cout << endl << "***** Nu am drepturi de creare fisiere";


	//citire date Produse
	Produs dateIntrare[5];
	int nrProduseFisier = 0;

	ifstream fisierIntrare("DateInput.txt");
	if (fisierIntrare.is_open()) {
		//citesc numarul de produse
		fisierIntrare >> nrProduseFisier;
		for (int i = 0; i < nrProduseFisier; i++) {
			char buffer[1000];
			fisierIntrare.get();
			fisierIntrare.getline(buffer, 1000);
			dateIntrare[i].denumire = string(buffer);
			fisierIntrare >> dateIntrare[i].pret;
			fisierIntrare >> dateIntrare[i].stoc;
			fisierIntrare >> dateIntrare[i].nrFacturi;
			if (dateIntrare[i].nrFacturi != 0) {
				dateIntrare[i].cantitatePerFactura =
					new int[dateIntrare[i].nrFacturi];
				for (int j = 0; j < dateIntrare[i].nrFacturi; j++)
					fisierIntrare >> dateIntrare[i].cantitatePerFactura[j];
			}

		}
		fisierIntrare.close();
	}
	else
		cout << endl << "Probleme deschidere fisier";

	//afisare date citite din fisier
	cout << endl << "******************";
	for (int i = 0; i < nrProduseFisier; i++)
		cout << dateIntrare[i];
}