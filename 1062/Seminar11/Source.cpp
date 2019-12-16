#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
	char* description;
	float price;
public:
	Product(const char* description, float price) {
		this->description = 
			new char[strlen(description) + 1];
		strcpy(this->description, description);
		this->price = price;
	}

	//Product() {

	//}
	~Product(){
		delete[] this->description;
	}
	Product(const Product& p) {
		this->description =
			new char[strlen(p.description) + 1];
		strcpy(this->description, p.description);
		this->price = p.price;
	}
	void print() {
		cout << endl << "The product " <<
			this->description << " has a price of " <<
			this->price;
	}
};

class FoodProduct: public Product {
	char productionDate[11];	//dd/mm/yyyy
	int expirationTermInDays;

public:
	FoodProduct(): Product("",0) {

	}

	FoodProduct(const char* description,
		float price, int expirationTerm)
		:Product(description, price){
		//don't do this - it's not your job
		//this->price = price;
		//this->description =
		//	new char[strlen(description) + 1];
		//strcpy(this->description, description);
		this->expirationTermInDays = expirationTerm;
		strcpy(this->productionDate, "11/12/2019");
	}

	~FoodProduct() {
		/*delete[] this->description;*/
	}

	//overriding the base class function
	void print() {
		//cout << endl << "The product " <<
		//	this->description << " has a price of " <<
		//	this->price;

		this->Product::print();

		cout << endl << "Production date: " <<
			this->productionDate;
		cout << endl << "Expires in " <<
			this->expirationTermInDays;
	}
};

class Test {
	int vb;
};

class PromotionalFoodProduct : public FoodProduct {
	float discount;
};

int main() {
	Product p1("Laptop", 1200);
	p1.print();
	//p1.price = 23;

	FoodProduct fp1;
	FoodProduct fp2("Salad", 7.5, 3);
	Test t1;

	fp2.print();
	//fp2.price = 0;

	PromotionalFoodProduct pfp;
}