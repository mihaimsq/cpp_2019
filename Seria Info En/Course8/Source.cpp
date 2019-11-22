#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {

	float variable = 2.33333;
	int intVariable = 10;

	printf("\n variable = %d", (int)variable);
	printf("\n variable = %3.2f", variable);
	printf("\n intVariable = %d", intVariable);
	printf("\n intVariable = %x", intVariable);

	cout << endl << "The value in hex is " 
		<< std::uppercase <<std::hex << intVariable;

	string name;
	int value;

	//limited by space
	//cout << endl << "The name is :";
	//cin >> name;
	//cout << endl << "The value is :";
	//cin >> value;

	//cout << endl << "Name = " << name << " and the value " << std::dec << value;

	//limited by space
	cout << endl << "The name is :";
	char buffer[100];
	//cin.get();
	cin.getline(buffer,100);
	name = string(buffer);
	cout << endl << "The value is :";
	cin >> value;

	cout << endl << "Name = " << name << " and the value " << std::dec << value;

	int someValue = (1, value, intVariable);
	cout << endl << "Some value = " << someValue;

	//files
	//types: text and binary
	//text types
	//		- sequential
	//binary types
	//		- sequential
	//		- direct access (uses an index, uses values with the same size)

	//text files
	//create a text file
	//fstream - generic purpose file handling
	//ofstream - writing into files
	//ifstream - reading from files

	//create a text file and open it in write mode
	ofstream report;
	report.open("report.txt", ios::app | ios::out);
	report << endl << "Name = " << name << " and the value " << std::dec << value;

	report.close();

	//reading from a text file
	ifstream input("report.txt");
	if (input.is_open()) {
		string aTextLine;
		while (!input.eof()) {
			char buffer[1000];
			//input >> aTextLine;
			input.getline(buffer, 1000);
			aTextLine = string(buffer);
			cout << endl << "File content :" << aTextLine;
		}
		input.close();
	}
	else
		cout << endl << "!!!!!!!!!!!!!!!!! Houston we have a problem with the file";
}