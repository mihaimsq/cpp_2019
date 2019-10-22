#include <iostream>
using namespace std;

void printArray(int values[], int n) {
	std::cout << std::endl << "The array is: ";
	for (int i = 0; i < n; i++) {
		cout << values[i] << " , ";
	}
}

void initArrayWithGivenValue(
	int* vector, int n, int value) {

	for (int i = 0; i < n; i++) {
		vector[i] = value;
	}

}

int* createAndInitAnArray(int* addressOfNumberElements) {
	//define an array
	int newArray[20];
	int noElements;
	int initialValue;

	std::cout << std::endl << "The number of elements is: ";
	std::cin >> noElements;
	*addressOfNumberElements = noElements;
	std::cout << std::endl << "The initial value is: ";
	cin >> initialValue;

	initArrayWithGivenValue(
		newArray, noElements, initialValue);

	return newArray;
}

int main() {

	//define an array
	int productPrices[20];
	int noProducts;

	//std::cout << std::endl << "The number of products is: ";
	//std::cin >> noProducts;

	//initArrayWithGivenValue(
	//	productPrices, noProducts, 0);

	//YOU CAN'T
	//productPrices = createAndInitAnArray();

	int newElementsNumber = 0;
	int* newValues = 
		createAndInitAnArray(&newElementsNumber);


	printArray(newValues, newElementsNumber);

}