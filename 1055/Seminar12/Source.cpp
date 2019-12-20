#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Persoana {
protected:
	string nume = "Anonim";
	int varsta = 0;
public:

	Persoana() {

	}

	Persoana(string nume, int varsta)
		:nume(nume), varsta(varsta) {

	}
	void info() {
		cout << endl << this->nume << " are varsta " <<
			this->varsta;
	}
};

class Student : public Persoana {
protected:
	string facultate = "CSIE";
public:
	Student():Persoana("Student Anonim", 14) {

	}

	void infoStudent() {
		this->info();
		cout << endl << "Este student(a) la " << this->facultate;
	}

	//supraincarcare
	//overloading
	int ceva(int a) {

	}
	int ceva(int a, int b) {

	}

	//supradefinire
	//overriding
	void info() {
		this->Persoana::info();
		cout << endl << "Este student(a) la " << this->facultate;
	}
};

class Elev : public Persoana {
protected: 
	string liceu;
public:
	Elev(string Nume, int Varsta, string Liceu)
		:Persoana(Nume, Varsta) {
		this->liceu = Liceu;
	}
};

int main(int argc, char* argv[]) {
	cout << endl << argv[0];
	if (argc == 3) {
		cout << endl << argv[1] << " si " << argv[2];
	}

	Persoana p1("Gigel", 21);
	Student s1;
	Elev e1("Ana", 16, "Sava");

	s1.info();

	Persoana studentiSiElevi[3];
	studentiSiElevi[0] = p1;
	studentiSiElevi[1] = s1;	//up-casting la nivel de obiect
	studentiSiElevi[2] = e1;	//up-casting

	for (int i = 0; i < 3; i++) {
		studentiSiElevi[i].info();
	}
}