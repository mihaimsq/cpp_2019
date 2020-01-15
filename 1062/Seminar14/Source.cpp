#include <iostream>
#include <string>
using namespace std;

class Faculty {
public:
	string name;
	string address;
public:
	Faculty(string Name, string Address) {
		this->name = name;
		address = Address;
	}
};

class GradeInterface {
public:
	virtual int getValue() = 0;
	virtual string getCourseName() = 0;
};

class EasternEuropeGrade: public GradeInterface {
private:
	int value;
	string course;
public:
	int getValue() {
		return this->value;
	}
	string getCourseName() {
		return this->course;
	}
	EasternEuropeGrade(int Value, string Course) {
		this->value = Value;
		course = Course;
	}
};

class Student {
	Faculty faculty;
	GradeInterface* *grades = NULL;
	int noGrades = 0;
public:
	Student(string facultyName, string facultyAddress)
		:faculty(facultyName, facultyAddress) {
		this->grades = NULL;
		noGrades = 0;
	}

	Student(Faculty studentFaculty):faculty(studentFaculty) {
		this->grades = NULL;
		noGrades = 0;
	}

	Student(Faculty studentFaculty,
		EasternEuropeGrade** grades, int noGrades)
		:faculty(studentFaculty) {
		this->grades = new GradeInterface*[noGrades];
		this->noGrades = noGrades;

		//option 1 - shallow copy
		//for (int i = 0; i < noGrades; i++) {
		//	this->grades[i] = grades[i];
		//}

		//option 2 - deep copy
		for (int i = 0; i < noGrades; i++) {
			this->grades[i] =
				new EasternEuropeGrade(grades[i]->getValue(),
					grades[i]->getCourseName());
		}
	}

	//dummy copy constructor
	Student(const Student& stud): faculty(stud.faculty) {
		cout << endl << "The student CC";
	}

	//post increment
	Student operator++(int) {
		//Student copy(*this);
		Student copy = *this;

		//change this
		this->noGrades += 1;
		//you need to add the grade TO DO

		return copy;
	}

	Student& operator=(Student s) {
		//copy values from s to this
		//TO DO
		cout << endl << "Calling Student operator =";
		return *this;

	}
};

int main() {

	Faculty csie("CSIE", "Calea Dorobanti");
	Student s1(csie);
	Student s2(csie);
	
	s2 = s1++;	//operator =(s2, (s1++));
	s1++;
	s2 = s1;


}
