#include <string>
#include <iostream>
using namespace std;

class StudentClass {
private:
	char studentName[50] = "John Doe";
	char* studentAddress = NULL;
	std::string highSchool = "";
	unsigned int id = 0;
	int age = 0;
	char gender = 'N';
	int mandatoryExams[15];
	int noMandatoryCourses = 0;

	int* facultativeExams = NULL;
	int noFacultativeCourses = 0;
public:

	//special methods
	//constructors family

	//the default constructor / the one without parameters
private:
	StudentClass() {
		cout << endl << "Hello ! I am a student";
		for (int i = 0; i < 15; i++) {
			this->mandatoryExams[i] = 0;
		}
	}
public:
	StudentClass(int id, const char* name) {
		cout << endl << "Constructor with arguments";
		//shadowing
		//id = id;
		this->id = id;
		this->setName(name);
	}

	//public interface of your class
	void setStudentAge(int value) {
		if (value >= 14)
			this->age = value;
		else {
			throw new exception("That's wrong !");
		}
	}

	void setName(const char* newName) {
		if (strlen(newName) >= 2) {
			strcpy(this->studentName, newName);
		}
		else
			throw "The name is too short";
	}

	void printStudentData() {
		cout << endl << "The name is " << this->studentName;
		cout << endl << "The ID is " << this->id;
		if (this->studentAddress != NULL) {
			cout << endl << "The address is " << this->studentAddress;
		}
		else {
			cout << endl << "No known address";
		}
		cout << endl << "The gender is " << this->gender;
		cout << endl << "The graduated highschool is " << this->highSchool;
		cout << endl << "The grades are: ";
		cout << endl << "For mandatory exams: ";
		for (int i = 0; i < this->noMandatoryCourses; i++) {
			cout << this->mandatoryExams[i] << " | ";
		}
		cout << endl << "For optional exams: ";
		for (int i = 0; i < this->noFacultativeCourses; i++) {
			cout << this->facultativeExams[i] << " | ";
		}
		cout << endl << "------------------------";
	}
};


int main() {

	//work with classes

	//the default is now private
	StudentClass superStudent; //an object
	StudentClass anotherStudent; //an object


	//StudentClass superStudents[1000];

	StudentClass student(1,"Alice"); //an object

	//student.studentName[3] = 0;
	//student.studentName = "John";
	//strcpy(superStudent.studentName, "John");
	//superStudent.gender = 'M';
	//superStudent.highSchool = "Vianu";

	//It's wrong
	//superStudent.studentAddress = "Bucharest";

	//superStudent.studentAddress = new char[100];
	//superStudent.studentAddress = new char[strlen("Bucharest")+1];
	//strcpy(superStudent.studentAddress, "Bucharest");

	//superStudent.age = -23;

	anotherStudent.setName("Bob");

	superStudent.printStudentData();
	anotherStudent.printStudentData();
	student.printStudentData();


	//superStudent.setStudentAge(23, superStudent);
	//superStudent.printStudentData(superStudent);

}