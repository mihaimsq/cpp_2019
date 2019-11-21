#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Product {
public:
	string name;
	int quantity = 0;
	float price = 0;

	int *quantityPerInvoice = NULL;
	int noInvoices = 0;

public:
	Product(string name, int quantity, float price)
		:price(price), quantity(quantity) {
		this->name = name;

		this->quantityPerInvoice = NULL;
		this->noInvoices = 0;
	}

	Product() {

	}

	~Product() {
		if (this->quantityPerInvoice != NULL)
			delete[] this->quantityPerInvoice;
	}

	friend ostream& operator<<(ostream& out, Product& p);
};

ostream& operator<<(ostream& out, Product& p) {
	out << endl << "---------------------------";
	out << endl << "Product name: " << p.name;
	out << endl << "Product price: " << p.price;
	out << endl << "Product quantity: " << p.quantity;

	if (p.noInvoices != 0) {
		out << endl << "Sold items: ";
		for (int i = 0; i < p.noInvoices; i++) {
			out << p.quantityPerInvoice[i] << " | ";
		}
	}
	else
		out << endl << "No data";

	return out;
}

int main() {
	Product product1("Laptop", 100, 1200);
	Product product2("Phone", 100, 990);
	cout << product1 << product2;

	//text files
	ofstream textReport("products.txt");
	textReport << product1;
	textReport << product2;
	textReport.close();

	//reading the text file
	ifstream inputFile("products.txt");
	if (inputFile.is_open()) {
		string fileLine;
		char buffer[100];

		while (!inputFile.eof()) {
			//inputFile >> fileLine;	//stops on space
			inputFile.getline(buffer,100);
			fileLine = string(buffer);

			//check for the line with the price
			if (fileLine.find("price")!= - 1) {
				int indexPrice = fileLine.find(":") + 2;
				int noChars = fileLine.length() - indexPrice;
				string price = fileLine.substr(indexPrice, noChars);
				cout << endl << "Price: " << price;
				int priceValue = stoi(price);
				cout << endl << "Price: " << priceValue;
			}

			cout << endl << "File line: " << fileLine;
		}
		inputFile.close();
	}
	else
		cout << endl << " **************** No file ";

	//reading products data from the file
	Product products[5];
	int noProducts;

	ifstream  data("input.txt");
	if (data.is_open()) {

		data >> noProducts;
		for (int i = 0; i < noProducts; i++) {
			char buffer[100];
			data.get();
			data.getline(buffer, 100);
			products[i].name = string(buffer);
			data >> products[i].price;
			data >> products[i].quantity;
			data >> products[i].noInvoices;
			if (products[i].noInvoices != 0) {
				products[i].quantityPerInvoice =
					new int[products[i].noInvoices];
				for (int j = 0; j < products[i].noInvoices; j++) {
					data >> products[i].quantityPerInvoice[j];
				}
			}

		}

		data.close();
	}


	cout << endl << "The file products are :";
	for (int i = 0; i < noProducts; i++)
		cout << products[i];

	cout << endl << "The end";
}