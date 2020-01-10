#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
using namespace std;

enum TipPrioritate {URGENT, PRIORITAR = 100, NORMAL };


template <typename T> class Colet {
public:
	TipPrioritate  prioritate;
	bool areContinutAlimentar;
	T continut;

	char* getPrioritate() {
		if (this->prioritate == 101)	//normal
		{
			return new char[8] {"normala"};
		}
	}

	string getPrioritate2() {
		if (this->prioritate == 101)	//normal
		{
			string mesaj = "normala";
			return mesaj;
		}
		else
			return "urgent";
	}

	Colet(TipPrioritate p, bool esteAlimentar, const T c) {
		cout << endl << "Varianta generica constructor template";
		this->prioritate = p;
		this->areContinutAlimentar = esteAlimentar;
		//nu merge daca T este char*
		this->continut = c;
	}
};

//specializare pentru constructor atunci cand T este char*
//Colet<char*>::Colet(TipPrioritate p, bool esteAlimentar, const char* c) {
//	cout << endl << "Varianta specializata constructor template pentru char*";
//	this->prioritate = p;
//	this->areContinutAlimentar = esteAlimentar;
//	this->continut = new char[strlen(c)+1];
//	strcpy(this->continut, c);
//}


int suma(int a, int b) {
	return a + b;
}

float suma(float a, float b) {
	return a + b;
}

//functie template
template<typename X> X sumaGenerica(X a, X b) {
	return a + b;
}

template<typename X, typename Y, typename Z> Z sumaGenerica2(X a, Y b) {
	return a + b;
}

int schimbaValoare(int variabila) {
	variabila = 100;
	return variabila;
}

class Frigider {
	int greutate = 0;
	char* marca = NULL;
};

int main() {
	Colet<string> c1(TipPrioritate::PRIORITAR, false, "O carte");
	//c1.prioritate = TipPrioritate::NORMAL;

	Colet<int> coletNumar(TipPrioritate::NORMAL, false, 10);
	Frigider f1;
	Colet<Frigider> coletFrigider(TipPrioritate::NORMAL, false, f1);

	//Colet<char*> coletSirDinamic(TipPrioritate::PRIORITAR, false, "O carte");

	//c1.prioritate = "normal";

	//nu e ok
	//c1.areContinutAlimentar = "true";
	//c1.areContinutAlimentar = "false";

	//inca nu e ok
	//c1.areContinutAlimentar = 1;
	//c1.areContinutAlimentar = 0;

	//e ok
	c1.areContinutAlimentar = true;
	c1.areContinutAlimentar = false;

	cout << endl << "Prioritatea coletului este " << c1.getPrioritate2();

	float rezultat = sumaGenerica<float>(2.3, 3);
	rezultat = sumaGenerica<int>(2, 3);

	double rez = sumaGenerica2<int, float, double>(2, 4.5);

	cout << endl << "Rezultatul este : " << rezultat;

	int vb = 10;
	vb = schimbaValoare(vb);
	cout << endl << vb;
}