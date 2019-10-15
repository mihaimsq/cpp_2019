#include <stdio.h>
#include <iostream>
using namespace std;

void main() {

	int luckyNumber = 7;

	//printf("\n The lucky number is: %d", luckyNumber);
	//printf("\n Give me your lucky number: ");
	//scanf("%d", &luckyNumber);
	//printf("\n The lucky number is: %d", luckyNumber);

	//std::cout << "\n The lucky number is:" << luckyNumber;
	//cout << std::endl << "Give me your lucky number: ";
	//cin >> luckyNumber;
	//std::cout << "\n The lucky number is:" << luckyNumber;

	//arrays
	//static approach
	//1. define

	int noLuckyNumbers = 6;
	int luckyNumbers[6];


	//2. init
	for (int i = 0; i < noLuckyNumbers; i++) {
		luckyNumbers[i] = i + 1;
	}

	cout << endl << "The values are:";
	for (int i = 0; i < noLuckyNumbers; i++) {
		cout << luckyNumbers[i] << " , ";
	}

	//adding a new value to the existing array ?
	//DON'T TRY
	//luckyNumbers[6] = 55;
	//cout << endl << "The values are:";
	//for (int i = 0; i <= noLuckyNumbers; i++) {
	//	cout << luckyNumbers[i] << " , ";
	//}

	//DON'T TRY THIS EITHER
	//int luckyNumbers2[7];

	//DYNAMIC ARRAYS
	//1. define
	int* bingoNumbers;
	int noBingoNumbers = 6;

	//2. create it
	bingoNumbers = new int[noBingoNumbers];

	//3. print it
	cout << endl << "Bingo numbers:";
	for (int i = 0; i < noBingoNumbers; i++) {
		cout << bingoNumbers[i] << ", ";
	}


}