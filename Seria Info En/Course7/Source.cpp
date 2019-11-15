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
	StudentClass() :id(noStudents), dummy(0) {
		cout << endl << "Hello ! I am a student";
		for (int i = 0; i < 15; i++) {
			this->mandatoryExams[i] = 0;
		}

		StudentClass::noStudents += 1;
	}
public:
	StudentClass(int Id, const char* name) :id(Id), dummy(0) {
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

	StudentClass(const char* name, string highSchool, const char* address,
		int* grades, int noGrades,
		int* facultativeGrades, int noFacultativeCourses)
		:id(StudentClass::noStudents), dummy(0) {
		this->setAddress(address);
		this->setName(name);
		this->setFacultativeGrades(facultativeGrades, noFacultativeCourses);
		this->setGrades(grades, noGrades);
		this->highSchool = highSchool;
	}

	//destructor
	~StudentClass() {
		cout << endl << "Calling the destructor";
		if (this->facultativeExams != NULL)
			delete[] this->facultativeExams;
		if (this->studentAddress != NULL)
			delete[] this->studentAddress;
	}

	//copy constructor
	StudentClass(const StudentClass& anotherStudent)
		:id(anotherStudent.id), dummy(0) {
		//don't do it
		//this->facultativeExams = anotherStudent.facultativeExams;

		cout << endl << "The copy constructor";

		this->setFacultativeGrades(anotherStudent.facultativeExams,
			anotherStudent.noFacultativeCourses);
		this->setAddress(anotherStudent.studentAddress);
		//init the other attributes

		//anotherStudent.gender = this->gender;
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

			delete[] this->facultativeExams;
			this->facultativeExams = new int[nGrades];

			for (int i = 0; i < nGrades; i++) {
				this->facultativeExams[i] = grades[i];
			}
			this->noFacultativeCourses = nGrades;
		}
		else
			throw "Wrong data";
	}

	string getName() {
		return this->studentName;
	}

	//don't do this
	//int* getFacultativeGrades() {
	//	return this->facultativeExams;
	//}

	int getNoFacultativeGrades() {
		return this->noFacultativeCourses;
	}

	int getFacultativeGrade(int index) {
		if (index >= 0 && index < this->noFacultativeCourses)
			return this->facultativeExams[index];
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

	void setAddress(const char* address) {
		//don't do it
		//this->studentAddress = address;

		if (strlen(address) >= 3) {
			this->studentAddress = new char[strlen(address) + 1];
			strcpy(this->studentAddress, address);
		}
		else
			throw "The address is too short";
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

	void operator=(StudentClass student) {
		cout << endl << "The copy constructor";

		this->setFacultativeGrades(student.facultativeExams,
			student.noFacultativeCourses);
		this->setAddress(student.studentAddress);
		//init the other attributes

		//anotherStudent.gender = this->gender;
	}

	explicit operator float() {
		float s = 0;
		for (int i = 0; i < this->noMandatoryCourses; i++) {
			s += this->mandatoryExams[i];
		}
		if (this->noMandatoryCourses != 0)
			return s / this->noMandatoryCourses;
		else
			return 0;
	}

	friend void operator<<(ostream& out, StudentClass student);

};//the end 

//init the static attributes
int StudentClass::noStudents = 0;
float StudentClass::MINIMUN_ADMISSION_GRADE = 6;

void justaAFunction() {

	int grades[] = { 10,9,8,10 };
	int nGrades = 4;

	int facultativeGrades[] = { 10,10,10 };
	int noFacultative = 3;

	StudentClass student1("John", "Sava", "Bucharest", grades, nGrades,
		facultativeGrades, noFacultative);
}

void anotherFunction(const StudentClass& student) {
	//nothing
}

StudentClass anotherAnotherFunction() {
	int grades[] = { 10,9,8,10 };
	int nGrades = 4;

	int facultativeGrades[] = { 10,10,10 };
	int noFacultative = 3;

	StudentClass student1("John", "Sava", "Bucharest", grades, nGrades,
		facultativeGrades, noFacultative);

	return student1;
}


void operator<<(ostream& out, StudentClass student) {
	out << endl << "The name is " << student.getName();
	out << endl << "The ID is " << student.id;
	if (student.studentAddress != NULL) {
		out << endl << "The address is " << student.studentAddress;
	}
	else {
		out << endl << "No known address";
	}
	out << endl << "The gender is " << student.gender;
	out << endl << "The graduated highschool is " << student.highSchool;
	out << endl << "The grades are: ";

	if (student.noMandatoryCourses != 0) {
		out << endl << "For mandatory exams: ";
		for (int i = 0; i < student.noMandatoryCourses; i++) {
			out << student.mandatoryExams[i] << " | ";
		}
	}
	else
		out << endl << "There are no grades for mandatory courses";

	if (student.getNoFacultativeGrades() != 0) {
		out << endl << "For optional exams: ";
		for (int i = 0; i < student.getNoFacultativeGrades(); i++) {
			out << student.getFacultativeGrade(i) << " | ";
		}
	}
	else
		out << endl << "There are no grades for facultative courses";

	out << endl << "------------------------";
}

int main() {

	int grades[] = { 10,9,8,10 };
	int nGrades = 4;

	int facultativeGrades[] = { 10,10,10 };
	int noFacultative = 3;

	StudentClass student1("John", "Sava", "Bucharest", grades, nGrades,
		facultativeGrades, noFacultative);
	StudentClass student2("Bob", "Vianu", grades, nGrades);

	student1.printStudentData();
	student2.printStudentData();

	int vb1 = 10; 
	int vb2 = vb1 + 10;		//function=(vb2, function+(vb1,10))


	//operators
	cout << student1 << student2;		//void operator<<(ostream&, StudentClass)
	cin >> student2;		//void operator>>(istream&, StudentClass&)

	//adding a new grade
	//student1.operator+(10)
	student1 = student1 + 10;	//StudentClass operator+(StudentClass, int)
	//9.operator(student1)
	student1 = 9 + student1;	//StudentClass operator+(int, StudentClass)

	student1 += 8;				//void operator+=(StudentClass&, int)
	student2 = student1 += 7;

	//adding multiple grades
	//add 3 facultative grades with 10 by default
	student1 *= 3;				//void operator*=(StudentClass&7, int)

	if (student1 > student2) {	// bool operator>(StudentClass,StudentClass)
		cout << endl << student1.getName() << " has a bigger average";
	}

	if (student1 == student2) { //bool operator==(StudentClass,StudentClass)
		cout << endl << "They have the same average";
	}

	//cast operator
	float average = (float)student1;	// operator float(StudentClass)

	//operator !
	if (!student1)					//bool operator!(StudentClass)
		cout << endl << "The student passed all exams";

	//index operator
	int secondGrade = student1[1];	//int operator[](StudentClass, int)
	
	//operator =
	student2 = student1;		//void operator=(StudentClass&,StudentClass)		

	//function operator
	float averageOf3Grades = student2(1,3);	//float operator()(StudentClass, int, int)
	float averageOfFirst3Grades = student2(3);	//float operator()(StudentClass, int)

	//post increment
	student2++;					//StudentClass operator++(StudentClass&, int)
	//pre increment
	student1 = ++student2;		//StudentClass operator++(StudentClass&)

}