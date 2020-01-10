#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class AnyClassInterface {
public:
	virtual void print() = 0;
	virtual void serialize(ofstream& file) = 0;
	virtual void deserialize(ifstream& file) = 0;
};

enum PetType {DOG = 10, CAT, FISH = 20, PARROT = 30};

class Pet: public AnyClassInterface {
	string name = "Not known";
	char owner[50];
	char* description = NULL;
	string* medicalRecords = NULL;
	int noRecords = 0;
	PetType type = PetType::DOG;
public:
	Pet(string Name, const char* Owner,
		const char* Descr, string* Records, int NoRecords,
		PetType Type) {
		this->type = Type;
		noRecords = NoRecords;
		name = Name;
		strcpy(owner, Owner);
		description = new char[strlen(Descr) + 1];
		strcpy(description, Descr);
		medicalRecords = new string[NoRecords];
		for (int i = 0; i < NoRecords; i++)
			medicalRecords[i] = Records[i];
	}

	void print() {
		cout << endl << this->owner << " has a pet named "
			<< this->name;
	}
	void serialize(ofstream& file) {
		//write the name as a 100 Byte buffer
		char buffer[100];
		strcpy(buffer, name.c_str());
		file.write(buffer, 100 * sizeof(char));
		//write the owner
		file.write(this->owner, sizeof(this->owner));
		//write the description
		int size = strlen(this->description) + 1;
		file.write((char*)&size, sizeof(int));
		file.write(description, size * sizeof(char));
		//write no records
		file.write((char*)&noRecords, sizeof(int));
		//write records
		for (int i = 0; i < noRecords; i++) {
			char record[1000];
			strcpy(record, medicalRecords[i].c_str());
			file.write(record, sizeof(record));
		}
		//write the type
		file.write((char*)&type, sizeof(PetType));

	}
	void deserialize(ifstream& file) {
		//read the name
		char buffer[100];
		file.read(buffer, sizeof(buffer));
		this->name = string(buffer);
		//read the owner
		file.read(this->owner, sizeof(this->owner));
		//read the description
		int size;
		file.read((char*)&size, sizeof(int));
		if (this->description != NULL)
			delete[] this->description;
		this->description = new char[size];
		file.read(description, size * sizeof(char));

		//medical records
		file.read((char*)&this->noRecords, sizeof(int));
		if (this->medicalRecords != NULL)
			delete[] medicalRecords;
		medicalRecords = new string[noRecords];
		for (int i = 0; i < noRecords; i++) {
			char record[1000];
			file.read(record, sizeof(record));
			medicalRecords[i] = string(record);
		}

		//read the type
		file.read((char*)&this->type, sizeof(PetType));


	}
};

int main() {
	string* records = new string[3]{
		"check 1", "vaccine 1", "check 2" };
	int n = 3;

	Pet pet1(
		"Silver", "John", "A funny dog", records, n, PetType::DOG);

	Pet** pets = new Pet*[2];
	pets[0] = &pet1;
	pets[1] = new Pet(
		"Goldy", "Alice", "Small fish", records, n, PetType::FISH);


}