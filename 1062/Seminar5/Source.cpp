
#include <string>
#include <iostream>
using namespace std;


class DeliveryVan {
private:
	std::string driverName;

public:
	int age = 0;
	char companyName[50];
	char* vanPlates = NULL;
private:
	int noCities = 0;
	string  *route = NULL;

public:
	string getDriverName() {
		return this->driverName;
	}

	void setDriverName(string newName) {
		if (newName.length() >= 2 &&
			newName.length() <= 50) {
			this->driverName = newName;
		}
		else
		{
			throw "Wrong name";
		}
			
	}

	void printData() {
		cout << endl << "The driver name is "
			<< this->driverName << " and its age is "
			<< this->age;

		if (this->vanPlates != NULL) {
			cout << endl << "Delivery van plates "
				<< this->vanPlates << " from " << this->companyName;
		}
		else
		{
			cout << endl << "The company is "
				<< this->companyName;
		}
		cout << endl << "The route is :";
		for (int i = 0; i < this->noCities; i++) {
			cout << this->route[i] << ", ";
		}
	}
};

int main() {

	DeliveryVan van1;
	DeliveryVan van2;

	DeliveryVan *pointerVan;
	pointerVan = &van1;


	van1.setDriverName("John");
	van2.setDriverName("Alice");

	cout << endl << "The driver name is " 
		<< van1.getDriverName();

	cout << endl << "The driver name is "
		<< van2.getDriverName();

	van1.age = 23;

	van1.printData();
	van2.printData();


}