
#include <string.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class ExceptieStudent {
public:
	string mesaj;
	int codEroare;

	ExceptieStudent(string msj, int cod)
		:mesaj(msj), codEroare(cod) 
	{

	}
};

class StudentEvoluat;

class ListaStudenti {
public:
	StudentEvoluat** lista = NULL;
	int nrStudenti = 0;
};

class StudentEvoluat {
public:
	char nume[50];
private:
	int varsta = 0;
public:
	const int nrMatricol;
	char gen = 'N';
private:
	int noteExameneObligatorii[18];
	int nrDisciplineObligatorii = 0;

	int *noteExameneFacultative = NULL;
	int nrDisciplineFacultative = 0;

	static int nrStudenti;

public:
	const static int NOTA_MAXIMA;

	//constructori


private:
	//constructor default/implicit/fara parametri
	StudentEvoluat() :nrMatricol(0) {
		//NU MERGE
		//this->nrMatricol = 0;
		cout << endl << " Salut ! Exist !";
		strcpy(this->nume, "Anonim");

		nrStudenti += 1;
	}


public:
	//constructor cu parametri
	StudentEvoluat(const char* nume, int id) : nrMatricol(id) {
		//cout << endl << " Constructor ce primeste numele studentului";
		strcpy(this->nume, nume);
		StudentEvoluat::nrStudenti += 1;
	}

	StudentEvoluat(const char* nume,
		int varsta, int nrMatricol) :nrMatricol(nrMatricol) {
		//cout << endl << " Constructor ce primeste numele studentului";
		strcpy(this->nume, nume);
		//shadowing
		//varsta = varsta;
		this->varsta = varsta;

		StudentEvoluat::nrStudenti += 1;
	}

	StudentEvoluat(const char* nume,
		int* noteFaculative, int nrNote) :nrMatricol(nrStudenti) {
		strcpy(this->nume, nume);
		this->nrDisciplineFacultative = nrNote;


		this->noteExameneFacultative = new int[nrNote];
		for (int i = 0; i < nrNote; i++) {
			if (noteFaculative[i] > StudentEvoluat::NOTA_MAXIMA)
				//throw "Nota gresita";
				//throw - 1;
				//throw new int(-1);
				//throw new ExceptieStudent("Nota gresita", -1);
				throw new exception("Nota gresita");
			this->noteExameneFacultative[i] = noteFaculative[i];
		}
		StudentEvoluat::nrStudenti += 1;
	}

	~StudentEvoluat() {
		if (this->noteExameneFacultative != NULL) {
			delete[] this->noteExameneFacultative;
		}
	}

