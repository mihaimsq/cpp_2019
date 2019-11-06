#include <string>
#include <iostream>
using namespace std;

class Product {

private:
	std::string description;
	float price = 0;
	int quantity = 0;
	const int id;

	int *soldItemsPerInvoice = NULL;;
	int noInvoices = 0;

public:

	//default constructor
	Product():id(1) {
		//this->id = 1;
	}

	Product(string name,
		float price, int initialStock, int Id):id(Id) {
		this->description = name;
		this->price = price;
		this->quantity = initialStock;
	}

	int getStock() {
		return this->quantity;
	}
	float getPrice() {
		return this->price;
	}
	string getDescription() {
		return this->description;
	}

	void setDiscount(float discountValue) {
		if (discountValue >= 0.01 && discountValue <= 0.5)
			this->price -= this->price*discountValue;
		else
			throw "The discount value is wrong";
	}

	void sell(int noItems) {
		if (noItems <= 0 || noItems > 1000)
			throw "Wrong number of items";

		if (this->quantity < noItems)
			throw "Stock not available";

		int *newValues = new int[this->noInvoices + 1];
		for (int i = 0; i < this->noInvoices; i++)
			newValues[i] = this->soldItemsPerInvoice[i];

		newValues[this->noInvoices] = noItems;

		this->quantity -= noItems;
		this->noInvoices += 1;
		
		//avoid the memory leak
		delete[] this->soldItemsPerInvoice;

		this->soldItemsPerInvoice = newValues;



	}

	void printInfo() {
		cout << endl << " -----------------  ";
		cout << endl << this->id << " - " << this->description;
		cout << endl << "Unit price " << this->price;
		cout << endl << "Available stock " << this->quantity;

		if (this->noInvoices == 0) {
			cout << endl << "No data";
		}
		else
		{
			cout << endl << " Sold item per invoice:";
			for (int i = 0; i < this->noInvoices; i++)
				cout << this->soldItemsPerInvoice[i]
				<< " | ";
		}

	}
};

int main() {

	Product product1;
	Product product2("Laptop", 1200, 150, 2);

	product1.printInfo();
	product2.printInfo();

	product2.setDiscount(0.1);
	product2.printInfo();

	product2.sell(5);
	product2.sell(3);

	product2.printInfo();

	//for (;;) {
	//	Product *pointerProduct =
	//		new Product("PC", 1500, 100, 3);
	//	pointerProduct->sell(3);
	//	delete pointerProduct;
	//}


}