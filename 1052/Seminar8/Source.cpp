#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Produs {
	string denumire = "";
	char producator[100];
	float pret = 0;
	int cantitate = 0;

	int* cantitateVanduta = NULL;
	int nrFacturi = 0;

public:
	Produs(string denumire, const char* producator, 
		float pret, int cantitate):pret(pret) {
		if (cantitate <= 0)
			throw "Cantitate gresita";
		if (denumire.length() <= 2)
			throw "Denumire gresita";
		if (strlen(producator) <= 3)
			throw "Denumire producator gresita";

		this->pret = pret;
		this->cantitate = cantitate;
		this->denumire = denumire;
		strcpy(this->producator, producator);

		this->cantitateVanduta = NULL;
		this->nrFacturi = 0;
	}

	friend ostream& operator<<(ostream& out, Produs& p);
	friend istream& operator>>(istream& in, Produs& p);
};

ostream& operator<<(ostream& out, Produs& p) {
	out << endl << "--------------------------";
	out << endl << "Denumire produs: " << p.denumire;
	out << endl << "Pret produs: " << p.pret;
	out << endl << "Cantitate produs: " << p.cantitate;
	out << endl << "Producator produs: " << p.producator;

	if (p.nrFacturi != 0) {
		out << endl << "Istoric vanzari: ";
		for (int i = 0; i < p.nrFacturi; i++)
			out << p.cantitateVanduta[i] << " | ";
	}
	return out;
}

istream& operator>>(istream& in, Produs& p) {
	cout << endl << "Noul nume: ";
	//in >> p.denumire; //nu merge cu space
	char buffer[1000];
	in.getline(buffer, 1000);
	p.denumire = string(buffer);
	cout << endl << "Noul pret: ";
	in >> p.pret;
	cout << endl << "Noua cantitate: ";
	in >> p.cantitate;
	cout << endl << "Noul producator: ";
	in >> p.producator;

	cout << endl << "Numar facturi de introdus:";
	in >> p.nrFacturi;

	if (p.cantitateVanduta != NULL)
		delete[] p.cantitateVanduta;
	p.cantitateVanduta = new int[p.nrFacturi];

	for (int i = 0; i < p.nrFacturi; i++) {
		cout << endl << "Cantitate factura " << i + 1 << ":";
		in >> p.cantitateVanduta[i];
	}

	return in;

}

int main() {
	Produs p1("Laptop", "Lenovo", 1200, 100);
	Produs p2("Smartphone", "Samsung", 1900, 100);
	cout << p1 << p2;
	cin >> p2;

	cout << p2;

	//fisiere text
	//fstream, ofstream, ifstream

	ofstream raport;
	raport.open("Raport produse.txt", ios::out | ios::app);
	raport << p1 << p2;
	raport.close();

	//citire din fisier text
	ifstream input("Raport produse.txt");
	if (input.is_open()) {
		while (!input.eof()) {
			string linieFisier;
			char buffer[1000];
			input.getline(buffer, 1000);
			linieFisier = string(buffer);
			cout << endl << "Linie fisier: " << linieFisier;
		}
		input.close();
	}
	else
		cout << endl << "!!!!!!!!!!!!!!! Nu gasesc fisierul !!!!!";

}