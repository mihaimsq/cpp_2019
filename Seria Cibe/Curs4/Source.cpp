
#include <string>
#include <iostream>

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
	int* noteFacultative;
	int nrFacultative;

	//adresa
	std::string adresa;
};

class StudentEvoluat {
private:
	int varsta;
public:
	const int cod;
	char gen;
public:
	//nume
	char prenume[50];
	char *prenumeVariabil;
	std::string numeFamilie;
private:
	//notele
	int noteExameneObligatorii[12];
	int* noteFacultative;
	int nrFacultative;

	//adresa
	std::string adresa;

	//numar studenti din facultate - variabila statica
	static int nrStudenti;


};

void modificaVarsta(int valoare, Student student) {
	//validari
}

void afisareStudent(Student stud) {
	//afisare Student
	std::cout << std::endl << "Nume student: ";
	stud.numeFamilie;
	std::cout << std::endl << "Varsta student: ";
	stud.varsta;
	std::cout << std::endl << "Cod student: ";
	stud.cod;
}

int main() {
	Student student1;
	Student student2;

	modificaVarsta(23, student2);
	student2.varsta = 23;

	std::cout << std::endl << "Nume student: ";
	student1.numeFamilie;
	std::cout << std::endl << "Varsta student: ";
	student1.varsta;

	afisareStudent(student2);

	StudentEvoluat stud1;

	std::cout << std::endl << "Nume student (obiect): ";
	stud1.numeFamilie;
	//std::cout << std::endl << "Varsta student (obiect): ";
	//stud1.varsta;


}