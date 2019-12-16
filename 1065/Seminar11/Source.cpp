#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
	char* description;
	float price;
public:
	Product(const char* desc, float price) {
		this->description =
			new char[strlen(desc) + 1];
		strcpy(this->description, desc);
		this->price = price;

		cout << endl << "Product constructor with args";
	}

	//Product() {
	//	cout << endl << "Product default constructor";
	//}

	~Product() {
		delete[] this->description;
	}
	Product(const Product& p) {
		this->description = 
			new char[strlen(p.description) + 1];
		strcpy(description, p.description);
		this->price = price;
	}
	void print() {
		cout << endl << this->description
			<< " has a price of " << this->price;
	}
};

//inheritance
class FoodProduct: public Product {
	char prodDate[11];	// dd/mm/yyyy
	int availabilityInDays;

public:
	void something() {
		this->price = 0;
		this->print();
	}

	FoodProduct():Product("",0){
		cout << endl << "FoodProduct default constructor";
	}

	FoodProduct(const char* Description, float Price,
		int expDays):Product(Description,Price) {
		cout << endl << "FoodProduct constr with args";
		//this->description =
		//	new char[strlen(Description) + 1];
		//strcpy(this->description, Description);
		//this->price = Price;
		this->availabilityInDays = expDays;
		strcpy(this->prodDate, "12/12/2019");
	}

	~FoodProduct(){
		//don't do it
		//this is the job of the parent class destructor
		//delete[] this->description;
	}
};

class Test {

};

int main() {
	//Product p1("Laptop", 1200);
	//Product p2("Salad", 7.6);

	////p2.price = 10;

	//p1.print();
	//p2.print();

	//Test t;

	FoodProduct fp("Salad",7.6,3);
	fp.print();
	//fp.price = 0;

}