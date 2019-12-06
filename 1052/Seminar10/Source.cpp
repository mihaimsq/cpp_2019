#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
	int variabila = 23;
	char unCaracter = 'a';
	string nume = "Popescu";
	char prenume[50];
	strcpy(prenume, "Gigel");
	char *adresa;
	adresa = new char[strlen("Bucuresti") + 1];
	strcpy(adresa, "Bucuresti");

	int puncte[5] = { 1,2,3,4,5 };
	int nrPuncte = 5;
	int* valori = new int[3];
	int nrValori = 3;
	for (int i = 0; i < nrValori; i++) {
		valori[i] = i * 10;
	}

	//scriere in fisiere binare
	ofstream fisier("date.bin", ios::out | ios::binary);
	
	//NU folosim << pt ca acesta transforma toate valorile in text
	//fisier << variabila;

	fisier.write((char*)&variabila, sizeof(int));
	fisier.write(&unCaracter, sizeof(char));
	fisier.write(nume.c_str(), nume.size() + 1);

	//scriem numarul de caractere
	int nrCaractere = strlen(prenume) + 1;
	fisier.write((char*)&nrCaractere, sizeof(int));
	fisier.write(prenume, strlen(prenume) + 1);

	nrCaractere = strlen(adresa) + 1;
	fisier.write((char*)&nrCaractere, sizeof(int));
	fisier.write(adresa, strlen(adresa) + 1);

	//vectori de numere
	//scriu numarul de elemente
	fisier.write((char*)&nrPuncte, sizeof(int));
	//il scriu element cu element
	for (int i = 0; i < nrPuncte; i++) {
		fisier.write((char*)&puncte[i], sizeof(int));
	}
	//il scriu pe tot
	fisier.write((char*)&nrValori, sizeof(int));
	fisier.write((char*)valori, nrValori * sizeof(int));

	fisier.close();

	ifstream input("date.bin", ios::in | ios::binary);
	if (input.is_open()) {

		int vb;
		input.read((char*)&vb, sizeof(int));
		cout << endl << " vb = " << vb;
		char c;
		input.read(&c, 1);
		cout << endl << " caracter = " << c;
		char buffer[100];
		//citim pana la \0
		for (int i = 0;; i++) {
			//citim un caracter
			input.read(&buffer[i], sizeof(char));
			if (buffer[i] == '\0')
				break;
		}
		string nume2 = string(buffer);
		cout << endl << "Nume2 = " << nume2;

		input.close();
	}
	else
		cout << endl << "*********** Probleme fisier";

	cout << endl << "Sfarsit exemplu";

}