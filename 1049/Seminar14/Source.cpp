#include <iostream>
#include <string>

using namespace std;

class A {
public:
	virtual void functieVirtuala() {
		cout << endl << " Functie virtuala A";
	}

	virtual void functieAbstracta() = 0;

	A(int vb) {

	}
};

class B : public A {
public:
	B(): A(5) {

	}

	void functieVirtuala() {
		cout << endl << " Functie virtuala B";
	}

	void functieAbstracta() {
		cout << endl << "Implementare functie in B";

	}
};

class C : public A {
	void functieAbstracta() {
		cout << endl << "Implementare functie in C";
	}
public:
	C() : A(5) {

	}
};

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
	T culoareOchi;
	P* note;
	int nrNote;
public:
	T getCuloare() {
		return this->culoareOchi;
	}

	Student(int varsta, T Culoare, P* note, int nrNote) {
		this->varsta = varsta;
		this->culoareOchi = Culoare;
		this->note = new P[nrNote];
		this->nrNote = nrNote;
		for (int i = 0; i < nrNote; i++)
			this->note[i] = note[i];
	}
};

int main() {
	//A a(10);
	A *pa;
	B b;
	C c;

	//A obiecte[10];
	A* pObiecte[3];
	pObiecte[0] = &b;
	pObiecte[1] = &c;
	pObiecte[2] = new B();

	for (int i = 0; i < 3; i++)
		pObiecte[i]->functieVirtuala();

	cout << endl << "2+3 = " << suma(2, 3);
	cout << endl << "2.2+3.3 = " << suma((float)2.2, 3.3f);

	cout << endl << "2+3 = " << sumaGenerica(2, 3);
	cout << endl << "2.2+3.3 = " 
		<< sumaGenerica<float>((float)2.2, 3.3f);
	cout << endl << "Concatenare = " << 
		sumaGenerica<string>("Ana ", " are mere");

	int* note = new int[5]{ 9,9,9,10,8 };
	Student<string, int> s1(21, "albastru", note, 5);
	Student<int, int> s2(21, 255, note, 5);
}
