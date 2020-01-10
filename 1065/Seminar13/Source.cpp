#include <iostream>
#include <string>
using namespace std;

enum PetType {FISH, DOG=10, CAT=20, PARROT};

class InterfacePet {
public:
	virtual string getDescription() = 0;
	virtual float getMonthlyCost() = 0;
};

class Pet: public InterfacePet {
	string name;
	PetType type;
public:
	string getDescription() {
		string typeName = "";
		switch (this->type) {
		case PetType::CAT:
			typeName = "Cat";
			break;
		case DOG:
			typeName = "Dog";
			break;
		case FISH:
			typeName = "Fish";
			break;
		case PARROT:
			typeName = "Parrot";
			break;
		default:
			typeName = "Not known";
		}
		return name + " is a " + typeName;
	}

	float getMonthlyCost() {
		return -1;
	}

	Pet(string Name, PetType type) {
		this->name = Name;
		this->type = type;
	}
};

class Puppy : public Pet {
protected:
	float FoodCost;
public:
	float getMonthlyCost() {
		return this->FoodCost;
	}

	Puppy(): Pet("",PetType::DOG) {

	}

	Puppy(string name, float cost) : Pet(name, PetType::DOG) {
		this->FoodCost = cost;
	}
};

class Cat : public Pet {
protected:
	float cost;
	int noLives;
public:
	Cat(string Name, float Cost, int NoLives)
		: Pet(Name, PetType::CAT) {
		this->cost = Cost;
		this->noLives = NoLives;
	}

	string getDescription() {
		string msg = Pet::getDescription();
		string value = std::to_string(this->noLives);
		msg += (". It has " + value + " lives");
		return msg;
	}

};

int main() {
	//InterfacePet iPet;
	InterfacePet* petPointer;
	Pet pet1("Goldy",PetType::FISH);
	petPointer = &pet1;
	cout << endl << petPointer->getDescription();

	InterfacePet** pets;
	pets = new InterfacePet*[3];
	pets[0] = &pet1;
	pets[1] = new Puppy("Rex", 90);
	pets[2] = new Cat("Fluffy", 85, 9);

	for (int i = 0; i < 3; i++) {
		cout << endl << pets[i]->getDescription();
	}


	//Puppy p1;
}
