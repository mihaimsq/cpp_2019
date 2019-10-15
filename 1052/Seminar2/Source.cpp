#include <stdio.h>
#include <string>

int main() {

	int oVariabilaFolositaCaExemplu = 10;
	char caracter1 = 'c';
	char caracter2 = 65;
	//char caracter3 = "65";
	char caracter4 = '65';	//ia doar primul byte

	printf("\n Numarul este: %d", oVariabilaFolositaCaExemplu);
	printf("\n Caracterul este: %c", caracter1);
	printf("\n Caracterul este: %d", caracter1);

	//definire siruri de caractere
	std::string numeStudent1;
	char numeStudent2[50];
	char* numeStudent3;
	//char numeStudent4[];

	//initializare
	numeStudent1 = "Ana";
	//numeStudent2 = "Gigel";
	strcpy(numeStudent2, "Gigel");
	//numeStudent3 = "Vader";
	numeStudent3 = new char[strlen("Gigel")+1];
	strcpy(numeStudent3, "Vader");


	//return 0;
}