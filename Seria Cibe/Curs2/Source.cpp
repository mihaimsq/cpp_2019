#include <stdio.h>

int main() {
	int vb = 10;
	char z = 48;
	char x = 'a';
	char nume[] = "Gigel";
	int note[10];
	int *noteDinamic;
	noteDinamic = new int[10];

	printf("Salut ! Prima aplicatie C++");
	printf("\n Valoarea lui vb este %d", vb);
	printf("\n Valoarea lui x este %d", x);
	printf("\n Valoarea lui z este %c", z);
	nume[2] = '\0';
	printf("\n Numele este %s", nume);
	printf("\n Valoare pointerului este %d", noteDinamic);
	//return 0;
}