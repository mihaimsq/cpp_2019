#include <stdio.h>


void interschimbare(int valoare1, int valoare2) {
	int temp = valoare1;
	valoare1 = valoare2;
	valoare2 = temp;
}

void interschimbare2(int *adresaVb1, int *adresaVb2) {
	int temp = *adresaVb1;
	*adresaVb1 = *adresaVb2;
	*adresaVb2 = temp;
}

void interschimbare3(int& valoare1, int& valoare2) {
	int temp = valoare1;
	valoare1 = valoare2;
	valoare2 = temp;
}

int main() {

	int unNumarOarecare;
	unNumarOarecare = 10;

	//definire pointer
	void *pointerGeneric;
	int *pointerCatreNumar;

	//pointer este o variabila care stocheaza numere
	//ce este o adresa in memorie?
	//		un numar

	pointerCatreNumar = (int*)100;
	printf("\n Valoare din pointer este %d", pointerCatreNumar);

	//citire si scriere prin pointeri


	//printf("\n La adresa %d se gaseste un numar %d",
	//	pointerCatreNumar, *pointerCatreNumar);

	pointerCatreNumar = &unNumarOarecare;

	printf("\n La adresa %d se gaseste un numar %d",
		pointerCatreNumar, *pointerCatreNumar);

	int vb1 = 10;
	int vb2 = 20;

	printf("\n vb1 = %d si vb2 = %d", vb1, vb2);
	
	int temp = vb1;
	vb1 = vb2;
	vb2 = temp;
	
	printf("\n vb1 = %d si vb2 = %d", vb1, vb2);

	//interschimbare(vb1, vb2);
	interschimbare2(&vb1, &vb2);

	printf("\n vb1 = %d si vb2 = %d", vb1, vb2);

	interschimbare3(vb1, vb2);

	printf("\n vb1 = %d si vb2 = %d", vb1, vb2);

}