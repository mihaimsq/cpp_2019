#include <string>
#include <iostream>
#include <fstream>
using namespace std;


class ListaStudenti {
public:
	Student* studenti = NULL;
	int nrStudenti = 0;
};

class Exceptie {
	string mesaj;
public:
	Exceptie(string mesaj) {
		this->mesaj = mesaj;
	}

	string getMesaj() {
		return this->mesaj;
	}
};
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


private:
	Student():id(0) {

	}
public:
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
			//throw "Nu exista note de transferat !";
			//throw - 1;
			//throw Exceptie("Am primit 0 note");
			//throw new Exceptie("Am primit 0 note");
			throw new exception("Am primit 0 note");
		if (nrNote != 0) {
			this->note = new int[nrNote];
			for (int i = 0; i < nrNote; i++)
				this->note[i] = note[i];
		}
		else
		{
			this->nrNote = 0;
			this->note = NULL;
		}
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

	~Student() {
		cout << endl << "Destructor";
		if (this->note != NULL)
			delete[] this->note;
	}

	//constuctor de copiere
	Student(const Student& student) :id(Student::contor) {
		cout << endl << "Apel constructor copiere";
		//student.nume = this->nume;
		this->nume = student.nume;
		//if (student.note != NULL) {
		//	this->transferNote(student.note, student.nrNote);
		//}
		//else
		//{
		//	this->note = NULL;
		//	this->nrNote = 0;
		//}

		try {
			cout << endl << "incerc sa transfer notele pentru " << student.nume;
			this->transferNote(student.note, student.nrNote);
			cout << endl << "Am reusit sa transfer notele";
		}

		catch (const char* err) {
			cout << endl << "Ai incercat sa transferi 0 note";
			cout << endl << "Mesaj: " << err;

			this->note = NULL;
			this->nrNote = 0;
		}
		catch (int err) {
			cout << endl << "Ai incercat sa transferi 0 note";
			cout << endl << "Cod eroare: " << err;
		}
		catch (Exceptie ex) {
			cout << endl << "Mesaj eroare: " << ex.getMesaj();
		}
		catch (Exceptie* ex) {
			cout << endl << "Mesaj eroare: " << ex->getMesaj();
		}
		catch (...) {
			cout << endl << "Eroare generica ";
		}



		//fara facultative

		Student::contor++;
	}

	explicit operator float() {
		return this->getMedie();
	}

	Student operator+(int nota) {
		Student clona = *this;

		//se adauga nota

		return clona;
	}

	//metoda care incarca datele studentilor din fisier text
	static ListaStudenti incarcaDateStudentiDinFisier(string numeFisier) {
		ifstream fisier(numeFisier);
		ListaStudenti lista;
		if (fisier.is_open()) {
			int nrStudenti;
			fisier >> nrStudenti;
			lista.nrStudenti = nrStudenti;
			lista.studenti = new Student[nrStudenti];
			for (int i = 0; i < nrStudenti; i++) {
				int id;
				fisier >> id;
				fisier.get();		//elimin '\n din buffer
				char buffer[1000];
				fisier.getline(buffer, 1000);
				string nume = string(buffer);

				Student stud(id, nume);

				int nrNoteFacultative;
				fisier >> nrNoteFacultative;
				if (nrNoteFacultative > 3)
					throw new exception("Numarul de note facultative >  3");
				for (int j = 0; j < nrNoteFacultative; j++) {
					fisier >> stud.noteFacultative[j];
				}
				int nrNoteObligatorii;
				fisier >> nrNoteObligatorii;
				if (nrNoteObligatorii != 0) {
					stud.note = new int[nrNoteObligatorii];
					stud.nrNote = nrNoteObligatorii;
					for (int k = 0; k < nrNoteObligatorii; k++) {
						fisier >> stud.note[k];
					}
				}

				lista.studenti[i] = stud;
			}
		}
		else
			throw new exception("Eroare deschidere fisier");

		return lista;
	}

private:
	void initVectorNoteFacultative() {
		for (int i = 0; i < 3; i++) {
			this->noteFacultative[i] = 0;
		}
	}

	friend ostream& operator<<(ostream& iesire, Student& stud);
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

ostream& operator<<(ostream& iesire, Student& stud) {
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
	return iesire;
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

	cout << student1 << student2;

	//incarcare date studenti dintr-un fisier text
	//vector de studenti

	//Student grupa[5]; //NU merge daca nu avem constructor default
	//Student *grupa;
	//grupa = new Student[5];

	//vector de pointeri la studenti
	Student* grupa[3];
	grupa[0] = &student1;
	grupa[1] = &student2;
	grupa[2] = new Student(5, "Ionut");

	cout << endl << "*************Grupa de studenti:*************";
	for (int i = 0; i < 3; i++) {
		cout << endl << *grupa[i];
	}

	ListaStudenti lista = 
		Student::incarcaDateStudentiDinFisier("dateStudenti.txt");

}