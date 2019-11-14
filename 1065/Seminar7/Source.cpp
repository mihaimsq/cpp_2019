#include <string>
#include <iostream>
using namespace std;

class Product {
private:
	std::string name = "No description";
	float price = 0;
	int availableStock = 0;

	int *noItemsPerInvoice = NULL;
	int noInvoices = 0;
public:
	const int id;
	const static int MAX_ITEMS;

private:
	Product():id(0) {

	}


public:

	Product(int Id, string name, float price, int initialStock)
		:id(Id) {
		this->name = name;
		this->price = price;
		this->availableStock = initialStock;
	}

	//the destructor
	~Product() {
		cout << endl << "Calling the DESTRUCTOR";
		if (this->noItemsPerInvoice != NULL)
			delete[] this->noItemsPerInvoice;
	}

	//copy constructor
	Product(const Product& existingOne):id(existingOne.id) {
		this->name = existingOne.name;
		this->price = existingOne.price;
		this->availableStock = existingOne.availableStock;

		//don't do that
		//this->noItemsPerInvoice = existingOne.noItemsPerInvoice;

		this->noItemsPerInvoice = new int[existingOne.noInvoices];
		this->noInvoices = existingOne.noInvoices;
		for (int i = 0; i < this->noInvoices; i++)
			this->noItemsPerInvoice[i] = existingOne.noItemsPerInvoice[i];

	}

	float getPrice() {
		return this->price;
	}
	int checkAvailableStock() {
		return this->availableStock;
	}

	float getStockValue() {
		return this->price * this->availableStock;
	}

	void setDiscount(float discountValue) {
		if (discountValue > 0 && discountValue < 1) {
			this->price -= this->price*discountValue;
		}
		else
		{
			throw "The discount is wrong !";
		}
	}

	void printData() {

		cout << endl << "------------------------";

		cout << endl << "Name: " << this->name;
		cout << endl << "Price: " << this->price;
		cout << endl << "Available stock: "
			<< this->availableStock;

		if (this->noInvoices > 0) {
			cout << endl << "No sold items per invoice: ";
			for (int i = 0; i < this->noInvoices; i++) {
				cout << this->noItemsPerInvoice[i] << " | ";
			}
		}
		else
			cout << endl << "There is no data";
	}

	void recordAnInvoice(int noItems) {
		int *newArray = new int[this->noInvoices + 1];
		for (int i = 0; i < this->noInvoices; i++) {
			newArray[i] = this->noItemsPerInvoice[i];
		}

		newArray[this->noInvoices] = noItems;

		delete[] this->noItemsPerInvoice;
		this->noItemsPerInvoice = newArray;
		this->noInvoices += 1;
		this->availableStock -= noItems;
	}

	Product operator+(int value) {
		Product copy = *this;
		copy.recordAnInvoice(value);
		return copy;
	}
};

const int Product::MAX_ITEMS = 100;

void someFunction() {
	Product product(1,"Laptop", 1200, 100);
}

void aFunction(Product p) {

}

Product anotherFunction() {
	Product product(1, "Laptop", 1200, 100);
	product.recordAnInvoice(2);
	product.recordAnInvoice(5);
	return product;
}

//Product operator+(Product p, int value) {
//	Product copy = p;
//	copy.recordAnInvoice(value);
//	return copy;
//}

int main() {

	//Product product1;

	Product product1(1, "Laptop", 1200, 100);

	//TO DO - put real names
	cout << endl << "The available stock is :"
		<< product1.checkAvailableStock();

	//testing the exception
	//product1.setDiscount(0);

	product1.setDiscount(0.2);
	cout << endl << "The new price is "
		<< product1.getPrice();

	product1.printData();

	product1.recordAnInvoice(2);
	product1.recordAnInvoice(5);

	product1.printData();

	//calling the destructor
	Product *productInHeap = new Product(2, "Phone", 1200, 100);
	delete productInHeap;

	cout << endl << "Calling a FUNCTION";

	someFunction();

	cout << endl << "The end";

	//aFunction(product1);
	anotherFunction();

	int vb1 = 10;
	vb1 = vb1 + 20;		//function+(vb1, 20)

	//adding an invoice with 10 items
	
	//product1.operator+(10);
	product1 = product1 + 10;	//Product operator+(Product, int)
	//increasing the price with 10
	product1 += 10;				//void operator+=(Product&, int)

	cout << product1;			//operator<<(ostream&, Product)
	cin >> product1;			//operator>>(istream&, Product&)

}