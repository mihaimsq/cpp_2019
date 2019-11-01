
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
	int nrMatricol = 0;
	char gen = 'N';
private:
	int noteExameneObligatorii[18];
	int nrDisciplineObligatorii = 0;

	int *noteExameneFacultative = NULL;
	int nrDisciplineFacultative = 0;
public:

	//constructori
	

private:
	//constructor default/implicit/fara parametri
	StudentEvoluat() {
		cout << endl << " Salut ! Exist !";
		strcpy(this->nume, "Anonim");
	}


public:
	//constructor cu parametri
	StudentEvoluat(const char* nume) {
		cout << endl << " Constructor ce primeste numele studentului";
		strcpy(this->nume, nume);
	}

	StudentEvoluat(const char* nume, int varsta) {
		cout << endl << " Constructor ce primeste numele studentului";
		strcpy(this->nume, nume);
		//shadowing
		//varsta = varsta;
		this->varsta = varsta;
	}

	StudentEvoluat(const char* nume, int* noteFaculative, int nrNote) {
		strcpy(this->nume, nume);
		this->nrDisciplineFacultative = nrNote;

		this->noteExameneFacultative = new int[nrNote];
		for (int i = 0; i < nrNote; i++)
			this->noteExameneFacultative[i] = noteFaculative[i];
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


int main() {

	//instantiere
	//crearea unui obiect
	StudentEvoluat obiectStudent("Nu stiu");
	StudentEvoluat student1("Gigel");

	int noteTest[] = { 10,10,9,10 };
	int nrNote = 4;

	StudentEvoluat student2("Ana",noteTest,nrNote);

	//strcpy(obiectStudent.nume, "Gigel");
	//obiectStudent.gen = 'M';
	////obiectStudent.varsta = -19;

	//obiectStudent.setVarsta(19, obiectStudent);
	//cout << endl <<
	//	"Varsta obiect student :" << obiectStudent.getVarsta(obiectStudent);

	student1.setVarsta(23);
	student2.setVarsta(22);

	cout << endl << "Varsta student 1 = "
		<< student1.getVarsta();
	cout << endl << "Varsta student 2 = "
		<< student2.getVarsta();

	//TE ROG NU UITA SA MODIFICI NUMELE - E Anonim

	student1.printDate();
	student2.printDate();
}