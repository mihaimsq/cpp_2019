
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class StudentEvoluat {
public:
	char nume[50];
private:
	int varsta = 0;
public:
	const int nrMatricol;
	char gen = 'N';
private:
	int noteExameneObligatorii[18];
	int nrDisciplineObligatorii = 0;

	int *noteExameneFacultative = NULL;
	int nrDisciplineFacultative = 0;

	static int nrStudenti;
	static int NOTA_MAXIMA;
public:

	const int test;

	//constructori


private:
	//constructor default/implicit/fara parametri
	StudentEvoluat():nrMatricol(0),test(0) {
		//NU MERGE
		//this->nrMatricol = 0;
		cout << endl << " Salut ! Exist !";
		strcpy(this->nume, "Anonim");

		nrStudenti += 1;
	}


public:
	//constructor cu parametri
	StudentEvoluat(const char* nume, int id): nrMatricol(id), test(0) {
		cout << endl << " Constructor ce primeste numele studentului";
		strcpy(this->nume, nume);
		StudentEvoluat::nrStudenti += 1;
	}

	StudentEvoluat(const char* nume, 
		int varsta, int nrMatricol):nrMatricol(nrMatricol), test(0) {
		cout << endl << " Constructor ce primeste numele studentului";
		strcpy(this->nume, nume);
		//shadowing
		//varsta = varsta;
		this->varsta = varsta;

		StudentEvoluat::nrStudenti += 1;
	}

	StudentEvoluat(const char* nume, 
		int* noteFaculative, int nrNote):nrMatricol(nrStudenti), test(0) {
		strcpy(this->nume, nume);
		this->nrDisciplineFacultative = nrNote;

		this->noteExameneFacultative = new int[nrNote];
		for (int i = 0; i < nrNote; i++)
			this->noteExameneFacultative[i] = noteFaculative[i];

		StudentEvoluat::nrStudenti += 1;
	}

	~StudentEvoluat() {
		cout << endl << "Apel destructor";
		if (this->noteExameneFacultative != NULL) {
			delete[] this->noteExameneFacultative;
		}
	}

	//constructor de copiere
	StudentEvoluat(StudentEvoluat& student)
		:nrMatricol(student.nrMatricol), test(0) {
		//this->noteExameneFacultative = student.noteExameneFacultative;
	

		this->noteExameneFacultative = new int[student.nrDisciplineFacultative];
		this->nrDisciplineFacultative = student.nrDisciplineFacultative;
		for (int i = 0; i < this->nrDisciplineFacultative; i++)
			this->noteExameneFacultative[i] = student.noteExameneFacultative[i];

	
	}

	int getVarsta() {
		return this->varsta;
	}

	void setVarsta(int valoare) {
		if (valoare >= 10 && valoare <= 90)
			this->varsta = valoare;
		else
			throw new exception("VARSTA e gresita !!!!!!!!");
	}

	void printDate() {
		cout << endl << " --------------------------- ";
		cout << endl << "Nume: " << this->nume;
		cout << endl << "Varsta: " << this->varsta;
		cout << endl << "Gen: " << this->gen;
		cout << endl << "Nr matricol: " << this->nrMatricol;
		cout << endl << "Note examene obligatorii";
		for (int i = 0; i < this->nrDisciplineObligatorii; i++) {
			cout << this->noteExameneObligatorii[i] << " | ";
		}

		if (this->noteExameneFacultative == NULL) {
			cout << endl << "Nu sunt note pentru facultative";
		}
		else {
			cout << endl << "Note examene facultative";
			for (int i = 0; i < this->nrDisciplineFacultative; i++) {
				cout << this->noteExameneFacultative[i] << " | ";
			}
		}
	}
};

int StudentEvoluat::nrStudenti = 0;
int StudentEvoluat::NOTA_MAXIMA = 10;

void nuFaceCeva(StudentEvoluat student) {

}

int main() {

	StudentEvoluat student1("Gigel",1);
	StudentEvoluat student2("Ana", 19,2);


	int noteFacultative[] = { 19,9,8 };
	int nrNote = 3;
	StudentEvoluat student3("Ionel", noteFacultative, nrNote);

	//student1.nrMatricol = 1;

	student1.printDate();
	student2.printDate();
	student3.printDate();

	

	//for (;;) {
	//	StudentEvoluat *pointerStudent;
	//	//pointerStudent = &student2;
	//	int noteFacultative[] = { 10,9,8 };
	//	int nrNote = 3;
	//	pointerStudent = 
	//		new StudentEvoluat("Ioana",noteFacultative,nrNote);
	//	delete pointerStudent;
	//}

	nuFaceCeva(student3);

}