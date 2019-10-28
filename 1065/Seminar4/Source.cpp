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

//IT's not working because the array is on the functions stack
//	the array is lost when the function terminates

//int* createAndInitAnArray(int* noNewArrayElements) {
//	int newArray[40];
//	int noElements;
//	int initialValue;
//
//	std::cout << std::endl << "The number of elements is:";
//	std::cin >> noElements;
//	*noNewArrayElements = noElements;
//
//	std::cout << std::endl << "The initial value is:";
//	std::cin >> initialValue;
//
//	initArrayWithGivenValue(
//		newArray, noElements, initialValue);
//
//	return newArray;
//}
int* createAndInitAnArray(int* noNewArrayElements) {
	//int newArray[40];
	int* newArray = NULL;
	int noElements;
	int initialValue;

	std::cout << std::endl << "The number of elements is:";
	std::cin >> noElements;
	*noNewArrayElements = noElements;

	std::cout << std::endl << "The initial value is:";
	std::cin >> initialValue;

	newArray = new int[noElements];

	initArrayWithGivenValue(
		newArray, noElements, initialValue);

	return newArray;
}

struct PromotionalOffer {
	//manage a store promotional offer
	int *prices;
	int noProducts;
	string *productNames;

	char storeName[50];
	char* storeAddress;
	string campaign;
};

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
	int newNumber = 0;

	//THIS WILL NOT WORK
	//productPrices = createAndInitAnArray();
	newArray = createAndInitAnArray(&newNumber);

	printArray(newArray, newNumber);

	PromotionalOffer emagCampaign;
	PromotionalOffer altexCampaign;

	//emagCampaign.storeName = "emag";
	emagCampaign.campaign = "Black Friday";
	//emagCampaign.storeAddress = "Bucharest";
	emagCampaign.storeAddress = new char[1000];
	strcpy(emagCampaign.storeAddress, "Bucharest");
	strcpy(emagCampaign.storeName, "emag");
	cout << endl << "Store name is :" << emagCampaign.storeName;


}