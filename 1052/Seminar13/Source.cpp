#include <iostream>
#include <string>

using namespace std;

int suma(int a, int b) {
	return a + b;
}

float suma(float a, float b) {
	return a + b;
}

float suma(double a, double b) {
	return a + b;
}

//functie template
template<typename X> X sumaT(X a, X b) {
	return a + b;
}

template<typename X, typename Y> X suma2(X a, Y b) {
	return a + b;
}

template<> string suma2(string a, int b) {
	return a + std::to_string(b);
}

template<typename T, typename P>
class Cutie {
	float greutate;
	float pret;
	T continut;
	P culoare;
public:
	Cutie(float Greutate, float Pret,
		T Continut, P Culoare) {
		this->greutate = Greutate;
		pret = Pret;
		continut = Continut;
		culoare = Culoare;
	}

	P getCuloare() {
		return this->culoare;
	}
};

class Frigider {
	float volum = 0;
};

class Floare {
	int nrPetale = 0;
};

void main() {
	cout << endl << "Suma dintre 2 si 3 este "
		<< suma(2, 3);
	cout << endl << "Suma dintre 2.2 si 3.2 este "
		<< suma(2.2f, (float)3.2);
	cout << endl << "Suma dintre 2.3 si 3.2 este "
		<< suma(2.3, 3.2);


	cout << endl << "* Suma dintre 2 si 3 este "
		<< sumaT<int>(2, 3);
	cout << endl << "* Suma dintre 2.2 si 3.2 este "
		<< sumaT(2.2f, (float)3.2);
	cout << endl << "* Suma dintre 2.3 si 3.2 este "
		<< sumaT(2.3, 3.2);
	cout << endl << "* Concatenare string-uri "
		<< sumaT<string>("Ana", " are mere!");

	cout << endl << "** Suma dintre 2 si 3 este "
		<< suma2<int, int>(2, 3);
	cout << endl << "** Suma dintre \"Test\" si 3 este "
		<< suma2<string, int>("Test", 3);

	Frigider f1;
	Cutie<Frigider, string> c1(30, 900, f1, "alb");
	Floare floare1;
	Cutie<Floare, int> c2(0.1, 5, floare1, 25500);
	cout << endl << "Culoare frigider " << c1.getCuloare();
	cout << endl << "Culoare floare " << c2.getCuloare();
}
