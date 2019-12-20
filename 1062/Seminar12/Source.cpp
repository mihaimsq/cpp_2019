#include <iostream>
#include <string>
using namespace std;

class AbstractPerson {
protected:
	string name;
	int age;
public:
	AbstractPerson(string name, int age) {
		this->name = name;
		this->age = age;
	}
	virtual void info() {
		cout << endl << "Person name is " << this->name;
		cout << endl << "His/her age is " << this->age;
	}

	virtual void takeExam(string exam) = 0;
	virtual void participate(string activity) = 0;
};

class Student : public AbstractPerson {
protected:
	string faculty;
public:
	Student(string name, int age, string faculty)
		:AbstractPerson(name, age) {
		this->faculty = faculty;
	}

	void takeExam(string exam) {
		cout << endl << "Student " << this->name
			<< " takes the exam at " << exam;
	}
	void participate(string activity) {
		cout << endl << "Student " << this->name
			<< " participates at " << activity;
	}

};

class Prof : public AbstractPerson {
protected:
	string faculty;
public:
	Prof(string name, int age, string faculty)
		:AbstractPerson(name, age) {
		this->faculty = faculty;
	}

	void takeExam(string exam) {
		cout << endl << "Prof " << this->name
			<< " organizes the exam at " << exam;
	}
	void participate(string activity) {
		cout << endl << "Prof " << this->name
			<< " participates at " << activity;
	}

};

int main(int argc, char* argv[]) {
	cout << endl << "The name and the path of this process "
		<< argv[0];
	if (argc == 3) {
		cout << endl << argv[1] << "  and " << argv[2];
	}

	//AbstractPerson ap1("John", 21);
	AbstractPerson* pointer;
	Student s1("Alice", 21, "CSIE");
	Prof p1("Bob", 23, "CSIE");

	AbstractPerson* people[2];
	people[0] = &s1;
	people[1] = &p1;

	for (int i = 0; i < 2; i++) {
		people[i]->takeExam("POO");
		people[i]->participate("POO course");

	}

}