
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main() {
	int integerValue = 23;
	string lastName = "Popescu";
	char firstName[50];
	strcpy(firstName, "John");
	char *address = new char[strlen("Bucharest") + 1];
	strcpy(address, "Bucharest");
	int values[5] = { 1,2,3,4,5 };
	int *points = new int[3];
	int noPoints = 3;

	for (int i = 0; i < noPoints; i++) {
		points[i] = 10 * i;
	}

	//write them in a binary file
	ofstream file;
	file.open("myData.bin", ios::out | ios::binary);


	//<< will always convert the values to their string format
	//file << integerValue;
	//writing an int
	file.write((char*)&integerValue, 
		sizeof(int));
	//writing the string with \0
	file.write(lastName.c_str(),
		lastName.size()+1);
	//writing the first name - char[50] with \0
	//writing its size
	int noChars = strlen(firstName) + 1;
	file.write((char*)&noChars, sizeof(int));
	file.write(firstName, strlen(firstName) + 1);
	//the address with \0
	file.write(address, strlen(address)+1);
	//store values int[5]
	//store it entirely in a single operation
	//only for static arrays
	//file.write((char*)values, sizeof(values));
	file.write((char*)values, sizeof(int) * 5);

	//store points = new int[]
	//store it value by value
	for (int i = 0; i < noPoints; i++) {
		file.write((char*)&points[i], sizeof(int));
	}
	file.close();

	//reading from a binary file
	ifstream input("myData.bin", ios::in | ios::binary);
	if (input.is_open()) {

		//read the integer value
		int vb;
		input.read((char*)&vb,sizeof(int));
		cout << endl << "Vb = " << vb;
		//read the string
		char buffer[100];
		//read each char into the buffer until \0
		for (int i = 0;; i++) {
			input.read(&buffer[i], 1);
			if (buffer[i] == '\0')
				break;
		}
		string name2 = string(buffer);
		cout << endl << "The name is " << name2;


		input.close();
	}
	else
		cout << endl << "************FILE not opened !";

}