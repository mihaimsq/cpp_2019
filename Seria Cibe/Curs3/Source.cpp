#include <stdio.h>

void interschimbareDouaNumere(int valoare1, int valoare2) {
	int temp = valoare1;
	valoare1 = valoare2;
	valoare2 = temp;
}

//NU EXISTA LA ACEST CURS
//int variabilaGlobala;

int main() {
	//ce este un pointer ?
	//o variabila numerica folosita pentru a stoca numere
	//....., ce sunt adrese in memorie
	void *unPointer;

	int numarNorocos = 10;
	int *adresaNumarNorocos;
	
	
	//varianta in care punem un numar
	//adresaNumarNorocos = (int*)numarNorocos;

	//printf("\n Adresa din pointer este %d", adresaNumarNorocos);
	//printf("\n Valoarea din RAM de la adresa aia este %d", *adresaNumarNorocos);

	adresaNumarNorocos = &.;
	printf("\n Adresa din pointer este %d", adresaNumarNorocos);
	printf("\n Valoarea din RAM de la adresa aia este %d", *adresaNumarNorocos);

	*adresaNumarNorocos = 7;
	printf("\n Numarul norocos este %d", numarNorocos);

	int vb1 = 10;
	int vb2 = 20;

	printf("\n vb1 = %d si vb2 = %d", vb1, vb2);

	int temp = vb1;
	vb1 = vb2;
	vb2 = temp;

	printf("\n vb1 = %d si vb2 = %d", vb1, vb2);

	interschimbareDouaNumere(vb1, vb2);

	printf("\n vb1 = %d si vb2 = %d", vb1, vb2);

}