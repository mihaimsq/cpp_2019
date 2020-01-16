#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

int suma(int a, int b) {
	return a + b;
}

float suma(float a, float b) {
	return a + b;
}

template<typename X> X sumaGenerica(X a, X b) {
	return a + b;
}

template<typename T, typename P> class Student {
	int varsta;
	T* note;
	int nrNote;
	P culoareOchi;
public:
	Student(int Varsta, P CuloareOchi,
		T* Note, int nrNote) {
		varsta = Varsta;
		this->nrNote = nrNote;
		this->culoareOchi = culoareOchi;
		this->note = new T[nrNote];
		for (int i = 0; i < nrNote; i++)
			this->note[i] = Note[i];
	}
};

//specializare totala a unei metode
template<> Student<int,char*>::Student(
	int Varsta, char* CuloareOchi,
	int* Note, int nrNote) {
}

//specializare partiala a clasei
template<typename T> class Student<T, char*> {
public:
	Student(
		int Varsta, char* CuloareOchi,
		T* Note, int nrNote) {
	}
};

int main() {
	cout << endl << "Suma dintre 2 si 3 este " <<
		suma(2, 3);
	cout << endl << "Suma dintre 2.2 si 3.3 este " <<
		suma(2.2f, 3.3f);

	cout << endl << "Suma dintre 2 si 3 este " <<
		sumaGenerica(2, 3);
	cout << endl << "Suma dintre 2.2 si 3.3 este " <<
		sumaGenerica<float>(2.2f, 3.3f);
	cout << endl << "Concatenare de siruri: "
		<< sumaGenerica<string>("Ana ", " are mere");

	int *note = new int[5]{ 9,9,9,9,9 };
	Student<int, string> stud1(21, "albastru", note, 5);

	vector<int> numere;
	vector<string> nume;

	numere.push_back(10);
	numere.push_back(10);
	numere.push_back(5);
	numere.push_back(6);

	for (int i = 0; i < numere.size(); i++)
		cout << endl << numere[i];

	nume.push_back("Gigel");
	nume.push_back("Ana");
	nume.push_back("Ion");

	for (int i = 0; i < nume.size(); i++)
		cout << endl << nume[i];

	set<int> numereUnice;
	numereUnice.insert(10);
	numereUnice.insert(10);
	numereUnice.insert(10);
	numereUnice.insert(5);

	set<int>::iterator it;
	for (it = numereUnice.begin();
		it != numereUnice.end(); it++) {
		cout << endl << "Numar unic = " << *it;
	}

	map<int, string> indexStudenti;
	indexStudenti[100] = "Gigel";
	indexStudenti[5] = "Ana";
	indexStudenti[50] = "Ionel";



}