#include <string>
#include <iostream>

using namespace std;

class CurierPostal {
private:
	char nume[50];
	int varsta;

	std::string companie;
	char* adresaPunctLucru;

	int nrOrase;
	char* *traseu;

	//interfata publica a clasei
public:
	int getVarsta() {
		//cout << endl << "Iti trimit varsta ";
		return this->varsta;
	}

	void setVarsta(int valoare) {
		if (valoare >= 18 && valoare <= 90) {
			this->varsta = valoare;
		}
		else {
			throw "Valoare gresita";
		}
	}

};

int main() {

	//creare obiecte / instantiere clasa
	CurierPostal curier;
	CurierPostal curier2;

	//curier.varsta = -19;

	//cout << endl << "Numele curierului este "
	//	<< curier.nume;
	//cout << endl << "Varsta curierului este "
	//	<< curier.varsta;

	curier2.setVarsta(-19);

	cout << endl << "Varsta curierului 1 este "
		<< curier.getVarsta();
	cout << endl << "Varsta curierului 2 este "
		<< curier2.getVarsta();


}