#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Floare {
	char* nume;
	float pret;
	int* stoc;
	int nrMagazine;
public:
	Floare(const char* Nume, float Pret,
		int* Stoc, int NrMagazine) {
		nume = new char[strlen(Nume) + 1];
		strcpy(nume, Nume);
		pret = Pret;
		if (NrMagazine > 0) {
			stoc = new int[NrMagazine];
			nrMagazine = NrMagazine;
			for (int i = 0; i < nrMagazine; i++) {
				stoc[i] = Stoc[i];
			}
		}
		else
		{
			this->nrMagazine = 0;
			this->stoc = NULL;
		}
	}

	static Floare** incarcaFlori(
		string numeFisier, int& nrFlori) {
		ifstream fisier(numeFisier);
		if (!fisier.is_open()) {
			cout << endl << "Fisierul nu exista";
			return NULL;
		}

		//citim numarul de flori
		fisier >> nrFlori;
		Floare** vector = new Floare*[nrFlori];
		//citim datele florilor
		for (int i = 0; i < nrFlori; i++) {
			char nume[1000];
			fisier >> nume;
			float pret;
			fisier >> pret;
			int nrMagazine;
			fisier >> nrMagazine;
			int * stoc;
			if (nrMagazine > 0) {
				stoc = new int[nrMagazine];
				for (int j = 0; j < nrMagazine; j++) {
					fisier >> stoc[j];
				}
			}
			else
			{
				nrMagazine = 0;
				stoc = NULL;
			}

			vector[i] = 
				new Floare(nume, pret, stoc, nrMagazine);
		}

		return vector;

	}
};

int main() {
	//Floare flori[3];
	//Floare *flori;
	//flori = new Floare[3];

	Floare* *pFlori;
	pFlori = new Floare*[3];
	int* stoc = new int[3]{ 100,90,50 };

	pFlori[0] = new Floare("Trandafir", 10, stoc, 3);
	pFlori[1] = new Floare("Margareta", 5, stoc, 3);
	pFlori[2] = new Floare("Lalea", 7, stoc, 3);

}