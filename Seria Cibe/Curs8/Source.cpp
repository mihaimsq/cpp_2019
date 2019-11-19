#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {

	string nume;
	int varsta;
	char bufferNume[1000];


	////citire cu space
	//cout << endl << "Nume :";
	////cin >> nume;	//limitat la space
	//cin.getline(bufferNume, 1000);
	//nume = string(bufferNume);
	//cout << endl << "Varsta: ";

	//cin >> varsta;

	//cin.get();
	//cin.get();

	//cout << endl << nume << " - " << varsta << " ani";

	//lucru cu fisiere text
	//scriere in fisiere text
	
	//varianta in care fisierul este deschis in mod text cu trunc
	//ofstream raport("raport.txt");

	//ofstream raport;
	//raport.open("raport.txt", ios::out | ios::app);

	//if (raport.is_open()) {
	//	raport << endl << nume << " - " << varsta << " ani";
	//	raport.close();
	//}
	//else
	//	cout << endl << "*************** Probleme la deschiderea fisierului";

	//citire din fisiere text
	ifstream fisier("raport.txt");
	if (fisier.is_open()) {

		while (!fisier.eof()) {
			char buffer[1000];
			fisier.getline(buffer, 1000);

			//daca stim ca nu exista spatiu pe linie
			//string linie;
			//fisier >> linie;

			string linie(buffer);

			int indexSeparatorNume = linie.find('-');
			cout << endl << "Index - " << indexSeparatorNume;

			if (indexSeparatorNume != -1) {
				string nume = linie.substr(0, indexSeparatorNume - 1);
				cout << endl << "Numele este " << nume;
			}

			cout << endl << "Linie fisier: " << linie;
		}

		fisier.close();
	}

	//o valoare, o linie
	ifstream fisier2("date.txt");
	if (fisier2.is_open()) {

		while (!fisier2.eof()) {
			string linie;
			char buffer[1000];
			fisier2.getline(buffer, 1000);

			linie = string(buffer);
			string nume = linie;
			int varsta;
			fisier2 >> varsta;
			string facultate;
			fisier2 >> facultate;
			fisier2.get();

			cout << endl << "Nume: " << nume;
			cout << endl << "Varsta: " << varsta;
			cout << endl << "Facultate: " << facultate;
		}

		fisier2.close();
	}
	else
		cout << endl << "*************** Probleme la deschidere fisier";

}