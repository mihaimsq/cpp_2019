#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Student;

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
	int noteFacultative[5] = { 0,0,0,0,0 };

	static int contor;
public:
	static const float MEDIE_MINIMA_BURSA;


private:
	Student() :id(0) {

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

	void operator=(const Student& existent) {
		try {
			this->transferNote(existent.note, existent.nrNote);
		}
		catch (...) {
			this->note = NULL;
			this->nrNote = 0;
		}

		this->nume = existent.nume;

		for (int i = 0; i < 5; i++) {
			this->noteFacultative[i] = existent.noteFacultative[i];
		}
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

	void serializareStudent(ofstream& fisierBinar) {
		//scriem id-ul
		fisierBinar.write((char*)&this->id, sizeof(int));
		//scriem numarul de caractere al numelui
		int nrCaractere = this->nume.size();
		fisierBinar.write((char*)&nrCaractere, sizeof(int));
		//scriem numele
		fisierBinar.write(this->nume.c_str(), this->nume.size() + 1);
		//scriem numarul de note obligatorii
		fisierBinar.write((char*)&this->nrNote, sizeof(int));
		
		//scriem notele una cate una - alternativa
		for (int i = 0; i < this->nrNote; i++) {
			fisierBinar.write((char*)&this->note[i], sizeof(int));
		}
		//scriem toate notele
		//fisierBinar.write((char*)this->note, sizeof(int) * this->nrNote);

		//scriem notele facultative
		//fisierBinar.write((char*)this->noteFacultative, sizeof(this->noteFacultative));
		fisierBinar.write((char*)this->noteFacultative, sizeof(int) * 5);
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


	iesire << endl << "Note examene obligatorii:";
	for (int i = 0; i < stud.getNrNote(); i++) {
		iesire << stud.note[i] << " | ";
	}

	iesire << endl << "Note examene facultative:";
	for (int i = 0; i < 5; i++) {
		iesire << stud.noteFacultative[i] << " | ";
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

	int* ceva;
	ceva = new int[3] {10, 10, 9};


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
		Student::incarcaDateStudentiDinFisier("studenti.txt");
	cout << endl << "*************Lista de studenti:*************";
	for (int i = 0; i < lista.nrStudenti; i++) {
		cout << endl << lista.studenti[i];
	}

	ofstream raportStudenti("raport.txt");
	for (int i = 0; i < lista.nrStudenti; i++) {
		raportStudenti << endl << lista.studenti[i];
	}
	raportStudenti.close();

	//lucru cu fisiere binare
	ofstream dateStudenti("studenti.bin", ios::out | ios::binary | ios::trunc);
	
	//salvez in fisier numarul de studenti
	dateStudenti.write((char*)&lista.nrStudenti, sizeof(int));
	for (int i = 0; i < lista.nrStudenti; i++) {
		//nu folosim <<
		//dateStudenti << endl << lista.studenti[i];

		//NU ASA daca aveti campuri dinamice
		//dateStudenti.write((char*)&lista.studenti[i], sizeof(Student));

		lista.studenti[i].serializareStudent(dateStudenti);
	}
	dateStudenti.close();

	//citire fisier binar

	Student* *lista2;
	int nrStudenti;

	ifstream dateIntrare;
	dateIntrare.open("studenti.bin", ios::in | ios::binary);
	if (dateIntrare.is_open()) {

		dateIntrare.read((char*)&nrStudenti, sizeof(int));
		//lista2 = new Student*[nrStudenti];

		//for (int i = 0; i < nrStudenti; i++) {
		//	//in fisierul binar am obiectele scrise direct
		//	lista2[i] = new Student(0, "");
		//	dateIntrare.read((char*)lista2[i], sizeof(Student));
		//}


		dateIntrare.close();
	}
	else
		cout << endl << "**********PROBLEME deschidere fisier";

	//cout << endl << "*************Lista de studenti din fisier binar:*************";
	//for (int i = 0; i < nrStudenti; i++) {
	//	cout << endl << *lista2[i];
	//}
}