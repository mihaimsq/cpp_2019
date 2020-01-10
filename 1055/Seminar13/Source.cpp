#include <iostream>
#include <string>
using namespace std;

enum TipPet {PESTISOR = 10, CATEL = 20, PISICA, PAPAGAL = 30};

class InterfataAnimalCompanie {
public:
	virtual string getDescriere() = 0;
	virtual int costIntretinere() = 0;
};

class AnimalCompanie: public InterfataAnimalCompanie {
protected:
	string nume;
	TipPet tip;
public:
	virtual string getDescriere() {
		string tipPet = "";
		switch (this->tip) {
			case TipPet::CATEL:
				tipPet = "catel";
				break;
			case TipPet::PAPAGAL:
				tipPet = "papagal";
				break;
			case PISICA:
				tipPet = "pisica";
				break;
			case PESTISOR:
				tipPet = "pestisor";
				break;
			default:
				tipPet = "necunoscut";
		}
		return "Animalul de companie " + nume + " este un/o " 
			+ tipPet;
	}
	virtual int costIntretinere() {
		return -1;
	}

	AnimalCompanie(string Nume, TipPet Tip) {
		this->nume = Nume;
		tip = Tip;
	}
};

class PestisorAuriu : public AnimalCompanie {
public:
	float costLunar;

	PestisorAuriu(string nume, float Cost)
		: AnimalCompanie(nume, TipPet::PESTISOR) {
		this->costLunar = Cost;
	}

	int costIntretinere() {
		return this->costLunar;
	}
};

class PisicaBirmaneza : public AnimalCompanie {
	float cost;
	int nrVieti;
public:
	PisicaBirmaneza(string Nume, float Cost, int NrVieti)
		:AnimalCompanie(Nume,TipPet::PISICA) {
		this->cost = Cost;
		nrVieti = NrVieti;
	}

	int costIntretinere() {
		return this->cost;
	}

	string getDescriere() {

		string vieti = std::to_string(nrVieti);
		return "Pisica " + nume + " are " + vieti + " vieti ";
	}
};

int main() {

	AnimalCompanie a1("Silver",TipPet::CATEL);
	cout << endl << a1.getDescriere();
	//InterfataAnimalCompanie i1;

	InterfataAnimalCompanie *pI;
	pI = &a1;

	PestisorAuriu pa1("Goldy",30);
	PisicaBirmaneza pb1("Pufy", 90, 9);

	InterfataAnimalCompanie** pets;
	pets = new InterfataAnimalCompanie*[3];
	pets[0] = new AnimalCompanie("Rex", TipPet::CATEL);
	pets[1] = &pa1;
	pets[2] = &pb1;

	for (int i = 0; i < 3; i++) {
		cout << endl << pets[i]->getDescriere();
		cout << endl << "Costul lunar de intretinere este "
			<< pets[i]->costIntretinere();
	}

}

