#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

	int intValue = 23;
	string name = "John";
	char anotherName[100];
	strcpy(anotherName, "Alice");
	char* email;
	email = new char[strlen("me@email.com") + 1];
	strcpy(email, "me@email.com");
	int values[10];
	for (int i = 0; i < 10; i++)
		values[i] = i + 1;
	int * otherValues = new int[5];
	for (int i = 0; i < 5; i++)
		otherValues[i] = i * 10;

	//opening a binary file
	ofstream file("mydata.bin", ios::out | ios::binary);
	//writing values

	//<< will convert the values to string
	//file << intValue;
	//file << name;
	//file << anotherName;

	file.write((char*)&intValue, sizeof(int));
	file.write(name.c_str(), name.size() + 1);
	//write the value from the static array
	//write the size of it
	int arraySize = strlen(anotherName) + 1;
	file.write((char*)&arraySize, sizeof(int));
	file.write(anotherName, strlen(anotherName) + 1);
	file.write(email, strlen(email) + 1);
	//writing the static array of 10 values, one by one
	for (int i = 0; i < 10; i++) {
		file.write((char*)&values[i], sizeof(int));
	}
	//write the dynamic array of 5 values at once
	file.write((char*)otherValues, 5 * sizeof(int));


	file.close();

	//read the data back
	ifstream input("mydata.bin", ios::in | ios::binary);
	//read the int
	int vb;
	input.read((char*)&vb, sizeof(int));
	cout << endl << "Vb = " << vb;
	//read the string
	//read byte by byte until \0
	char buffer[1000];
	for (int i = 0;;i++) {
		input.read(&buffer[i], 1);
		if (buffer[i] == '\0')
			break;
	}
	name = string(buffer);
	cout << endl << "The name is: " << name;
	//read the another name
	int noChars;
	input.read((char*)&noChars, sizeof(int));
	input.read(buffer, noChars);
	cout << endl << "The another name is " << buffer;


	input.close();

	cout << endl << "The end";


}