#include <string>
#include <iostream>
using namespace std;

class Student {
public:
	const int id;
private:
	string nume = "Anonim";
	int* note = NULL;
	int nrNote = 0;
	int noteFacultative[3] = { 0,0,0 };

	static int contor;
public:
	static const float MEDIE_MINIMA_BURSA;

	//alegem sa nu implementam constructorul default
	//constructor cu parametri
	Student(int Id, const string Nume) :id(Id) {
		this->nume = Nume;
		this->initVectorNoteFacultative();

		Student::contor += 1;
	}

	Student(string Nume, int* note, int nrNote) :id(Student::contor) {
		this->nume = Nume;
		this->transferNote(note, nrNote);
		this->initVectorNoteFacultative();
		Student::contor += 1;
	}



	void transferNote(int* note, int nrNote) {

		this->nrNote = nrNote;
		if (note == NULL)
			throw "Nu exista note de transferat !";

		this->note = new int[nrNote];
		for (int i = 0; i < nrNote; i++)
			this->note[i] = note[i];
	}

	float getMedie() {
		float s = 0;
		for (int i = 0; i < this->nrNote; i++) {
			s += this->note[i];
		}
		if (this->nrNote != 0)
			return s / this->nrNote;
		else
			return 0;
	}

	int getNrNote() {
		return this->nrNote;
	}

	string getNume() {
		return this->nume;
	}

	void afisareStudent() {

		cout << endl << "-------------------------------";

		//afisare Student
		cout << endl << this->id << " cu numele " << this->nume;


		cout << endl << "Note examene obligatorii:";
		for (int i = 0; i < this->nrNote; i++) {
			cout << this->note[i] << " | ";
		}

		cout << endl << "Note examene facultative:";
		for (int i = 0; i < 3; i++) {
			cout << this->noteFacultative[i] << " | ";
		}
	}

	~Student() {
		cout << endl << "Destructor";
		if (this->note != NULL)
			delete[] this->note;
	}

	//constuctor de copiere
	Student(const Student& student):id(Student::contor) {
		cout << endl << "Apel constructor copiere";
		//student.nume = this->nume;
		this->nume = student.nume;
		this->transferNote(student.note, student.nrNote);
		//fara facultative

		Student::contor++;
	}

	operator float() {
		return this->getMedie();
	}

	Student operator+(int nota) {
		Student clona = *this;

		//se adauga nota

		return clona;
	}

private:
	void initVectorNoteFacultative() {
		for (int i = 0; i < 3; i++) {
			this->noteFacultative[i] = 0;
		}
	}

	friend void operator<<(ostream& iesire, Student stud);
};

int Student::contor = 1;
const float Student::MEDIE_MINIMA_BURSA = 8.0;

void oFunctie() {
	int note[] = { 10,10,5 };
	int nrNote = 3;
	Student student("Ioana", note, nrNote);
}

void incaOFunctie(Student student) {

}

Student oAltaFunctie() {
	int note[] = { 10,10,5 };
	int nrNote = 3;
	Student student("Ioana", note, nrNote);
	return student;
}

void operator<<(ostream& iesire, Student stud) {
	iesire << endl << "-------------------------------";

	//afisare Student
	iesire << endl << stud.id << " cu numele " << stud.getNume();


	cout << endl << "Note examene obligatorii:";
	for (int i = 0; i < stud.getNrNote(); i++) {
		cout << stud.note[i] << " | ";
	}

	iesire << endl << "Note examene facultative:";
	for (int i = 0; i < 3; i++) {
		cout << stud.noteFacultative[i] << " | ";
	}
}

//operator float(Student stud) {
//	return stud.getMedie();
//}

int main() {
	//Student student;
	int note[] = { 10,10,5 };
	int nrNote = 3;

	Student student1(1, "Gigel");
	Student student2("Ana", note, nrNote);

	student1.afisareStudent();
	student2.afisareStudent();

	//for (;;) {
	//	oFunctie();
	//}

	incaOFunctie(student2);
	oAltaFunctie();


	//apel constructor copiere
	Student student3 = student2;

	cout << student2; //operator<<(cout, student1)
	//cin >> student1;

	float medie1 = (float)student2;

	//student2 = student2 + 10;	//adaugare note operator+(Student, int)
	//student2 = 10 + student2;

	//student2 += 10;

	//if (!student2) {
	//	cout << endl << "Nu este bursier";
	//}

	//student1 = student2;

	//cout << endl << "Prima nota este " << student2[0];

	//float mediePrimele2Note = student2(2);


}