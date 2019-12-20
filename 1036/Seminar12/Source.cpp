#include <iostream>
#include <string>
using namespace std;

class PersoanaAbstracta {
protected:
	string nume;
	int varsta;
public:
	PersoanaAbstracta(string NUME, int VARSTA)
		:nume(NUME), varsta(VARSTA) {
	}

	virtual void info() = 0;
	virtual void sustineExamen(string examen) = 0;
	int ceva() {
		cout << endl << "Ceva din Persoana";
	}
	virtual void cevaVirtual() {
		cout << endl << "Ceva virtual din Persoana";
	}
};

class Student : public PersoanaAbstracta {
	string facultate;
public:
	Student(string Nume, int Varsta, string facultate)
		:PersoanaAbstracta("",Varsta){
		this->nume = Nume;
		this->facultate = facultate;
	}

	virtual void info() {
		cout << endl << "Studentul " << this->nume;
		cout << endl << "Are varsta: " << this->varsta;
	}
	virtual void sustineExamen(string examen) {
		cout << endl << this->nume << " sustine examen la "
			<< examen;
	}
};

int main(int argc, char* argv[]) {
	cout << endl << argv[0];
	if (argc == 3) {
		cout << endl << "Primul argument:" << argv[1];
		cout << endl << "Al 2-lea argument:" << argv[2];
		string fisierIntrare = string(argv[1]);
	}
	else
		cout << endl << "Nu am primit alte argumente";

	//PersoanaAbstracta p1("Gigel", 21);
	Student s1("Ana",23,"CSIE");
	Student s2("Gigel",23,"CSIE");

	PersoanaAbstracta* lista[2];
	lista[0] = &s1;
	lista[1] = &s2;

	for (int i = 0; i < 2; i++) {
		lista[i]->sustineExamen("POO");
	}

}
