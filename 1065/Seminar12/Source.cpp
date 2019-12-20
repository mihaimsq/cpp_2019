#include <iostream>
#include <string>
using namespace std;

class AbstractPerson {
protected:
	string name;
	int age;
public:
	AbstractPerson(string Name, int Age) {
		this->name = Name;
		this->age = Age;
	}
	virtual void info() {
		cout << endl << this->name << " is " << this->age
			<< " years old";
	}

	virtual void takeExam(string exam) = 0;
	virtual void participate(string course) = 0;
};

class Student : public AbstractPerson {
protected: 
	string faculty;
public:

	Student(string name, int age, string faculty) 
		:AbstractPerson(name, age) {
		this->faculty = faculty;
	}

	virtual void takeExam(string exam) {
		cout << endl << this->name << " takes the exam at "
			<< exam;
	}
	virtual void participate(string course) {
		cout << endl << this->name << "goes to " << course;
	}
};

class Professor : public AbstractPerson {
protected:
	string university;
public:
	Professor(string name, int age, string univ)
	:AbstractPerson(name, age){
		university = univ;
	}

	void info() {
		this->AbstractPerson::info();
		cout << endl << "It's a prof at " << this->university;
	}

	virtual void takeExam(string exam) {
		cout << endl << this->name << " prepares the exam at "
			<< exam;
	}
	virtual void participate(string course) {
		cout << endl << this->name << " presents " << course;
	}
};

int main(int argc, char* argv[]) {
	cout << argv[0];
	if (argc == 3) {
		cout << endl << "First filename: " << argv[1];
		cout << endl << "Second filename: " << argv[2];
	}

	//AbstractPerson p1("John", 21);
	AbstractPerson* pointer;		//an abstract class is used as a pointer type

	Student s1("Alice",21,"CSIE");
	Professor p1("Vader", 21, "ASE");

	AbstractPerson* list[2];
	list[0] = &s1;			//up-casting
	list[1] = &p1;

	for (int i = 0; i < 2; i++) {
		list[i]->info();
		list[i]->takeExam("OOP");
		list[i]->participate("OOP");
	}
}