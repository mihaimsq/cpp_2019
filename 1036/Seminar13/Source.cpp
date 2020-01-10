#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum TipPet {Pestisor=10, Pisica=20, Catel, Broscuta = 30};

class InterfataPet {
public:
	virtual void afisare() = 0;
	virtual void serializare(ofstream& fisierBinar) = 0;
	virtual void deserializare(ifstream& fisierBinar) = 0;
};

class Pet: public InterfataPet {
	string descriere = "";
	TipPet tip = TipPet::Pestisor;
	char nume[50];
	char* stapan = NULL;
	int varsta = 0;
public:
	Pet(string Descriere, TipPet Tip,
		const char* Nume, const char* Stapan, int Varsta) {
		descriere = Descriere;
		this->varsta = Varsta;
		tip = Tip;
		strcpy(nume, Nume);
		stapan = new char[strlen(Stapan) + 1];
		strcpy(stapan, Stapan);
	}

	virtual void afisare() {
		cout << this->nume << " are ca stapan pe " << this->stapan;
	}

	void serializare(ofstream& fisierBinar) {
		//scriu descriere ca un buffer de 100B
		char buffer[100];
		strcpy(buffer, this->descriere.c_str());
		fisierBinar.write(buffer,sizeof(buffer));
		//tipul
		fisierBinar.write((char*)&this->tip, sizeof(TipPet));
		//numele
		fisierBinar.write(this->nume, sizeof(this->nume));
		//stapan
		int dim = strlen(this->stapan) + 1;
		fisierBinar.write((char*)&dim, sizeof(int));
		fisierBinar.write(this->stapan, dim * sizeof(char));
		//varsta
		fisierBinar.write((char*)&this->varsta, sizeof(int));

	}
	void deserializare(ifstream& fisierBinar) {
		//citesc descrierea
		char buffer[100];
		fisierBinar.read(buffer, sizeof(buffer));
		this->descriere = string(buffer);
		//tipul
		fisierBinar.read((char*)&this->tip, sizeof(TipPet));
		//numele
		fisierBinar.read(this->nume, sizeof(this->nume));
		//stapanul
		int n;
		fisierBinar.read((char*)&n, sizeof(int));
		if (this->stapan != NULL)
			delete[] this->stapan;
		this->stapan = new char[n];
		fisierBinar.read(this->stapan, n * sizeof(char));
		//varsta
		fisierBinar.read((char*)&this->varsta, sizeof(int));
	}
};

int main() {
	Pet pet1("Un pestisor auriu", TipPet::Pestisor, "Gigel", "Eu", 1);

}

