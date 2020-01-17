#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;


class Grade {
	int value;
	string course;
};
class IdCard {
	string serial;
	int no;
	string address;
private:
	IdCard() {

	}
public:
	IdCard(string Serial, int No) {
		address = "";
	}
};

template<typename T, typename P> class Student {
	int id;
	string name;
	IdCard card;
	T eyesColor;
	P *grades = NULL;
	int noGrades = 0;
public:
	Student():card("AA",0){

	}

	Student(int Id, string name,
		IdCard sCard, T color, P* Grades, int nGrades)
		:card(sCard), id(Id), name(name)
	{
		cout << endl << "COnstructor for template";
		eyesColor = color;
		grades = new P[nGrades];
		noGrades = nGrades;
		for (int i = 0; i < nGrades; i++)
			grades[i] = Grades[i];
	}
	
};

//specializing functions for particular types
template<> Student<char*, float>::Student(
	int Id, string name,
	IdCard sCard, char* color, float* Grades, int nGrades)
	:card(sCard), id(Id), name(name)
{

	cout << endl << "COnstructor for char* and float";
	eyesColor = new char[strlen(color) + 1];
	strcpy(eyesColor, color);
	grades = new float[nGrades];
	noGrades = nGrades;
	for (int i = 0; i < nGrades; i++)
		grades[i] = Grades[i];
}


//partial specialization

//template<typename P> class Student<char*, P> {
//public:
//	Student(
//		int Id, string name,
//		IdCard sCard, char* color, P* Grades, int nGrades)
//		:card(sCard), id(Id), name(name)
//	{
//
//		cout << endl << "COnstructor for char* and float";
//		eyesColor = new char[strlen(color) + 1];
//		strcpy(eyesColor, color);
//		grades = new float[nGrades];
//		noGrades = nGrades;
//		for (int i = 0; i < nGrades; i++)
//			grades[i] = Grades[i];
//	}
//};

class Flower {

	int id;
	string name = "";
	float price = 0;
public:
	Flower() {

	}

	Flower(int id, string Name, float Price) {
		name = Name;
		price = Price;
	}

	string getName() {
		return this->name;
	}

	int getId() {
		return id;
	}
};

int main() {

	IdCard card1("BB", 1);
	int* intGrades = new int[3]{ 9,9,9 };
	float* floatGrades = new float[3]{ 9,9,9 };
	Student<string, int> s1(1,"John",card1,"blue",intGrades,3);
	Student<char*, float> s2(1, "John", card1, (char*)"brown", floatGrades, 3);
	Student<char*, Grade> s3;

	vector<int> vectorOfNumbers;
	vectorOfNumbers.push_back(10);
	vectorOfNumbers.push_back(10);
	vectorOfNumbers.push_back(5);
	vectorOfNumbers.push_back(8);

	vector<string> vectorOfStrings;
	vectorOfStrings.push_back("Ana");
	vectorOfStrings.push_back("Alice");

	vector<Flower> flowers;
	flowers.push_back(Flower());
	flowers.push_back(Flower());
	flowers.push_back(Flower());

	vector<Flower*> pFlowers;
	pFlowers.push_back(new Flower());
	pFlowers.push_back(new Flower());
	pFlowers.push_back(new Flower());
	pFlowers.push_back(new Flower());

	cout << endl << "The numbers are :";
	for (int i = 0; i < vectorOfNumbers.size(); i++) {
		cout << " " << vectorOfNumbers[i];
	}

	set<int> uniqueNumbers;
	uniqueNumbers.insert(10);
	uniqueNumbers.insert(10);
	uniqueNumbers.insert(5);
	uniqueNumbers.insert(10);

	cout << endl << "The unique values are :";
	set<int>::iterator it;
	for (it = uniqueNumbers.begin();
		it != uniqueNumbers.end(); it++) {
		cout << " " << *it;
	}

	map<string, Flower> flowersMap;
	flowersMap["rose"] = Flower();
	flowersMap["daisy"] = Flower(1, "Daisy", 10);


	Flower f1(1, "Daisy", 10);
	Flower f2(3, "Rose", 20);


	map<int, Flower> flowersMap2;
	flowersMap2[100] = Flower();
	flowersMap2[200] = Flower(1, "Daisy", 10);

	map<int, Flower> flowersMap3;
	flowersMap3[f1.getId()] = f1;
	flowersMap3[f2.getId()] = f2;

	Flower floareCautata = flowersMap3[3];
	cout << endl << floareCautata.getName();
	cout << endl << flowersMap3[3].getName();

	map<int, string> students;
	students[1] = "John";
	students[1001] = "Alice";
	students[56] = "Bob";

	string studentName = students[89];
	cout << endl << "The student name is " << studentName;

}