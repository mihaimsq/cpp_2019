#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
using namespace std;

class Test {


	int getVarsta();
};

int Test::getVarsta() {

}

int main() {

	float vb1 = 2.33333333;
	unsigned int vb2 = 10;
	printf("Vb1 = %2.2f", vb1);
	cout << endl << "Vb1 = " << vb1;
	cout << "Vb2 = " << std::uppercase << std::hex << vb2;

	string nume;
	int varsta;

	cout << endl << "Nume:";
	cin >> nume;	//considera space ca fiind separator
	cout << endl << "Varsta:";
	cin >> varsta;
	cout << endl << "Nume : " << nume << " si varsta " << std::dec << varsta;

	//citire cu spatiu
	cout << endl << "Nume:";
	char buffer[100];
	cin.get();
	cin.getline(buffer, 100);
	nume = string(buffer);
	cout << endl << "Varsta:";
	cin >> varsta;
	cout << endl << "Nume : " << nume << " si varsta " << std::dec << varsta;


	//fisiere
	//1. text
	//	secvential - la nivel de linie (pana la \n) sau la nivel de caracter
	//2. binar
	//	secvential - la nivel de byte
	//	cu acces direct - cu un index sau daca toate elementele au aceeasi dimensiune

	//citire si scriere
	int variabila = 23;

	//fisiere text
	//lucru generic cu fisiere
	fstream fisierGeneric;
	//lucru cu fisiere in mod scriere
	ofstream fisierIesire;
	//lucru cu fisiere in mod scriere
	ifstream fisierIntrare;

	//deschidere fisier text
	ofstream raport("raport.txt");
	ofstream raport2;
	raport2.open("raport2.txt", ios::out | ios::app);

	//test fisier binar
	ofstream raport3;
	raport3.open("raport3.bin", ios::out | ios::app | ios::binary);

	raport << endl << "Nume : " << nume << " si varsta " << std::dec << varsta;
	raport2 << endl << "Nume : " << nume << " si varsta " << std::dec << varsta;
	//in fisiere binare nu scriem cu  <<
	raport3 << endl << "Nume : " << nume << " si varsta " << std::dec << varsta;

	raport.close();
	raport2.close();
	raport3.close();
}