#include <iostream>
#include <string>

using namespace std;

class Student {
protected:
	string nume = "";
protected:
	int varsta = 0;
	int noteObligatorii[15];
	int nrNote = 0;
	int* campDinamic = NULL;

//private:
//	Student() {
//		cout << endl << "Apel constructor default Student";
//	}
public:
	Student(string nume, int varsta)
	:nume(nume), varsta(varsta){
		cout << endl << "Apel constructor cu parametri Student";
		this->campDinamic = new int[5];
	}

	~Student() {
		cout << endl << "Apel destructor Student";
		delete[] campDinamic;
	}

	Student(const Student& s) {
		cout << endl << "Apel constructor copiere Student";
		this->campDinamic = new int[5];
	}

	void sustineExamen() {

	}

};

class StudentEvoluat: public Student {
	char gen;
	int inaltime;

public:
	void functieStudentEvoluat() {
		this->varsta = 0;
		this->nrNote = 0;
	}

	StudentEvoluat():Student("Anonim", 23) {
		cout << endl << "Apel constructor default StudentEvoluat";
	}

	StudentEvoluat(string nume, int varsta, char gen)
	:Student(nume,varsta){
		this->gen = gen;
	}

	~StudentEvoluat() {
		cout << endl << "Apel destructor StudentEvoluat";
	}
};

class Test {
};

int main() {

	//Student studenti[5];
	//Student s;
	//s.sustineExamen();

	StudentEvoluat se;
	//se.sustineExamen();
	//se.varsta = 0;

	//Test t;

}