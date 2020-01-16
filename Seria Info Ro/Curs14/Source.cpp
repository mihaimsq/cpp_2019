#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class A {
	int x;
public:
	virtual void functie() {
		cout << endl << " Functie A virtuala";
	}

};

class B : public A {
	int y = 0;
public:
	void functie() {
		cout << endl << " Functie B virtuala";
	}
};

class C : public B {
	int z = 99;
public:
	void Functie() {
		cout << endl << " Functie C virtuala";
	}

	void functieSpeciala() {
		cout << endl << " Functie speciala";
		cout << endl << "Z = " << z;
	}
};

//template
int suma(int a, int b) {
	return a + b;
}

float suma(float a, float b) {
	return a + b;
}

string suma(string a, string b) {
	return a + b;
}

template<typename X> X sumaGenerica(X a, X b) {
	return a + b;
}

template <typename T, typename P> class Student {
	int varsta = 0;
	int id;
	T culoareOchi;
	P *note;
	int nrNote;

public:
	Student(int Id, const T culoare, P* note, int NrNote) {
		this->id = Id;
		culoareOchi = culoare;
		this->note = new P[NrNote];
		for (int i = 0; i < NrNote; i++)
			this->note[i] = note[i];
		this->nrNote = NrNote;
	}

	T getCuloareOchi() {
		return this->culoareOchi;
	}

};
//specializare partiala
template <typename P> class Student<char*, P> {

	int varsta = 0;
	int id;
	char* culoareOchi;
	P *note;
	int nrNote;
public:
	Student(int Id, const char* culoare, P* note, int NrNote) {
		cout << endl << "Apel constructor specializat";
		this->id = Id;
		this->culoareOchi = new char[strlen(culoare) + 1];
		strcpy(this->culoareOchi, culoare);
		this->note = new P[NrNote];
		for (int i = 0; i < NrNote; i++)
			this->note[i] = note[i];
		this->nrNote = NrNote;
	}
};

int main() {
	A a;
	B b;
	C c;

	a = b; //up-casting

	A *pa;
	pa = &a; //up-casting
	pa = &b;
	pa = &c;

	A* *pointeri;
	pointeri = new A*[3];
	pointeri[0] = &a;
	pointeri[1] = &b;
	pointeri[2] = &c;

	for (int i = 0; i < 3; i++)
		pointeri[i]->functie();

	//down-casting

	if (dynamic_cast<C*>(pointeri[2]))
	{
		C* pointerC = (C*)pointeri[2];
		pointerC->functieSpeciala();
	}
	else
		cout << endl << "La adresa respectiva nu este un C";

	cout << endl << "2 + 3 = " << suma(2, 3);
	cout << endl << "2.2 + 3.3 = " << suma(2.2f, (float)3.3);
	cout << endl << "Ana + are mere = " << suma("Ana"," are mere");

	cout << endl << "2 + 3 = " << sumaGenerica(2, 3);
	cout << endl << "2.2 + 3.3 = " << sumaGenerica<float>(2.2f, (float)3.3);
	cout << endl << "Ana + are mere = " << sumaGenerica<string>("Ana", " are mere");

	int* noteNumere = new int[3]{ 9,9,10 };
	string* noteCalificative = new string[3]{ "bine", "bine", "foarte bine" };


	Student<string, int> s1(1, "albastri", noteNumere, 3);
	Student<int, string> s2(1, 127, noteCalificative, 3);
	Student<char*, string> s3(1, (char*)"caprui", noteCalificative, 3);
}