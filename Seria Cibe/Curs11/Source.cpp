#include <string>
#include <iostream>

using namespace std;

class Persoana {
	int cnp;
	int nume;
};

class Student {
public:
	unsigned int id = 0;
	string nume = "Anonim";
	int note[10];
protected:
	int nrNote = 0;
public:
	Student() {
		cout << endl << "Apel constructor default";
	}

	Student(int id, string nume):id(id), nume(nume) {
		cout << endl << "Apel constructor cu parametri";
	}

	~Student() {
		cout << endl << "Apel destructor";
	}

	Student(const Student& student) {
		cout << endl << "Apel constructor de copiere";
	}

	void salut() {
		cout << endl << "Salut !";
	}

};

//derivare/mostenire
class StudentEvoluat: public Student, public Persoana {
public:
	char gen;
	int noteFacultative[10];
	int nrNoteFacultative;

public:
	StudentEvoluat():Student(0,"Anonim"), Persoana() {
		cout << endl << "Apel constructor default StudentEvoluat";
	}

	StudentEvoluat(int id, string nume, char gen)
		:Student(id, nume) {
		this->gen = gen;
	}

	~StudentEvoluat() {
		cout << endl << "Apel destructor  StudentEvoluat";
	}

	void incrementareNrNote() {
		this->nrNote += 1;
	}
};

int main() {
	//Student student1;
	//student1.salut();
	//Student student2(1, "Ana");
	//Student student3 = student2;
	//student1 = student3;	//apel operator =
	//Student lista[10];
	//Student *lista2 = new Student[10];
	//delete[] lista2;

	//Student **lista3 = new Student*[10];

	StudentEvoluat studentEv;
	studentEv.id =23;
}