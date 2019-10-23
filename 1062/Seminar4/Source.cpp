#include <iostream>
#include <string>
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

//int* createAndInitAnArray(int* addressOfNumberElements) {
//	//define an array
//	//IT's WRONG - the static array is on the functions stack
//	// you will LOSE IT
//	int newArray[20];
//	int noElements;
//	int initialValue;
//
//	std::cout << std::endl << "The number of elements is: ";
//	std::cin >> noElements;
//	*addressOfNumberElements = noElements;
//	std::cout << std::endl << "The initial value is: ";
//	cin >> initialValue;
//
//	initArrayWithGivenValue(
//		newArray, noElements, initialValue);
//
//	return newArray;
//}

int* createAndInitAnArray(int* addressOfNumberElements) {
	//define an array

	int* newArray = NULL;
	int noElements;
	int initialValue;

	std::cout << std::endl << "The number of elements is: ";
	std::cin >> noElements;
	*addressOfNumberElements = noElements;

	//create the new array
	newArray = new int[noElements];

	std::cout << std::endl << "The initial value is: ";
	cin >> initialValue;

	initArrayWithGivenValue(
		newArray, noElements, initialValue);

	return newArray;
}

struct promotionalOffer {
	int* productPrices;
	int noProducts;
	string *productNames;

	char storeName[50] = "noName";
	char *adddress;
	string promotionName = "no name";

};

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

	//create a black friday offer
	promotionalOffer blackFriday;

	//get the data from the console
	blackFriday.productPrices =
		createAndInitAnArray(&blackFriday.noProducts);

	blackFriday.productNames = new string[blackFriday.noProducts];
	cout << endl << "Product names are:";
	for (int i = 0; i < blackFriday.noProducts; i++){
		cout << endl << "Product " << i + 1 << ":";
		cin >> blackFriday.productNames[i];
	}

	cout << endl << "Store name :";
	cin >> blackFriday.storeName;

	cout << endl << "Store address :";
	char buffer[1000];
	cin >> buffer;
	blackFriday.adddress = new char[strlen(buffer) + 1];
	strcpy(blackFriday.adddress, buffer);


}