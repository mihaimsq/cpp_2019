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

private:
	Product() {

	}


public:

	Product(string name, float price, int initialStock) {
		this->name = name;
		this->price = price;
		this->availableStock = initialStock;
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
};

int main() {

	//Product product1;

	Product product1("Laptop", 1200, 100);

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

}