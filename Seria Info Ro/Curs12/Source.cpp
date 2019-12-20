#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;


class PersoanaAbstracta {
public:
	virtual void theOriginalPrint(int a) = 0;
};
class Persoana: public PersoanaAbstracta {
protected:
	string nume = "Anonim";
	int varsta = 0;
public:
	Persoana() {
		cout << endl << "Apel dafault Persoana";
	}
	Persoana(string Nume, int Varsta) {
		this->nume = Nume;
		varsta = Varsta;
		cout << endl << "Apel constructor cu parametri Persoana";
	}
	~Persoana(){
		cout << endl << "Apel destructor Persoana";
	}
	virtual void print() {
		cout << endl << this->nume << " are varsta " << this->varsta;
	}

	virtual void theOriginalPrint(int a) {
		cout << endl << "ceva";
	}
};

class Student : public Persoana {
protected:
	string facultate = "CSIE";
public:
	Student(string nume, int varsta, string Facultate)
		: Persoana(nume,varsta) {
		facultate = Facultate;
		cout << endl << "Apel constructor cu parametri Student";
	}

	~Student() {
		cout << endl << "Apel destructor Student";
	}

	//supradefinire - overriding
	void print() {
		//cout << endl << this->nume << " are varsta " << this->varsta;
		this->Persoana::print();
		cout << endl << "Este student(a) la facultatea " << facultate;
	}

	//supraincarcare - overloading
	void ceva() {

	}

	void ceva(int a) {

	}

	void ceva(string a) {

	}

	void printStudent() {
		this->print();
		cout << endl << "Este student(a) la facultatea " << facultate;
	}
};

class Masterand : public Student {
protected:
	string masterat = "";
public:
	Masterand() : Student("Masterand anonim", 18, "CSIE") {
		cout << endl << "Apel dafault Masterand";
	}
	Masterand(string nume, int varsta,
		string facultate, string masterat): 
		Student(nume,varsta,facultate) {
		this->masterat = masterat;
		cout << endl << "Apel constructor cu parametri Masterand";
	}
	~Masterand() {
		cout << endl << "Apel destructor Masterand";
	}

	void printMasterand() {
		this->print();
		cout << endl << "Este masterand(a) la " << masterat;
	}

	void Print() {
		//cout << endl << this->nume << " are varsta " << this->varsta;
		this->Student::print();
		cout << endl << "Este masterand(a) la " << masterat;
	}
};

int main(int argc, char* argv[]) {
	Persoana p1;				//cd pers
	Persoana p2("Gigel", 21);	//cp pers
	//p1.print();
	//p2.print();
	Student s1("Ana",21,"CSIE");	//cp pers, cp stud
	Masterand m1("Ionel",23,"CSIE","Info");					//cp pers, cp stud, cd mast	

	//m1 = s1;		//down-casting
	///s1 = m1;		//up-casting

	s1.print();

	//Persoana lista[4];
	//lista[0] = p1;
	//lista[1] = p2;
	//lista[2] = s1;
	//lista[3] = m1;


	Persoana* lista[4];
	lista[0] = &p1;
	lista[1] = &p2;
	lista[2] = &s1;
	lista[3] = &m1;

	cout << endl << "-----------------------";
	for (int i = 0; i < 4; i++) {
		lista[i]->print();		//early-binding
		//lista[i]->vtptr[0]();	//late-binding
	}
	cout << endl << "-----------------------";


}