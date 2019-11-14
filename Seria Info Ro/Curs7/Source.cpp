
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

public:
	const static int NOTA_MAXIMA;
	const int test;

	//constructori


private:
	//constructor default/implicit/fara parametri
	StudentEvoluat() :nrMatricol(0), test(0) {
		//NU MERGE
		//this->nrMatricol = 0;
		cout << endl << " Salut ! Exist !";
		strcpy(this->nume, "Anonim");

		nrStudenti += 1;
	}


public:
	//constructor cu parametri
	StudentEvoluat(const char* nume, int id) : nrMatricol(id), test(0) {
		cout << endl << " Constructor ce primeste numele studentului";
		strcpy(this->nume, nume);
		StudentEvoluat::nrStudenti += 1;
	}

	StudentEvoluat(const char* nume,
		int varsta, int nrMatricol) :nrMatricol(nrMatricol), test(0) {
		cout << endl << " Constructor ce primeste numele studentului";
		strcpy(this->nume, nume);
		//shadowing
		//varsta = varsta;
		this->varsta = varsta;

		StudentEvoluat::nrStudenti += 1;
	}

	StudentEvoluat(const char* nume,
		int* noteFaculative, int nrNote) :nrMatricol(nrStudenti), test(0) {
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

		this->gen = student.gen;
		strcpy(this->nume,student.nume);
		this->varsta = student.varsta;

		for (int i = 0; i < student.nrDisciplineObligatorii; i++) {
			this->noteExameneObligatorii[i] =
				student.noteExameneObligatorii[i];
		}
		this->nrDisciplineObligatorii = student.nrDisciplineObligatorii;

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

	void adaugaNotaFacultativa(int nota) {
		if (nota > 0 && nota <= StudentEvoluat::NOTA_MAXIMA) {
			int* note = new int[this->nrDisciplineFacultative + 1];
			for (int i = 0; i < this->nrDisciplineFacultative; i++) {
				note[i] = this->noteExameneFacultative[i];
			}
			note[this->nrDisciplineFacultative] = nota;
			this->nrDisciplineFacultative += 1;

			//evitam un memory leak
			delete[] this->noteExameneFacultative;
			this->noteExameneFacultative = note;
		}
		else
			throw "Nota un e ok";
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

	//sfarsit clasa
	StudentEvoluat operator+(int notaNoua) {
		StudentEvoluat copie = *this;
		copie.adaugaNotaFacultativa(notaNoua);
		return copie;
	}

	operator float() {
		float s = 0;
		for (int i = 0; i < this->nrDisciplineFacultative; i++) {
			s += this->noteExameneFacultative[i];
		}
		if (this->nrDisciplineFacultative != 0)
			return s / this->nrDisciplineFacultative;
		else
			return 0;


	}


	friend void operator<<(ostream& out, StudentEvoluat stud);

};

int StudentEvoluat::nrStudenti = 0;
const int StudentEvoluat::NOTA_MAXIMA = 10;

void operator<<(ostream& out, StudentEvoluat stud) {
	out << endl << " --------------------------- ";
	out << endl << "Nume: " << stud.nume;
	out << endl << "Varsta: " << stud.getVarsta();
	out << endl << "Gen: " << stud.gen;
	out << endl << "Nr matricol: " << stud.nrMatricol;
	out << endl << "Note examene obligatorii";
	for (int i = 0; i < stud.nrDisciplineObligatorii; i++) {
		out << stud.noteExameneObligatorii[i] << " | ";
	}

	if (stud.noteExameneFacultative == NULL) {
		out << endl << "Nu sunt note pentru facultative";
	}
	else {
		out << endl << "Note examene facultative";
		for (int i = 0; i < stud.nrDisciplineFacultative; i++) {
			out << stud.noteExameneFacultative[i] << " | ";
		}
	}
}

void nuFaceCeva(StudentEvoluat student) {

}

StudentEvoluat oFunctie() {
	int noteFacultative[] = { 19,9,8 };
	int nrNote = 3;
	StudentEvoluat student("Ionel", noteFacultative, nrNote);
	return student;
}

int main() {

	StudentEvoluat student1("Gigel", 1);
	StudentEvoluat student2("Ana", 19, 2);


	int noteFacultative[] = { 19,9,8 };
	int nrNote = 3;
	StudentEvoluat student3("Ionel", noteFacultative, nrNote);

	//student1.nrMatricol = 1;

	student1.printDate();
	student2.printDate();

	student3.adaugaNotaFacultativa(10);

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

	//nuFaceCeva(student3);
	//oFunctie();

	//apel constructor copiere
	StudentEvoluat clona = student3;

	int vb1 = 10;
	int vb2 = vb1 + 10;		//int operator+(int, int)

	cout << student3;		//void operator<<(ostream&,StudentEvoluat)
	cin >> clona;			//void operator>>(istream&,StudentEvoluat)

	cout << clona;

	clona = clona + 10;		//StudentEvoluat operator+(StudentEvoluat, int)
	clona = 10 + clona;		//StudentEvoluat operator+(int, StudentEvoluat)
	clona += 9;				//void operator+=(StudentEvoluat, int)

	clona = student3 * 3;	//operator*

	float medie = (float)clona;		//operator float(StudentEvoluat)

	float mediePrimele3Note = clona(3);	//float operator(StudentEvoluat, int)

	int nota = clona[0];		//int operator[](StudentEvoluat, int)

	if (!student3) {			//bool operator!(StudentEvoluat)
		cout << endl << "Studentul este restantier";
	}
	
	clona = student3++;	//incrementeaza varsta StudentEvoluat operator++(StudentEvoluat, int)
	clona = ++student3;		//StudentEvoluat operator++(StudentEvoluat)

	student3--;	//sterge ultima nota facultativa

	clona = student3;		//void operator=(StudentEvoluat,StudentEvoluat)

}