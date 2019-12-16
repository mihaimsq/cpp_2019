#include <iostream>
#include <string>

using namespace std;

class Student {
protected:
	string nume = "Anonim";
	int varsta = 0;
	string facultate = "";
public:
	Student() {
		cout << endl << "Constructor default Student";
	}
	Student(string nume, int varsta, string facultate) {
		this->nume = nume;
		this->facultate = facultate;
		this->varsta = varsta;
		cout << endl << "Constructor cu parametri Student";
	}
	~Student() {
		cout << endl << "Destructor student";
	}

	void info() {
		cout << endl << "-----------------------";
		cout << endl << "Nume: " << this->nume;
		cout << endl << "Varsta: " << this->varsta;
		cout << endl << "Facultate: " << this->facultate;
	}
};

class Masterand : public Student {
protected: 
	string programMasterat = "";
public:
	Masterand() : Student("Masterand anonim",0,"") {
		cout << endl << "Apel constructor default Masterand";

	}
	Masterand(string nume, int varsta,
		string facultate, string masterat)
		:Student(nume, varsta, facultate)
	{
		cout << endl << "Apel constructor cu parametri Masterand";
		this->programMasterat = masterat;
	}
	~Masterand() {
		cout << endl << "Apel destructor masterand";
	}
};

class Intern: public Student {
protected:
	string companie;
public:
	Intern(string nume, int varsta,
		string facultate, string companie)
		: Student(nume, varsta, facultate) {
		cout << endl << "Apel constructor cu parametri Intern";
		this->companie = companie;
	}
	~Intern() {
		cout << endl << "Apel destructor Intern";
	}
};

int main() {
	Student s1;
	Student s2("Gigel", 21, "CSIE");

	s1.info();
	s2.info();

	Masterand m1;
}