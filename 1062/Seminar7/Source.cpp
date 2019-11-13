#include <string>
#include <iostream>
using namespace std;

class Product {

private:
	std::string description;
	float price = 0;
	int quantity = 0;


	int *soldItemsPerInvoice = NULL;;
	int noInvoices = 0;

	const static int MAX_ITEMS;

public:
	const int id;

	//default constructor
	Product() :id(1) {
		//this->id = 1;
	}

	Product(string name,
		float price, int initialStock, int Id) :id(Id) {
		this->description = name;
		this->setPrice(price);
		this->quantity = initialStock;
	}

	//the destructor
	~Product() {
		if (this->soldItemsPerInvoice != NULL)
			delete[] this->soldItemsPerInvoice;
	}

	//this is not anymore the copy constructor
	//you must use the & version
	Product(const Product* product):id(product->id) {
		cout << endl << "Copy constructor";
		this->description = product->description;
		this->price = product->price;
		this->quantity = product->quantity;

		//the default way - it's not ok
		//this->soldItemsPerInvoice = product->soldItemsPerInvoice;

		if (product->soldItemsPerInvoice != NULL) {
			this->soldItemsPerInvoice =
				new int[product->noInvoices];
			for (int i = 0; i < product->noInvoices; i++)
				this->soldItemsPerInvoice[i] =
				product->soldItemsPerInvoice[i];

			this->noInvoices = product->noInvoices;
		}
		else
		{
			this->soldItemsPerInvoice = NULL;
			this->noInvoices = 0;
		}
	}

	Product(const Product& product) :id(product. id) {
		cout << endl << "Copy constructor";
		this->description = product.description;
		this->price = product.price;
		this->quantity = product.quantity;

		//the default way - it's not ok
		//this->soldItemsPerInvoice = product->soldItemsPerInvoice;

		if (product.soldItemsPerInvoice != NULL) {
			this->soldItemsPerInvoice =
				new int[product.noInvoices];
			for (int i = 0; i < product.noInvoices; i++)
				this->soldItemsPerInvoice[i] =
				product.soldItemsPerInvoice[i];

			this->noInvoices = product.noInvoices;
		}
		else
		{
			this->soldItemsPerInvoice = NULL;
			this->noInvoices = 0;
		}
	}

	void setPrice(int value) {
		if (value <= 0)
			throw "Price is wrong";
		else
			this->price = 0;
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
		if (noItems <= 0 || noItems > Product::MAX_ITEMS)
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

	friend void operator<<(ostream& out, Product p);
	friend void operator>>(istream& in, Product& p);
};

const int Product::MAX_ITEMS = 100;

void doSomething(Product p) {
}

Product doSomethingElse() {
	Product product2("Laptop", 1200, 150, 2);
	product2.sell(5);
	product2.sell(3);
	return product2;
}

void operator<<(ostream& out, Product p) {
	out << endl << " -----------------  ";
	out << endl << p.id << " - " << p.getDescription();
	out << endl << "Unit price " << p.getPrice();
	out << endl << "Available stock " << p.getStock();

	if (p.noInvoices == 0) {
		out << endl << "No data";
	}
	else
	{
		out << endl << " Sold item per invoice:";
		for (int i = 0; i < p.noInvoices; i++)
			out << p.soldItemsPerInvoice[i]
			<< " | ";
	}
}

void operator>>(istream& in, Product& p) {
	cout << endl << "The description is:";
	in >> p.description;
	cout << endl << "The price is:";
	in >> p.price;
	cout << endl << "The stock is:";
	in >> p.quantity;

	cout << endl << "The number of invoices is:";
	in >> p.noInvoices;

	//avoid the memory leak
	if (p.soldItemsPerInvoice != NULL)
		delete[] p.soldItemsPerInvoice;

	p.soldItemsPerInvoice = new int[p.noInvoices];
	for (int i = 0; i < p.noInvoices; i++) {
		cout << endl << "Previous sold items:";
		in >> p.soldItemsPerInvoice[i];
	}
}

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

	doSomething(product2);

	//explicit call to the copy constructor
	Product copy = product2;

	cout << product2;	//void operator<<(ostream&,Product)
	cin >> product1;	//void operator>>(istream&,Product&)

	int vb1 = 10;
	vb1 = vb1 + 20;		//int operator+(int, int)	


}