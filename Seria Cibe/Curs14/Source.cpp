#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <fstream>

using namespace std;

class A {
public:
	virtual void nimic() {

	}
};

class B : public A {

};

class C : public A {

};

class D : public C {
	int x = 99;
public:
	void metodaD() {
		cout << endl << " X = " << x;
	}
};

class Student {
public:
	int id;
	int varsta;
	string nume;

	Student() {
		id = 0;
		varsta = 0;
		nume = "Anonim";
	}
	Student(string nume, int varsta, int id) {
		this->nume = nume;
		this->varsta = varsta;
		this->id = id;
	}
};

class Test {
	int valori[100];
public:
int&	operator[](int index) {
		//validez indexul
		return this->valori[index];
	}

int operator()(int i, int j) {

}

};

ofstream& operator<<(ofstream& fisierBinar, Student s) {
	//fisierBinar.
}

int main() {

	A a;
	B b;
	C c;
	D d;

	A* obiecte[4];
	obiecte[0] = &a;	//upcasting
	obiecte[1] = &b;
	obiecte[2] = &c;
	obiecte[3] = &d;

	D* pd;
	pd = (D*)obiecte[1]; //down casting

	if (dynamic_cast<D*>(obiecte[1])) {
		cout << endl << "Putem face downcast in siguranta";
	}
	else
		cout << endl << "Nu putem face downcast in siguranta";

	if (dynamic_cast<D*>(obiecte[3])) {
		cout << endl << "Putem face downcast in siguranta";
		pd = (D*)obiecte[3]; //down casting
		pd->metodaD();
	}
	else
		cout << endl << "Nu putem face downcast in siguranta";

	

	//colectii
	vector<int> vectorInt;
	vectorInt.push_back(10);
	vectorInt.push_back(15);
	vectorInt.push_back(23);
	cout << endl << "Vectorul este: ";
	for (int i = 0; i < vectorInt.size(); i++) {
		cout << " " << vectorInt[i];
	}

	vectorInt.pop_back();
	cout << endl << "Vectorul este: ";
	for (int i = 0; i < vectorInt.size(); i++) {
		cout << " " << vectorInt[i];
	}


	vector<Student> vectorStudenti;
	vector<Student*> vectorPStudenti;

	vectorStudenti.push_back(Student("Gigel", 21, 1));
	vectorStudenti.push_back(Student("Ana", 21, 2));

	cout << endl << "Vectorul de studenti este: ";
	for (int i = 0; i < vectorStudenti.size(); i++) {
		cout << " " << vectorStudenti[i].nume;
	}

	vectorPStudenti.push_back(new Student("Ionel", 21, 3));
	vectorPStudenti.push_back(new Student("Ioana", 21, 4));

	cout << endl << "Vectorul de studenti este: ";
	for (int i = 0; i < vectorPStudenti.size(); i++) {
		cout << " " << vectorPStudenti[i]->nume;
	}

	//map
	map<int, Student> mapStudenti;
	mapStudenti[1] = Student("Gigel", 19, 1);
	mapStudenti[100] = Student("Anei", 22, 100);
	mapStudenti[50] = Student("Ioana", 21, 50);
	mapStudenti[3] = Student("Ionel", 21, 3);

	Student gigel = mapStudenti[2];
	if (gigel.id != 0)
		cout << endl << "Varsta lui Gigel este " << gigel.varsta;
	else
		cout << endl << "Gigel nu are id-ul cautat";

	set<int> numereUnice;
	numereUnice.insert(10);
	numereUnice.insert(10);
	numereUnice.insert(13);
	numereUnice.insert(15);
	numereUnice.insert(13);

	cout << endl << "Valorile unice sunt: ";
	set<int>::iterator it = numereUnice.begin();
	for (; it!=numereUnice.end(); it++) {
		cout << " " << "Numar unic este :" << *it;
	}


	Test t;
	int primaValoare = t[0];
	t[0] = 10;
	t[1] = 11;

	float medieAnumiteValori = t(2, 9);

	ofstream fisier();


}