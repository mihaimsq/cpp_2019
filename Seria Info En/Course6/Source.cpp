#include <string>
#include <iostream>
using namespace std;


class StudentClass {
private:
	char studentName[50] = "John Doe";
	char* studentAddress = NULL;
	std::string highSchool = "";
	
	int age = 0;
	char gender = 'N';
	int mandatoryExams[15];
	int noMandatoryCourses = 0;

	int* facultativeExams = NULL;
	int noFacultativeCourses = 0;


	const int dummy;
public:

	const unsigned int id;
	static int noStudents;
	static float MINIMUN_ADMISSION_GRADE;

	//special methods
	//constructors family

	//the default constructor / the one without parameters
private:
	StudentClass():id(0), dummy(0) {
		cout << endl << "Hello ! I am a student";
		for (int i = 0; i < 15; i++) {
			this->mandatoryExams[i] = 0;
		}

		StudentClass::noStudents += 1;
	}
public:
	StudentClass(int Id, const char* name):id(Id), dummy(0) {
		cout << endl << "Constructor with arguments";
		//shadowing
		//id = id;


		//this->id = id;	//you can't after const
		this->setName(name);

		StudentClass::noStudents += 1;
	}

	StudentClass(const char* name, string highSchool, int* grades, int noGrades)
	:id(StudentClass::noStudents), dummy(0)
	{
		this->setName(name);
		this->highSchool = highSchool;
		this->setGrades(grades, noGrades);

		StudentClass::noStudents += 1;
	}

	//destructor
	~StudentClass() {
		cout << endl << "Calling the destructor";
		if (this->facultativeExams != NULL)
			delete[] this->facultativeExams;
	}

private:
	void setGrades(int* grades, int nGrades) {
		if (grades != NULL && nGrades > 0 && nGrades <= 15) {
			for (int i = 0; i < nGrades; i++) {
				this->mandatoryExams[i] = grades[i];
			}
			this->noMandatoryCourses = nGrades;
		}
		else
			throw "Wrong data";
	}
public:

	void setFacultativeGrades(int* grades, int nGrades) {
		if (grades != NULL && nGrades > 0 && nGrades <= 15) {
			this->facultativeExams = new int[nGrades];

			for (int i = 0; i < nGrades; i++) {
				this->facultativeExams[i] = grades[i];
			}
			this->noFacultativeCourses = nGrades;
		}
		else
			throw "Wrong data";
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
		
		if (this->noMandatoryCourses != 0) {
			cout << endl << "For mandatory exams: ";
			for (int i = 0; i < this->noMandatoryCourses; i++) {
				cout << this->mandatoryExams[i] << " | ";
			}
		}
		else
			cout << endl << "There are no grades for mandatory courses";

		if (this->facultativeExams != NULL) {
			cout << endl << "For optional exams: ";
			for (int i = 0; i < this->noFacultativeCourses; i++) {
				cout << this->facultativeExams[i] << " | ";
			}
		}
		else
			cout << endl << "There are no grades for facultative courses";

		cout << endl << "------------------------";
	}
};

//init the static attributes
int StudentClass::noStudents = 0;
float StudentClass::MINIMUN_ADMISSION_GRADE = 6;


int main() {

	int grades[] = { 10,9,8,10 };
	int nGrades = 4;

	StudentClass student1(1, "Alice");
	StudentClass student2("Bob", "Sava", grades, nGrades);
	StudentClass student3(1, "Vader");

	student1.printStudentData();
	student2.printStudentData();

	cout << endl << "No students: " << StudentClass::noStudents;

	student1.setFacultativeGrades(grades, nGrades);
	student1.printStudentData();

	for (;;) {
		StudentClass *pointerStudent = new StudentClass(0, "Dummy");
		pointerStudent->setFacultativeGrades(grades, nGrades);
		delete pointerStudent;
	}

}