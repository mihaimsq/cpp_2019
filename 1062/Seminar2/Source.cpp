#include <stdio.h>
#include <iostream>
using namespace std;

void main() {

	int luckyNumber = 7;


	//printf("\n The lucky number is %d", 
	//	luckyNumber);
	//printf("\n Give me onother one:");
	//scanf("%d", &luckyNumber);
	//printf("\n The lucky number is %d",
	//	luckyNumber);


	//std::cout << "\n The lucky number is " 
	//	<< luckyNumber;
	//cout << std::endl << "Give me onother one:";
	//cin >> luckyNumber;
	//std::cout << "\n The lucky number is "
	//	<< luckyNumber;

	//arrays
	//static 
	int luckyNumbers[6];
	int noLuckyNumbers = 6;

	//init the values with 0
	for (int i = 0; i < noLuckyNumbers; i++) {
		luckyNumbers[i] = 0;
	}

	cout << endl << "Lucky numbers:";
	for (int i = 1; i <= noLuckyNumbers+20; i++) {
		cout << endl << "Lucky number "
			<< i << ": " << luckyNumbers[i];
	}
	luckyNumbers[100] = 55;
}