	//constructor de copiere
	StudentEvoluat(StudentEvoluat& student)
		:nrMatricol(student.nrMatricol) {
		//this->noteExameneFacultative = student.noteExameneFacultative;

		this->gen = student.gen;
		strcpy(this->nume, student.nume);
		this->varsta = student.varsta;

		for (int i = 0; i < student.nrDisciplineObligatorii; i++) {
			this->noteExameneObligatorii[i] =
				student.noteExameneObligatorii[i];
		}
		this->nrDisciplineObligatorii = student.nrDisciplineObligatorii;

		this->noteExameneFacultative = new int[student.nrDisciplineFacultative];
		this->nrDisciplineFacultative = student.nrDisciplineFacultative;
		for (int i = 0; i < this->nrDisciplineFacultative; i++)
			this->noteExameneFacultative[i] = student.noteExameneFacultative[i];


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

	void adaugaNotaFacultativa(int nota) {
		if (nota > 0 && nota <= StudentEvoluat::NOTA_MAXIMA) {
			int* note = new int[this->nrDisciplineFacultative + 1];
			for (int i = 0; i < this->nrDisciplineFacultative; i++) {
				note[i] = this->noteExameneFacultative[i];
			}
			note[this->nrDisciplineFacultative] = nota;
			this->nrDisciplineFacultative += 1;

			//evitam un memory leak
			delete[] this->noteExameneFacultative;
			this->noteExameneFacultative = note;
		}
		else
			throw "Nota un e ok";
	}

	void printDate() {
		cout << endl << " --------------------------- ";
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

	//metoda ce incarca un vector de studenti
	static ListaStudenti loadDateStudenti(string numeFisier) {
		ListaStudenti studenti;
		ifstream fisier("DateInput.txt", ios::in);
		if (fisier.is_open()) {
			fisier >> studenti.nrStudenti;
			studenti.lista = new StudentEvoluat*[studenti.nrStudenti];
			for (int i = 0; i < studenti.nrStudenti; i++) {
				char buffer[100];
				fisier.get();
				fisier.getline(buffer, 100);
				int varsta;
				fisier >> varsta;
				int nrMatricol;
				fisier >> nrMatricol;
				char gen;
				fisier >> gen;
				studenti.lista[i] = 
					new StudentEvoluat(buffer, varsta, nrMatricol);
				studenti.lista[i]->gen = gen;
				//citim notele obligatorii
				fisier >> studenti.lista[i]->nrDisciplineObligatorii;
				for (int j = 0; j < studenti.lista[i]->nrDisciplineObligatorii; j++) {
					fisier >> studenti.lista[i]->noteExameneObligatorii[j];
				}
				//citim notele facultative
				int nrNoteF;
				fisier >> nrNoteF;
				studenti.lista[i]->nrDisciplineFacultative = nrNoteF;
				studenti.lista[i]->noteExameneFacultative = new int[nrNoteF];
				for (int j = 0; j < nrNoteF; j++) {
					fisier >> studenti.lista[i]->noteExameneFacultative[j];
				}
			}

			return studenti;
		}
		else
			throw new exception("Eroare deschidere fisier");
	}

	friend void operator<<(ostream& out, StudentEvoluat stud);

};

int StudentEvoluat::nrStudenti = 0;
const int StudentEvoluat::NOTA_MAXIMA = 10;

void operator<<(ostream& out, StudentEvoluat stud) {
	out << endl << " --------------------------- ";
	out << endl << "Nume: " << stud.nume;
	out << endl << "Varsta: " << stud.getVarsta();
	out << endl << "Gen: " << stud.gen;
	out << endl << "Nr matricol: " << stud.nrMatricol;
	out << endl << "Note examene obligatorii: ";
	for (int i = 0; i < stud.nrDisciplineObligatorii; i++) {
		out << stud.noteExameneObligatorii[i] << " | ";
	}

	if (stud.noteExameneFacultative == NULL) {
		out << endl << "Nu sunt note pentru facultative";
	}
	else {
		out << endl << "Note examene facultative: ";
		for (int i = 0; i < stud.nrDisciplineFacultative; i++) {
			out << stud.noteExameneFacultative[i] << " | ";
		}
	}
}


int main() {

	StudentEvoluat student1("Gigel", 1);
	StudentEvoluat student2("Ana", 19, 2);


	int noteFacultative[] = { 9,9,8 };
	int nrNote = 3;
	try {

		cout << endl << "Incerc ceva ";
		StudentEvoluat student3("Ionel", noteFacultative, nrNote);
		//StudentEvoluat studenti[5];
		//StudentEvoluat *studenti;
		//studenti = new StudentEvoluat[5];

		//StudentEvoluat* studenti[5];
//studenti[0] = &student1;
//studenti[1] = &student2;
//studenti[2] = &student3;
//studenti[3] = new StudentEvoluat("George", 21, 1001);
//studenti[4] = new StudentEvoluat("George", 21, 1001);

		StudentEvoluat* *studenti;
		studenti = new StudentEvoluat*[3];
		int nrStudenti = 3;
		studenti[0] = &student1;
		studenti[1] = &student3;
		studenti[2] = new StudentEvoluat("George", 21, 1001);

		cout << endl << "-----------Lista studenti: ";
		for (int i = 0; i < 3; i++) {
			studenti[i]->printDate();
		}

		//generare raport text cu datele studentilor
		ofstream raport("DateStudenti.txt", ios::trunc | ios::out);
		for (int i = 0; i < nrStudenti; i++)
			raport << *studenti[i];
		raport.close();

		//incarcam date din fisier
		cout << endl << " ****************** date fisier";
		ListaStudenti lista = StudentEvoluat::loadDateStudenti("DateInput.txt");
		for (int i = 0; i < lista.nrStudenti; i++)
			cout << *lista.lista[i];

	}
	catch (const char* mesajEroare) {
		cout << endl << "Eroare: " << mesajEroare;
	}
	catch (int codEroare) {
		cout << endl << "Eroare: " << codEroare;
	}
	catch (int* codEroare) {
		cout << endl << "Eroare: " << *codEroare;
	}
	catch (ExceptieStudent* ex) {
		cout << endl << "Mesaj eroare:" << ex->mesaj;
		cout << endl << "Cod eroare:" << ex->codEroare;
	}
	catch (exception ex) {
		cout << endl << "Mesaj eroare:" << ex.what();
	}
	catch (...) {
		cout << endl << "Oops, eroare !";
	}



	cout << endl << "Sfarsit";

}