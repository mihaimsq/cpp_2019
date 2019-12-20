#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>

using namespace std;

class PersoanaAbstracta {
public: 
	virtual void oFunctie(int vb, char t) = 0;
};

class Persoana: public PersoanaAbstracta {
protected:
	string nume = "Anonim";
	int varsta = 0;
public:
	Persoana() {
		cout << endl << "Constructor default Persoana";
	}
	Persoana(string nume, int varsta)
		:nume(nume), varsta(varsta) {
		cout << endl << "Constructor cu parametri Persoana";
	}
	~Persoana() {
		cout << endl << "Destructor Persoana";
	}

	virtual void info() {
		cout << endl << this->nume << " are varsta "
			<< this->varsta;
	}

	virtual void oFunctie(int vb, char t) {

	}
};

class Student : public Persoana {
	string facultate = "CSIE";
public:
	//Student() :Persoana() {
	//	cout << endl << "Constructor default Student";
	//}
	Student(string nume, int varsta, string facultate)
		:Persoana(nume, varsta) {
		this->facultate = facultate;
		cout << endl << "Constructor cu parametri Student";
	}
	Student(string facultate):Persoana("Student Anonim", 14) {
		this->facultate = facultate;
		cout << endl << "Constructor cu parametri Student";
	}

	~Student() {
		cout << endl << "Destructor Student";
	}

	/*void infoStudent() {
		this->info();
		cout << " si este student(a) la " << this->facultate;
	}*/

	//supradefinire - overriding
	//se redefineste o functie mostenita
	void info() {
		this->Persoana::info();	//apelez versiunea din Persoana
		cout << " si este student(a) la " << this->facultate;
	}

	//supraincarcare - overloading
	void ceva() {

	}
	void ceva(int a, int b) {

	}
	void ceva(string vb, float c) {

	}
};

class Masterand: public Student {
protected:
	string masterat = "IE";
public:
	Masterand():Student("Masterand Anonim",16,"CSIE"){
		cout << endl << "Constructor default Masterand";
	}
	Masterand(string Nume, int Varsta,
		string Facultate, string Masterat)
		:Student(Nume,Varsta,Facultate) {
		this->masterat = Masterat;
		cout << endl << "Constructor cu parametri Masterand";
	}

	~Masterand() {
		cout << endl << "Destructor Masterand";
	}

	void info() {
		this->Student::info();	//apelez versiunea din Persoana
		cout << endl <<" Inmatriculat(a) la programul de masterat " << this->masterat;
	}
};


int main() {
	Persoana p1;
	Persoana p2("Gigel", 21);
	Student s1("Ana",21,"MAN");
	Masterand m1("Ionel",21,"CSIE","Cibernetica");

	//m1 = p1;		//down-casting - NU este permis

	//Persoana lista[4];
	//lista[0] = p1;
	//lista[1] = p2;
	//lista[2] = s1;		//up-casting
	//lista[3] = m1;		//up-casting

	Persoana* lista[4];
	lista[0] = &p1;
	lista[1] = &p2;
	lista[2] = &s1;		//up-casting
	lista[3] = &m1;		//up-casting

	cout << endl << "----------------------------";
	for (int i = 0; i < 4; i++) {
		//late-biding cand functia este virtuala
		lista[i]->info();		//early-binding fara virtual
		//lista[i]->vtptr[0]();
	}
	cout << endl << "----------------------------";
}