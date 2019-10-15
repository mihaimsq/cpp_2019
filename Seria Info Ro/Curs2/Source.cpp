#include <stdio.h>
#include <string>
using namespace std;

int main() {

	int numar = 21;
	//char caracter = 'e';
	char caracter = 101; //cod ASCII e
	char caracter2 = 48;
	//char caracter3 = '48';
	//char caracter4 = "48";

	printf("\n Numarul este %d", numar);
	printf("\n Caracterul este %c", caracter);

	//definire siruri de caractere
	char nume[50];
	std::string numeStudent;
	char* numeProfesor;

	//nume = "Gigel";
	strcpy(nume, "Gigel");
	numeStudent = "Ana";
	//numeProfesor = "Vader";
	numeProfesor = new char[20];
	strcpy(numeProfesor, "Vader");

	//stergere
	//delete[] nume;
	delete[] numeProfesor;


	
}