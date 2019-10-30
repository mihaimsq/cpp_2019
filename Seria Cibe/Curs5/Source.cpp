
#include <string>
#include <iostream>
#include <exception>

using namespace std;

struct Student {
	int varsta;
	int cod;
	char gen;

	//nume
	char prenume[50];
	char *prenumeVariabil;
	std::string numeFamilie;

	//notele
	int noteExameneObligatorii[12];
	int nrExameneObligatorii;
	int* noteFacultative;
	int nrFacultative;
};

class StudentEvoluat {
private:
	int varsta;
	int cod;
	char gen;

public:
	//nume
	char prenume[50];
	char *prenumeVariabil;
	std::string numeFamilie;

private:
	//notele
	int noteExameneObligatorii[12];
	int nrExameneObligatorii;
	int* noteFacultative;
	int nrFacultative;

public:

	//functii constructor

	//constructor implicit/default

private:
	StudentEvoluat() {
		cout << endl << "Apel constructor implicit";
		this->cod = 0;
		this->gen = 'N';
		this->varsta = 19;

		strcpy(this->prenume, "Anonim");
		this->prenumeVariabil = new char[strlen("Anonim") + 1];
		strcpy(this->prenumeVariabil, "Anonim");
		this->numeFamilie = "Nu stiu";

		this->nrExameneObligatorii = 0;
		this->noteFacultative = NULL;
		this->nrFacultative = 0;
	}
public:
	//constructor cu parametri
	StudentEvoluat(string numeFamilie, const char* prenume, int cod, int varsta) {
		cout << endl << "Apel constructor cu parametri";
		this->cod = cod;
		this->gen = 'N';
		this->varsta = varsta;

		strcpy(this->prenume, prenume);
		this->prenumeVariabil = new char[strlen("") + 1];
		strcpy(this->prenumeVariabil, "");
		this->numeFamilie = numeFamilie;

		this->nrExameneObligatorii = 0;
		this->noteFacultative = NULL;
		this->nrFacultative = 0;
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
		//afisare Student
		std::cout << std::endl << "Nume student: " << this->numeFamilie <<
			" " << this->prenume << " ";
		std::cout << std::endl << "Varsta student: " << this->varsta;
		std::cout << std::endl << "Cod student: " << this->cod;
	}
};

void modificaVarsta(int valoare, Student& student) {
	if (valoare >= 10 && valoare < 100) {
		student.varsta = valoare;
		//pentru varianta cu Student* student
		//(*student).varsta = valoare;
		//student->varsta = valoare;
	}
	else
	{
		throw new std::exception("Valoare gresita pentru varsta !");
	}
}



void afisareStudent(Student stud) {
	//afisare Student
	std::cout << std::endl << "Nume student: " << stud.numeFamilie <<
		" " << stud.prenume << " ";
	std::cout << std::endl << "Varsta student: " << stud.varsta;
	std::cout << std::endl << "Cod student: " << stud.cod;
}

int main() {
	//Student student1;
	//Student student2;

	////modificaVarsta(23, student2);
	//student2.varsta = -23;

	////va genera eroare
	////modificaVarsta(-23, student2);

	//afisareStudent(student2);

	//std::cout << std::endl << "Nume student: ";
	//student1.numeFamilie;
	//std::cout << std::endl << "Varsta student: ";
	//student1.varsta;

	//StudentEvoluat studentEv3;
	StudentEvoluat studentEv1("Ionescu", "Ana", 2, 19);
	StudentEvoluat studentEv2("Popescu","Ion",1,19);

	studentEv1.afisareStudent();
	studentEv2.afisareStudent();

	//NU se poate accesa
	//studentEv1.varsta = -23;

	studentEv1.modificaVarstaStudentEvoluat(23);

	std::cout << std::endl << "Nume student: " << studentEv1.numeFamilie;
	std::cout << std::endl << "Varsta student: " << studentEv1.getVarsta();
	std::cout << std::endl << "Varsta student 2: " << 
		studentEv2.getVarsta();
}