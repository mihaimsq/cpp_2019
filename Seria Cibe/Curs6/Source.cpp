
#include <string>
#include <iostream>
#include <exception>

using namespace std;

class StudentEvoluat {
private:
	int varsta = 0;
	const int cod = 0;
	char gen = 'N';

	const int numarCI;
public:
	static int nrStudenti;

public:
	//nume
	char prenume[50];
	char *prenumeVariabil = NULL;
	std::string numeFamilie = "Anonim";

private:
	//notele
	int noteExameneObligatorii[12];
	int nrExameneObligatorii = 0;
	int* noteFacultative = NULL;
	int nrFacultative = 0;

public:

	//functii constructor
	//constructor implicit/default

	StudentEvoluat():cod(nrStudenti), numarCI(0) {
		cout << endl << "Apel constructor implicit";
		this->gen = 'N';
		this->varsta = 19;

		strcpy(this->prenume, "Anonim");
		this->prenumeVariabil = new char[strlen("Anonim") + 1];
		strcpy(this->prenumeVariabil, "Anonim");
		this->numeFamilie = "Nu stiu";

		this->nrExameneObligatorii = 0;
		this->noteFacultative = NULL;
		this->nrFacultative = 0;

		nrStudenti += 1;
	}
public:
	//constructor cu parametri
	StudentEvoluat(
		string numeFamilie, const char* prenume, 
		int Cod, int varsta):cod(Cod),numarCI(0) {
		cout << endl << "Apel constructor cu parametri";
		this->gen = 'N';
		this->varsta = varsta;

		strcpy(this->prenume, prenume);
		this->prenumeVariabil = new char[strlen("") + 1];
		strcpy(this->prenumeVariabil, "");
		this->numeFamilie = numeFamilie;

		this->nrExameneObligatorii = 0;
		this->noteFacultative = NULL;
		this->nrFacultative = 0;

		nrStudenti += 1;
	}

	StudentEvoluat(string nume, const char* prenume, 
		int cod, int* note, int nrNote):cod(cod), numarCI(0) {
		this->setNume(nume);
		this->setPrenume(prenume);

		if (nrNote > 12) {
			throw "Prea multe note";
		}
		else
		{
			for (int i = 0; i < nrNote; i++)
				this->noteExameneObligatorii[i] = note[i];
			this->nrExameneObligatorii = nrNote;
		}

		nrStudenti += 1;
	}

	StudentEvoluat(string nume, const char* prenume, const char* prenume2)
		:cod(StudentEvoluat::nrStudenti), numarCI(0) {
		this->setNume(nume);
		this->setPrenume(prenume);
		this->setPrenumeVariabil(prenume2);

		StudentEvoluat::nrStudenti += 1;
	}

	//destructor
	~StudentEvoluat() {
		cout << endl << "Apel destructor";
		if (this->prenumeVariabil != NULL)
			delete[] this->prenumeVariabil;
		if (this->noteFacultative != NULL)
			delete[] this->noteFacultative;
	}

	//constructor copiere
	StudentEvoluat(StudentEvoluat& student):cod(student.cod), 
		numarCI(student.numarCI) {

		cout << endl << "Apel constructor de copiere";
	}

	void setNume(string nume) {
		if (nume.length() >= 2)
			this->numeFamilie = nume;
		else
			throw "Numele este prea scurt";
	}

	void setPrenume(const char* prenume) {
		if (strlen(prenume) >= 2) {
			strcpy(this->prenume, prenume);
		}
		else
			throw "Prenumele este prea scurt";
	}

	void setPrenumeVariabil(const char* prenume) {
		if (strlen(prenume) >= 2) {
			this->prenumeVariabil = new char[strlen(prenume) + 1];
			strcpy(this->prenumeVariabil, prenume);
		}
		else
			throw "Prenumele este prea scurt";
	}

	void modificaVarstaStudentEvoluat(int valoare) {
		if (valoare >= 10 && valoare < 100) {
			this->varsta = valoare;
		}
		else
		{
			throw new std::exception("Valoare gresita pentru varsta !");
		}
	}

	int getVarsta() {
		return this->varsta;
	}


	void afisareStudent() {

		cout << endl << "-------------------------------";

		//afisare Student
		if (this->prenumeVariabil != NULL) {
			std::cout << std::endl << "Nume student: " << this->numeFamilie <<
				" " << this->prenume << " " << this->prenumeVariabil;
		}
		else
			std::cout << std::endl << "Nume student: " << this->numeFamilie <<
			" " << this->prenume;

		std::cout << std::endl << "Varsta student: " << this->varsta;
		std::cout << std::endl << "Cod student: " << this->cod;

		cout << endl << "Note examene obligatorii:";
		for (int i = 0; i < this->nrExameneObligatorii; i++) {
			cout << this->noteExameneObligatorii[i] << " | ";
		}

		cout << endl << "Note examene facultative:";
		for (int i = 0; i < this->nrFacultative; i++) {
			cout << this->noteFacultative[i] << " | ";
		}
	}
};

void faCeva(StudentEvoluat student) {

}

//initializare atribut static din clasa
int StudentEvoluat::nrStudenti = 0;


int main() {

	int note[] = { 10,9,9,7,10 };
	int nrNote = 5;

	StudentEvoluat student1;
	StudentEvoluat student2("Popescu", "Ion", 1, 19);
	StudentEvoluat student3("Ionescu", "Ana", 3, note, nrNote);
	StudentEvoluat student4("Ionescu", "Ana", "Elena");

	StudentEvoluat *pointerStudent;
	pointerStudent = &student1;
	//pointerStudent = new StudentEvoluat();
	pointerStudent = new StudentEvoluat("Anonim","Gigel",2,19);

	student1.afisareStudent();
	student2.afisareStudent();
	student3.afisareStudent();

	cout << endl << "Numar studenti: " << StudentEvoluat::nrStudenti;

	//for (;;) {
	//	StudentEvoluat *pointerStud = 
	//		new StudentEvoluat("Anonim", "Anonim", "Nimic");
	//	delete pointerStud;
	//}

	cout << endl << "Urmeaza Apel constructor de copiere";
	faCeva(student4);
}