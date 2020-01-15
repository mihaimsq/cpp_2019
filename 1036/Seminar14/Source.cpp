#include <iostream>
#include <string>
using namespace std;

class Facultate {
	string denumire;
	string adresa;
public:
	Facultate(string Denumire, string Adresa) {
		this->denumire = Denumire;
		this->adresa = Adresa;
	}
};

class Nota {
	int valoare;
	string disciplina;
public:
	void setNota(int valoare) {
		this->valoare = valoare;
	}

	void setDisciplina(string Disciplina) {
		this->disciplina = Disciplina;
	}

	int getNota() {
		return valoare;
	}
};

class Student {
	Facultate facultate;
	Nota *note = NULL;
	int nrNote = 0;
	int id = 0;
public:
	Student():facultate("CSIE","Calea Dorobant") {
		id = 0;
		note = NULL;
		nrNote = 0;
	}

	Student(string numeFacultate, string adresaFacultate)
		:facultate(numeFacultate,adresaFacultate) {
		id = 0;
		note = NULL;
		nrNote = 0;
	}

	Student(int Id, Facultate facultate,
		Nota* note, int nrNote):facultate(facultate) {
		this->id = Id;
		this->note = new Nota[nrNote];
		for (int i = 0; i < nrNote; i++)
			this->note[i] = note[i];
		this->nrNote = nrNote;
	}

	bool operator!() {
		bool esteIntegralist = true;
		if (this->nrNote == 0)
			return esteIntegralist;
		for (int i = 0; i < nrNote; i++) {
			if (this->note[i].getNota() < 5) {
				esteIntegralist = false;
			}
		}

		return esteIntegralist;
	}

};

class Test {
	int valoare;
public:
	virtual void ceva() = 0;

};

class Test2 :public Test {

};

int main() {

	Nota *note = new Nota[3];
	note[0].setNota(10);
	note[0].setDisciplina("POO");
	note[1].setNota(10);
	note[1].setDisciplina("BD");
	note[2].setNota(4);
	note[2].setDisciplina("Drept");

	Facultate f1("MAN", "Str Eminescu");

	Student s1("CSIE", "Calea Dorobanti");
	Student s2(1,f1,note,3);

	if (!s2)
		cout << endl << "Studentul este integralist";
	else
		cout << endl << "Are cel putin o restanta";


}