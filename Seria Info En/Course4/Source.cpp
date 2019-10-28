#include <string>
#include <iostream>
using namespace std;

struct Student {

	char studentName[50];
	char* studentAddress;
	std::string highSchool;

	unsigned int id;
	char gender;
	int age;

	int mandatoryExams[15];
	int noMandatoryCourses;

	char* facultativeExams;
	int noFacultativeCourses;
};

class StudentClass {
public:
	char studentName[50];
	char* studentAddress;
	std::string highSchool;
public:
	unsigned int id;
private:
	int age;
public:
	char gender;
private:
	int mandatoryExams[15];
	int noMandatoryCourses;

	char* facultativeExams;
	int noFacultativeCourses;
public:
	void setStudentAge(int value, StudentClass& student) {
		if (value >= 14)
			student.age = value;
		else {
			throw new exception("That's wrong !");
		}
	}

	void printStudentData(StudentClass student) {
		cout << endl << "The name is " << student.studentName;
		cout << endl << "The gender is " << student.gender;
		cout << endl << "The graduated highschool is " << student.highSchool;
	}
};

void setStudentAge(int value, Student& student) {
	if(value >= 14)
		student.age = value;
	else {
		throw new exception("That's wrong !");
	}
}

void printStudentData(Student student) {
	cout << endl << "The name is " << student.studentName;
	cout << endl << "The gender is " << student.gender;
	cout << endl << "The graduated highschool is " << student.highSchool;
}

int main() {

	Student student; //an article
	Student students[1000];

	//student.studentName[3] = 0;
	//student.studentName = "John";
	strcpy(student.studentName, "John");
	student.gender = 'M';
	student.highSchool = "Vianu";
	student.age = -23;
	//setStudentAge(-23, student);

	printStudentData(student);

	//work with classes
	StudentClass superStudent; //an object
	StudentClass superStudents[1000];

	//student.studentName[3] = 0;
	//student.studentName = "John";
	strcpy(superStudent.studentName, "John");
	superStudent.gender = 'M';
	superStudent.highSchool = "Vianu";

	//superStudent.age = -23;
	superStudent.printStudentData(superStudent);
	superStudent.setStudentAge(23, superStudent);
	superStudent.printStudentData(superStudent);

}