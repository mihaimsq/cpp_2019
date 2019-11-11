#include <string>
#include <iostream>
using namespace std;

class Student {
public:
	const int nrMatricol;
	std::string nume = "Anonim";
private:
	char* facultate = NULL;
	int *note = NULL;
	int nrNote = 0;

	static int nrMatricolCurent;
	static float medieMinimaBursa;

public:
	Student():nrMatricol(nrMatricolCurent) {
		Student::nrMatricolCurent += 1;
	}

	Student(string nume, const char* facultate,
		int* note, int nrNote):nrMatricol(nrMatricolCurent++) {
		this->nume = nume;
		this->facultate = new char[strlen(facultate) + 1];
		strcpy(this->facultate, facultate);

		this->note = new int[nrNote];
		for (int i = 0; i < nrNote; i++) {
			this->note[i] = note[i];
		}
		this->nrNote = nrNote;
	}

	//destructorul
	~Student() {
		cout << endl << "Apel destructor";
		if (this->note != NULL)
			delete[] this->note;
		if (this->facultate != NULL)
			delete[] this->facultate;
	}

	//constructor copiere
	Student(Student& student):nrMatricol(student.nrMatricol) {
		cout << endl << "Apel constructor de copiere";
		this->nume = student.nume;
		//NU ASA
		//this->facultate = student.facultate;

		this->facultate = new char[strlen(student.facultate) + 1];
		strcpy(this->facultate, student.facultate);

		this->note = new int[student.nrNote];
		for (int i = 0; i < student.nrNote; i++) {
			this->note[i] = student.note[i];
		}
		this->nrNote = student.nrNote;
	}

	void afisare() {
		cout << endl << "--------------------";
		cout << endl << this->nrMatricol << " - " << this->nume;
		if (this->facultate != NULL)
			cout << endl << "Facultate " << this->facultate;
		if (this->note != NULL) {
			cout << endl << "Note: ";
			for (int i = 0; i < this->nrNote; i++)
				cout << this->note[i] << " | ";
		}
	}

	float getMedie() {
		if (this->note != NULL) {
			float suma = 0;
			for (int i = 0; i < this->nrNote; i++)
				suma += this->note[i];
			return suma / this->nrNote;
		}
		else
			return 0;
	}

	bool esteBursier() {
		if (this->getMedie() >= Student::medieMinimaBursa)
			return true;
		else
			return false;
	}
};

int Student::nrMatricolCurent = 1;
float Student::medieMinimaBursa = 8.0;

void oFunctie() {
	int note[] = { 10,10,9 };
	int nrNote = 3;
	Student("Ionel", "MAN", note, nrNote);
}

void oAltaFunctie(Student student) {

}


int main() {
	
	int note[] = { 10,10,9 };
	int nrNote = 3;

	Student student1;
	Student student2("Gigel", "CSIE", note, nrNote);
	Student student3("Ana", "MK", note, nrNote);

	student1.afisare();
	student2.afisare();
	student3.afisare();

	cout << endl << "Media Anei este " << student3.getMedie();
	if (student3.esteBursier())
		cout << endl << "Are bursa";

	Student *pointerStudent;
	pointerStudent = &student2;
	pointerStudent->afisare();

	pointerStudent = new Student("Ionel", "MAN", note, nrNote);
	pointerStudent->afisare();
	delete pointerStudent;

	//test pentru memory-leak pe destructor
	//for (;;) {
	//	//pointerStudent = new Student("Ionel", "MAN", note, nrNote);
	//	//delete pointerStudent;
	//	oFunctie();
	//}

	oAltaFunctie(student2);

}