#include <iostream>
#include <string>

using namespace std;

class A {
	int x = 0;
public:
	void function() {
		cout << endl << "A function from A";
	}
};

class B : public A {
	int y = 10;
public:
	void function() {
		cout << endl << "A function from B";
	}
};

class C : public B {
	int z = 20;
public:

};

class Faculty {
	string name;
	string address;
public:
	Faculty(string Name, string Address) {
		name = Name;
		address = address;
	}
};

class Grade {
	int value;
	string course;
public:
	int getValue() {
		return value;
	}
	string getCourse() {
		return course;
	}
};

class Student {
	int id;
	string name;
	Faculty faculty;
	Grade *grades;
	int noGrades;
public:
	Student():faculty("CSIE", "Calea Dorobanti") {
		id = 0;
		name = "John Doe";
		grades = NULL;
		noGrades = 0;
	}
	Student(string facultyName, string address)
	:faculty(facultyName, address){
		id = 0;
		name = "John Doe";
		grades = NULL;
		noGrades = 0;
	}

	Student(Faculty sFaculty, Grade* grades, int nGrades
	, string name)
		:faculty(sFaculty){
		id = 0;
		this->name = name;
		this->grades = new Grade[nGrades];
		for (int i = 0; i < nGrades; i++)
			this->grades[i] = grades[i];
		this->noGrades = nGrades;
	}
};

int main() {
	A a;
	B b;
	C c;

	A* objects = new A[3];
	objects[0] = a;
	objects[1] = b;
	objects[2] = c;

	for (int i = 0; i < 3; i++)
		objects[i].function();

	A* *pObjects = new A*[3];
	pObjects[0] = new A();
	pObjects[1] = new B();
	pObjects[2] = &c;

	for (int i = 0; i < 3; i++)
		pObjects[i]->function();

	//will not work if the address is not in Heap - check c
	//for (int i = 0; i < 3; i++)
	//	delete pObjects[i];
	delete[] pObjects;


	A* pa = new A();
	delete pa;


	Student s1;



}