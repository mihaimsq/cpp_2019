
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

struct Student {
	char nume[50];
	int varsta;
	int nrMatricol;
	char gen;

	int noteExameneObligatorii[18];
	int nrDisciplineObligatorii;

	int *noteExameneFacultative;
	int nrDisciplineFacultative;
};

class StudentEvoluat {
public:
	char nume[50];
private:
	int varsta;
public:
	int nrMatricol;
	char gen;
private:
	int noteExameneObligatorii[18];
	int nrDisciplineObligatorii;

	int *noteExameneFacultative;
	int nrDisciplineFacultative;
public:
	int getVarsta(StudentEvoluat stud) {
		return stud.varsta;
	}

	void setVarsta(int valoare, StudentEvoluat& stud) {
		if (valoare >= 10)
			stud.varsta = valoare;
		else
			throw new exception("VARSTA e gresita !!!!!!!!");
	}
};

void setVarsta(int valoare, Student& stud) {
	if (valoare >= 10)
		stud.varsta = valoare;
	else
		throw new exception("VARSTA e gresita !!!!!!!!");
}

void afisareStudent(Student s) {
	cout << endl << "Nume " << s.nume;
	cout << endl << "Gen " << s.gen;
	cout << endl << "Varsta " << s.varsta;
}

int main(){
	Student student;
	//student.nume = "Gigel";
	strcpy(student.nume, "Gigel");
	student.gen = 'M';
	student.varsta = -19;
	//setVarsta(-19, student);

	afisareStudent(student);

	StudentEvoluat obiectStudent;
	strcpy(obiectStudent.nume, "Gigel");
	obiectStudent.gen = 'M';
	//obiectStudent.varsta = -19;
	obiectStudent.setVarsta(19, obiectStudent);
	cout << endl << 
		"Varsta obiect student :" << obiectStudent.getVarsta(obiectStudent);


	string a = "Gigel";
	a = a + " test";
	cout << endl << a;
}