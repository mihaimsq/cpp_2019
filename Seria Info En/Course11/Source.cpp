#include <iostream>
#include <string>
using namespace std;
class Student2_0;
class Student {
protected:
	string name;
	int age;
	int grades[10];
	int noGrades;
	int *somethingInHeap;

public:
	//Student() {
	//	cout << endl << "Default ctr from Student";
	//	somethingInHeap = new int[5];
	//}
	Student(string name, int age):name(name), age(age) {
		cout << endl << "Ctr with args from Student";
		somethingInHeap = new int[5];
	}
	Student(const Student& s) {
		cout << endl << "Copy Ctr from Student";
		somethingInHeap = new int[5];
	}

	~Student() {
		cout << endl << "Destructor from Student";
		delete[] somethingInHeap;
	}

	void aMethod() {
		cout << endl << "A function from Student";
	}

};

class Student2_0: public Student {
	char gender;
	int height;
public:
	Student2_0():Student("John",23) {
		cout << endl << "Default ctr from Student2.0";
		//this->age = 23;
		//this->name = "John";
	}

	Student2_0(string nume, int varsta, char gen)
		:Student(nume, varsta) {
		this->gender = gen;
	}

	~Student2_0() {
		cout << endl << "Destructor from Student2.0";
	}
};
class Intern : Student {
	string company;
	int internshipDuration;
};

class MasterStudent : Student2_0 {
	string masterProgram;
};

int main() {
	//Student s1;
	//s1.aMethod();


	//Student students[5];
	//Student s2("John", 21);

	Student2_0 stud1;
	Student2_0 stud2;
	Student2_0 stud3("Ana", 21, 'F');
	//stud1.aMethod();
	//stud1.age = 22;

}