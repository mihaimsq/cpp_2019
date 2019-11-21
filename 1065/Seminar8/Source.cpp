#include <string>
#include <iostream>
using namespace std;

class Product {
	string description = "";
	float price = 0;
	int quantity = 0;

	int *itemsPerInvoice = NULL;
	int noInvoices = 0;

public:
	Product(string description, float price, int stock)
		:price(price), quantity(stock) {
		this->description = description;

		this->itemsPerInvoice = NULL;
		this->noInvoices = 0;
	}

	void operator+=(int items) {
		int* newInvoices = new int[this->noInvoices + 1];
		for (int i = 0; i < this->noInvoices; i++) {
			newInvoices[i] = this->itemsPerInvoice[i];
		}
		newInvoices[this->noInvoices] = items;
		delete[] this->itemsPerInvoice;
		this->itemsPerInvoice = newInvoices;
		this->noInvoices += 1;
		this->quantity -= items;
	}

	void operator-=(int priceReduction) {
		if (priceReduction >= this->price)
			throw "Wrong value";
		this->price -= priceReduction;
	}

	explicit operator float() {
		return this->price * this->quantity;
	}

	friend ostream& operator<<(ostream& out, Product& p);
	friend istream& operator>>(istream& in, Product& p);
};

ostream& operator<<(ostream& out, Product& p) {
	out << endl << "----------------------";
	out << endl << "Product description: " << p.description;
	out << endl << "Product price: " << p.price;
	out << endl << "Product quantity: " << p.quantity;

	if (p.noInvoices != 0) {
		out << endl << "Previous sold items: ";
		for (int i = 0; i < p.noInvoices; i++) {
			out << p.itemsPerInvoice[i] << " | ";
		}
	}
	return out;
}

istream& operator>>(istream& in, Product& p) {
	cout << endl << "New description: ";
	in >> p.description;
	cout << endl << "New price: ";
	in >> p.price;
	cout << endl << "New quantity: ";
	in >> p.quantity;
	cout << endl << "Number of invoices to insert: ";
	in >> p.noInvoices;

	if(p.itemsPerInvoice != NULL)
		delete[] p.itemsPerInvoice;
	p.itemsPerInvoice = new int[p.noInvoices];
	cout << endl << "Invoices data:";
	for (int i = 0; i < p.noInvoices; i++) {
		cout << endl << "Invoice " << i + 1 << ":";
		in >> p.itemsPerInvoice[i];
	}
	return in;
}

int main() {
	Product prod1("Laptop", 1200, 100);
	Product prod2("Phone", 990, 100);
	cout << prod1 << prod2;
	//cout << prod2;
	cin >> prod2;
	cout << prod2;
	prod2 += 3;
	cout << prod2;
	prod2 -= 10;

	float productStockValue = (float)prod2;

	//int test = prod2 + 5;

}