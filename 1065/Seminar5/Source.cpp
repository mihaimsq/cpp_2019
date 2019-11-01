#include <string>
#include <iostream>
using namespace std;

class DeliveryVan {
private:
	std::string driverName = "John Doe";
	int age = 0;
private:
	char company[50];
	char* address = NULL;
private:
	int noCities = 0;
	string *route = NULL;
public:
	int getDriverAge() {
		return this->age;
	}

	void setDriverName(string newName) {
		if (newName.length() >= 2 && newName.length() <= 50) {
			this->driverName = newName;
		}
		else
			throw "Wrong name. Too short or too long !";
	}

	string getDriverName() {
		return this->driverName;
	}

	void print() {
		cout << endl << "The driver name is " << this->driverName
			<< " and his/her age is " << this->age;

		if (this->address != NULL) {
			cout << endl << "The company is " << this->company
				<< " located in " << this->address;
		}
		else
		{
			cout << endl << "No address for " << this->company;
		}

		cout << endl << "The route is :";
		for (int i = 0; i < this->noCities; i++) {
			cout << this->route[i] << ", ";
		}
	}
};

int main() {
	//an object
	//create an object / create an instance of the class
	DeliveryVan van1;
	DeliveryVan van2;

	van1.setDriverName("Bob");
	van2.setDriverName("Alice");

	//van1.age = -19;
	cout << endl << "The driver 1 name is " << van1.getDriverName()
		<< " and his/her age is " << van1.getDriverAge();

	cout << endl << "The driver 2 name is " << van2.getDriverName()
		<< " and his/her age is " << van2.getDriverAge();

	van1.print();
	van2.print();
}