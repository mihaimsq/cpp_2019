#include <iostream>
#include <string>
using namespace std;

class AnotherPerson {
public: 
	//a virtual pure method - a method without a body
	virtual void genericPrint() = 0;
};

class Person: public AnotherPerson {
protected:
	string name = "";
	int age = 0;
public:
	Person() {
		cout << endl << "Default from Person";
	}
	~Person() {
		cout << endl << "Destructor from Person";
	}

	virtual void print() {
		cout << endl << this->name << " is " << this->age
			<<" years old";
	}

};
class Student : public Person {
protected:
	string faculty;
public:
	Student(string name, int age, string faculty):Person() {
		cout << endl << "With args from Student";
		this->name = name;
		this->age = age;
		this->faculty = faculty;
	}

	Student() {

	}
	~Student() {
		cout << endl << "Destructor from Student";
	}

	void printStudent() {
		this->print();
		cout << endl << "His/Her faculty is " << this->faculty;
	}

	//overloading
	void doSomething(int vb) {

	}

	void doSomething(int a, int b) {

	}

	void doSomething(char a, string b) {

	}

	//overriding
	//change the behaviour of your parent type method
	void print() {
		//cout << endl << this->name << " is " << this->age
		//	<< " years old";
		
		//calling the parent print
		this->Person::print();
		cout << endl << "His/Her faculty is " << this->faculty;
	}


	void genericPrint() {
		cout << endl << "A body";
	}
};

class MasterStudent : public Student {
protected:
	string masterProgram;
public:
	MasterStudent() :Student("",0,"") {
		cout << endl << "Default from MasterStudent";
	}

	MasterStudent(string name, int age,
		string faculty, string master)
		:Student(name, age, faculty) {
		cout << endl << "With args from MasterStudent";
		this->masterProgram = master;
	}

	~MasterStudent() {
		cout << endl << "Destructor from MasterStudent";
	}

	//overriding
	//change the behaviour of your parent type method
	void print() {
		this->Student::print();
		cout << endl << "His/Her master program is " << this->masterProgram;
	}
};

class Intern : public Student {
protected:
	string company;
public:
	Intern(string name, int age,
		string faculty, string company)
		:Student(name, age, faculty) {
		cout << endl << "With args from Intern";
		this->company = company;
	}
	~Intern() {
		cout << endl << "Destructor from Intern";
	}

	//overriding
//change the behaviour of your parent type method
	void print() {
		this->Student::print();
		cout << endl << "The company is " << this->company;
	}
};

int main() {
	Person p1;
	Student s1("Student John", 21, "CSIE");
	MasterStudent m1("Master Bob", 22,"MAN","Master 1") ;
	Intern i1("Intern Alice", 21, "CSIE", "Intel");

	Person persons[10];
	Student students[5];

	//we try to store all objects in a single array
	Person everything[4];
	everything[0] = p1;
	everything[1] = s1;	//up-casting
	everything[2] = m1;
	everything[3] = i1;

	Person* all[4];
	all[0] = &p1;	//up-casting at pointer level
	all[1] = &s1;
	all[2] = &m1;
	all[3] = &i1;

	cout << endl << "----------------------";
	//s1.print();
	for (int i = 0; i < 4; i++) {
		all[i]->print();		//early - binding without virtual
		//late-binding 
	}
	cout << endl << "----------------------";

}