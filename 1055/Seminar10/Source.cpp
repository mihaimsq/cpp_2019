#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	int valoareInt = 23;
	string prenume = "Ionut";
	char nume[100];
	strcpy(nume, "Popescu");

	char* adresa;
	adresa = new char[strlen("Bucuresti") + 1];
	strcpy(adresa, "Bucuresti");

	int puncteFidelitate[10];
	int nrPuncte = 10;
	for (int i = 0; i < nrPuncte; i++) {
		puncteFidelitate[i] = i + 1;
	}

	int *valori = new int[5];
	int nrValori = 5;
	for (int i = 0; i < nrValori; i++) {
		valori[i] = i * 10;
	}

	//salvare date in fisier binar
	ofstream fisier("date.bin", ios::out | ios::binary);
	// << face conversie la text
	//fisier << valoareInt;

	fisier.write((char*)&valoareInt, sizeof(int));
	//scriem prenumele
	fisier.write(prenume.c_str(), prenume.size() + 1);
	//scriem numele
	//scriem numarul de caractere al numelui
	int nrCaractere = strlen(nume) + 1;
	fisier.write((char*)&nrCaractere, sizeof(int));
	fisier.write(nume, strlen(nume) + 1);
	//scriem adresa
	nrCaractere = strlen(adresa) + 1;
	fisier.write((char*)&nrCaractere, sizeof(int));
	fisier.write(adresa, strlen(adresa) + 1);
	//scriem puncte fidelitate
	//scriem dimensiunea
	fisier.write((char*)&nrPuncte, sizeof(int));
	//element cu element
	for (int i = 0; i < nrPuncte; i++) {
		fisier.write((char*)&puncteFidelitate[i],
			sizeof(int));
	}
	//scriem valorile
	//scriem dimensiunea
	fisier.write((char*)&nrValori, sizeof(int));
	fisier.write((char*)valori, sizeof(int) * nrValori);

	fisier.close();

	//citire din fisiere binare
	ifstream input("date.bin", ios::in | ios::binary);
	//citim valoarea int
	int valoare;
	input.read((char*)&valoare, sizeof(int));
	cout << endl << "Numar: " << valoare;
	//citesc prenumele
	//nu stiu cate caractere are
	char buffer[1000];
	//citim caracter cu caracter pana la \0
	for (int i = 0;; i++) {
		input.read(&buffer[i], 1);
		if (buffer[i] == '\0')
			break;
	}
	string prenume2 = string(buffer);
	cout << endl << "Prenume: " << prenume2;
	//citim numele
	char nume2[100];
	//citesc numarul de caractere
	int nrC;
	input.read((char*)&nrC, sizeof(int));
	input.read(nume2, nrC * sizeof(char));
	cout << endl << "Nume: " << nume2;

	//citim adresa
	input.read((char*)&nrC, sizeof(int));
	char* adresa2 = new char[nrC];
	input.read(adresa2, nrC * sizeof(char));
	cout << endl << "Adresa: " << adresa2;

	//citim vectorul de puncte
	int nrPuncte2;
	input.read((char*)&nrPuncte2, sizeof(int));
	int puncteF[10];
	input.read((char*)puncteF, sizeof(int)*nrPuncte2);

	input.close();

	cout << endl << "Sfarsit exemplu";
}