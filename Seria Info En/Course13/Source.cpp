#include <iostream>
#include <string>

using namespace std;

int sum(int a, int b) {
	return a + b;
}

float sum(float a, float b) {
	return a + b;
}

double sum(double a, double b) {
	return a + b;
}

template<typename X> X templateSum(X a, X b) {
	return a + b;
}

void* genericSum(void* a, void* b) {
	double* rez = new double();
	*rez = *((double*)a) + *((double*)b);
	return rez;
}

template <typename T, typename P> class Box {
	float weight;
	T content;
	P color;
public:
	Box(T content, P color) {
		this->color = color;
		this->content = content;
	}

	P getColor() {
		return color;
	}
};

class Fridge {

};

int main() {
	cout << endl << "Sum of 2 + 3 is " << sum(2, 3);
	cout << endl << "Sum of 2.1 + 3.2 is " << sum(2.1f, 3.2f);
	cout << endl << "Sum of 2.1 + 3.2 is " << sum(2.1, 3.2);

	double vb1 = 2.1;
	double vb2 = 3.2;
	cout << endl << "Sum of 2 + 3 is " << *((double*)genericSum(&vb1, &vb2));

	cout << endl << "Template Sum of 2 + 3 is " << templateSum(2, 3);
	cout << endl << "Template Sum of 2.2 + 3.3 is " << templateSum(2.2, 3.3);
	cout << endl << "Template Sum of 2.2 + 3.3 is " << templateSum(2.2, 3.3);
	cout << endl << "Template Sum of 1 + 2 is "  << (int)templateSum<char>(1, 2);
	cout << endl << "Template Sum of 1 + 2 is "  
		<< templateSum<string>("Alice", " is happy");

	Fridge f1;
	Box<Fridge,string> box1(f1, "white");
	cout << endl << "The color is " << box1.getColor();
	Box<string, float> box2("Letter", 1234);
	cout << endl << "The color is " << box2.getColor();
}