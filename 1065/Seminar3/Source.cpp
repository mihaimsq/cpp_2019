#include <iostream>
using namespace std;

void printArray(int array[], int n) {
	cout << endl << "The array values are: ";
	for (int i = 0; i < n; i++) {
		cout << array[i] << ", ";
	}
}

void initArrayWithGivenValue(int * array, int n, int value) {
	for (int i = 0; i < n; i++)
		array[i] = value;
}

int* createAndInitAnArray(int* noNewArrayElements) {
	int newArray[40];
	int noElements;
	int initialValue;

	std::cout << std::endl << "The number of elements is:";
	std::cin >> noElements;
	*noNewArrayElements = noElements;

	std::cout << std::endl << "The initial value is:";
	std::cin >> initialValue;

	initArrayWithGivenValue(
		newArray, noElements, initialValue);

	return newArray;
}

int main() {

	int productPrices[40];
	int noProducts;
	int initialValue;

	//std::cout << std::endl << "The number of products is:";
	//std::cin >> noProducts;
	//std::cout << std::endl << "The initial value is:";
	//std::cin >> initialValue;

	//initArrayWithGivenValue(
	//	productPrices, noProducts, initialValue);
	// printArray(productPrices, noProducts);

	int* newArray;
	int newNumber = 0 ;

	//THIS WILL NOT WORK
	//productPrices = createAndInitAnArray();
	newArray = createAndInitAnArray(&newNumber);

	printArray(newArray, newNumber);
}