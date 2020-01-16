#include <iostream>
#include <string>

using namespace std;

class Facultate {
	string denumire;
	string adresa;
public:
	Facultate(string Denumire, string Adresa) {
		adresa = Adresa;
		denumire = Denumire;
	}
};

class Nota {
	int valoare;
	string curs;
public:
	string getCurs() {
		return this->curs;
	}

	int getValoare() {
		return this->valoare;
	}
};

class Student {
	Facultate facultate;
	Nota note[10];
	Nota* noteFacultative;
	int nrNoteFacultative;
public:
	Student() :facultate("CSIE", "Calea Dorobanti") {
		noteFacultative = NULL;
		nrNoteFacultative = 0;
	}

	Student(string numeFacultate,
		string adresaFacultate)
		:facultate(numeFacultate,adresaFacultate) {
		noteFacultative = NULL;
		nrNoteFacultative = 0;
	}

	Student(Facultate facultatePrimita)
		:facultate(facultatePrimita) {
		noteFacultative = NULL;
		nrNoteFacultative = 0;
	}

	Student(Facultate facultate, Nota* note,
		int nrNote) :facultate(facultate) {
		this->noteFacultative = new Nota[nrNote];
		for (int i = 0; i < nrNote; i++) {
			this->noteFacultative[i] = note[i];
			this->nrNoteFacultative = nrNote;
		}
	}

	Nota getNotaFacultativa(int indexNota) {
		if (indexNota < 0
			&& indexNota >= nrNoteFacultative) {
			throw new exception("Index gresit");
		}
		else
			return noteFacultative[indexNota];
	}

	int getNrNote() {
		return this->nrNoteFacultative;
	}
};

int main() {
	Student s1;
	Facultate csie("CSIE", "Bucuresti");
	Student s2(csie);

	for (int i = 0; i < s2.getNotaFacultativa; i++) {
		try {
			cout << endl << "Nota este" <<
				s2.getNotaFacultativa(i).getValoare();
		}
	}
}