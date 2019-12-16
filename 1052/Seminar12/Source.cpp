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

	virtual void info() {
		cout << endl << "-----------------------";
		cout << endl << "Nume: " << this->nume;
		cout << endl << "Varsta: " << this->varsta;
		cout << endl << "Facultate: " << this->facultate;
	}

	//functie virtuala pura - nu are corp
	virtual void functieObligatorie() = 0;
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

	void printMasterand() {
		this->info();
		cout << endl << "Program masterat " << this->programMasterat;
	}

	//supraincarcare
	void ceva(int vb) {

	}
	void ceva(int a, int b) {

	}
	void ceva(string a, float b) {

	}

	//supradefinire
	void info() {
		this->Student::info();
		cout << endl << "Program masterat " << this->programMasterat;
	}

	void functieObligatorie() {

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

	//supradefinire
	void info() {
		this->Student::info();
		cout << endl << "Companie practica " << this->companie;
	}
};

int main() {

	//nu mai merge cu clasa abstracta
	Student s1;
	Student s2("Student Gigel", 21, "CSIE");

	//s1.info();
	//s2.info();

	Masterand m1("Masterand Ionel", 22, "CSIE","IE");
	Intern i1("Intern Ana", 21, "CSIE", "Intel");

	//m1.info();

	//Student lista[4];
	//lista[0] = s1;
	//lista[1] = s2;
	//lista[2] = m1;		//up-casting
	//lista[3] = i1;

	Student* lista2[4];

	lista2[0] = &s1;
	lista2[1] = &s2;
	lista2[2] = &m1;	//up casting la nivel de pointer
	lista2[3] = &i1;	//up casting la nivel de pointer

	for (int i = 0; i < 4; i++) {
		lista2[i]->info();	//early-binding fara virtual
		//late-binding cu virtual
	}

}