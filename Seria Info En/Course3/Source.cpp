#include <stdio.h>

void interchange(int vb1, int vb2) {
	int temp = vb1;
	vb1 = vb2;
	vb2 = temp;
}

void interchange2(int* addressVb1, int* addressVb2) {
	int temp = *addressVb1;
	*addressVb1 = *addressVb2;
	*addressVb2 = temp;
}

void interchange3(int& vb1, int& vb2) {
	int temp = vb1;
	vb1 = vb2;
	vb2 = temp;
}

int main() {

	int justANumber = 100;

	//a pointer is a numerical variable that stores addresses
	//define a pointer
	void *aGenericPointer;
	int *pointerToANumber;

	//pointerToANumber = (int*)10;

	//init them with valid addresses
	pointerToANumber = &justANumber;

	printf("\n The pointer value is %d", pointerToANumber);
	printf("\n The value at the address %d is %d",
		pointerToANumber, *pointerToANumber);

	//write somthing at the pointer address
	*pointerToANumber = 99;

	printf("\n Just a number: %d", justANumber);

	int value1 = 10;
	int value2 = 20;

	printf("\n value1 =  %d, value2 = %d", value1, value2);

	//interchange(value1, value2);
	//interchange2(&value1, &value2);
	interchange3(value1, value2);

	printf("\n value1 =  %d, value2 = %d", value1, value2);
}