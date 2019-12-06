#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class StudentException {
public:
	string msg;
	int errCode;
	StudentException(string msg, int code) :msg(msg), errCode(code) {

	}

};

class StudentClass;

class StudentList {
public:
	StudentClass** students;
	int noStudents;
};

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
		//cout << endl << "Calling the destructor";
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

		strcpy(this->studentName, anotherStudent.studentName);

		cout << endl << "The copy constructor";

		try {
			cout << endl << "Trying to copy the grades !";

			this->setFacultativeGrades(anotherStudent.facultativeExams,
				anotherStudent.noFacultativeCourses);

			cout << endl << "Done. Grades are cloned !";
		}
		catch (const char* err) {
			cout << endl << "We can't copy the facultative grades: " << err;
			this->facultativeExams = NULL;
			this->noFacultativeCourses = 0;
		}
		catch (int errCode) {
			cout << endl << "We can't copy the facultative grades. Error code: " << errCode;
			this->facultativeExams = NULL;
			this->noFacultativeCourses = 0;
		}
		catch (StudentException ex) {
			cout << endl << ex.msg << " Error code: " << ex.errCode;
			this->facultativeExams = NULL;
			this->noFacultativeCourses = 0;
		}
		catch (StudentException* ex) {
			cout << endl << ex->msg << " Error code: " << ex->errCode;
			this->facultativeExams = NULL;
			this->noFacultativeCourses = 0;
			delete ex;
		}
		catch (exception *ex) {
			cout << endl << ex->what();
		}
		catch (...) {
			cout << endl << "Oops ! An error";
		}

		try {
			this->setAddress(anotherStudent.studentAddress);
		}
		catch (...) {
			cout << endl << "Oops ! An error";
			this->studentAddress = NULL;
		}
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
			//throw "Wrong data";
			//throw -5;
			//throw StudentException("Null pointer received", -5);
			//throw new StudentException("Null pointer received", -5);
			throw new exception("NUll grades", 10);
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

		if (address != NULL && strlen(address) >= 3) {
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

	static StudentList loadStudents(string fileName) {
		ifstream input(fileName);
		if (input.is_open()) {

			StudentList list;
			input >> list.noStudents;
			list.students = new StudentClass*[list.noStudents];
			for (int i = 0; i < list.noStudents; i++) {
				int id;
				input >> id;
				char buffer[100];
				input.get();
				input.getline(buffer, 100);
				list.students[i] = new StudentClass(id, buffer);
				//thr address
				input.getline(buffer, 100);
				list.students[i]->setAddress(buffer);
				input.getline(buffer, 100);
				list.students[i]->highSchool = string(buffer);
				input >> list.students[i]->age;
				input >> list.students[i]->gender;

				//reading the mandatory grades
				input >> list.students[i]->noMandatoryCourses;
				for (int j = 0; j < list.students[i]->noMandatoryCourses; j++) {
					input >> list.students[i]->mandatoryExams[j];
				}

				//reading the facultative grades
				input >> list.students[i]->noFacultativeCourses;
				list.students[i]->facultativeExams = new int[list.students[i]->noFacultativeCourses];
				for (int j = 0; j < list.students[i]->noFacultativeCourses; j++) {
					input >> list.students[i]->facultativeExams[j];
				}
			}
			input.close();
			return list;
		}
		else
			throw exception("The file is not there !!!!!");

	}

	//method for serializing the objects
	void serialize(ofstream& file) {
		//write the name
		//file.write((char*)this->studentName, 50 * sizeof(char));
		file.write((char*)this->studentName, sizeof(this->studentName));
		//write the number of char from the address
		int noChars = strlen(this->studentAddress) + 1;
		file.write((char*)&noChars, sizeof(int));
		file.write(this->studentAddress, noChars);
		//highschool
		noChars = this->highSchool.size() + 1;
		file.write(this->highSchool.c_str(), noChars);
		//age
		file.write((char*)&this->age, sizeof(int));
		//gender
		file.write((char*)&this->gender, sizeof(char));
		//mandatory grades
		//number of grades
		file.write((char*)&this->noMandatoryCourses, sizeof(int));
		file.write((char*)this->mandatoryExams,
			sizeof(this->mandatoryExams));
		//facultative grades
		//number of grades
		file.write((char*)&this->noFacultativeCourses, sizeof(int));
		for (int i = 0; i < this->noFacultativeCourses; i++) {
			file.write((char*)&this->facultativeExams[i],
				sizeof(int));
		}
	}

	friend void operator<<(ostream& out, StudentClass& student);

};//the end 

//init the static attributes
int StudentClass::noStudents = 0;
float StudentClass::MINIMUN_ADMISSION_GRADE = 6;

void operator<<(ostream& out, StudentClass& student) {
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

	cout << student1;
	cout << student2;
	cout << endl << "******************************";


	StudentClass* *students;
	students = new StudentClass*[3];
	students[0] = &student1;
	students[1] = &student2;
	students[2] = new StudentClass(3, "Vader");
	for (int i = 0; i < 3; i++) {
		cout << endl << *students[i];
	}

	cout << endl << "****************************** FILE DATA";
	StudentList list = StudentClass::loadStudents("students.txt");
	for (int i = 0; i < list.noStudents; i++) {
		cout << endl << *list.students[i];
	}


	//save the data into a binary file
	ofstream backup("students.bin", ios::out | ios::binary);
	for (int i = 0; i < list.noStudents; i++) {
		int vb = 23;
		//don't use << because it converts everything to string
		//backup << vb;
		//backup.write((char*)&vb, sizeof(int));

		//NEVER LIKE THIS - IT'S WRONG
		//backup.write((char*)list.students[i], sizeof(StudentClass));
		list.students[i]->serialize(backup);
	}

	//backup.close();

	StudentList list2;
/*	ifstream inputF("students.bin", ios::in | ios::binary);
	if (inputF.is_open()) {
		inputF.seekg(0, ios::end);
		int fileSize = inputF.tellg();
		inputF.seekg(0, ios::beg);
		list2.noStudents = fileSize / sizeof(StudentClass);
		list2.students = new StudentClass*[list2.noStudents];
		for (int i = 0; i < list2.noStudents; i++) {
			list2.students[i] = new StudentClass(0, "John Doe");
			inputF.read((char*)list2.students[i], sizeof(StudentClass));
		}

		inputF.close();
	}
	else
		cout << endl << "//////////////////// File error*/";

	cout << endl << "****************************** BINARY FILE DATA";
	for (int i = 0; i < list2.noStudents; i++) {
		cout << endl << *list2.students[i];
	}

	cout << endl << "The end";
}