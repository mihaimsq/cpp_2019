#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class ExceptieEmail {
	string mesaj;
	int nivelCritic;
public:
	ExceptieEmail(string msj, int nivel) {
		this->nivelCritic = nivel;
		this->mesaj = msj;
	}
	string getMesaj() {
		return this->mesaj;
	}
	int getNivelCritic() {
		return this->nivelCritic;
	}
};

class Email {
	const int id;
	string subject = "";
	char from[50] = "";
	string *to = NULL;
	int nrDestinatari = 0;
	bool *confirmari = NULL;
	char* continut = NULL;

public:
	Email(int Id, string subiect):id(Id) {
		this->subject = subiect;
	}

	void operator+=(string adresa) {
		if (adresa.find("@") == -1)
			throw ExceptieEmail("Adresa invalida", 1);
		if (adresa.find(".") == -1)
			throw ExceptieEmail("Adresa invalida", 1);
		if(adresa.find("@") > adresa.find_last_of("."))
			throw ExceptieEmail("Adresa invalida", 1);

		string* newDestinatari =
			new string[this->nrDestinatari + 1];
		bool* newConfirmari =
			new bool[this->nrDestinatari + 1];

		for (int i = 0; i < this->nrDestinatari; i++) {
			newDestinatari[i] = this->to[i];
			newConfirmari[i] = this->confirmari[i];
		}

		newDestinatari[this->nrDestinatari] = adresa;
		newConfirmari[this->nrDestinatari] = false;

		delete[] this->to;
		delete[] this->confirmari;

		this->to = newDestinatari;
		this->confirmari = newConfirmari;

		this->nrDestinatari += 1;
	}

	void setFrom(const char* adresa) {
		strcpy(this->from, adresa);
	}

	void operator<<(const char* text) {
		if (this->continut != NULL) {
			char* continutNou =
				new char[strlen(this->continut) +
				strlen(text) + 1];

			//continutNou[0] = '\0';
			//strcat(continutNou, this->continut);

			strcpy(continutNou, this->continut);

			strcat(continutNou, text);

			delete[] this->continut;
			this->continut = continutNou;
		}
		else
		{
			this->continut = new char[strlen(text) + 1];
			strcpy(this->continut, text);
		}
	}

	bool& operator[](string adresa) {
		int indexAdresa = -1;
		for (int i = 0; i < this->nrDestinatari; i++) {
			if (adresa == this->to[i]) {
				indexAdresa = i;
				break;
			}
		}
		if (indexAdresa == -1)
			throw ExceptieEmail("Destinatar necunoscut", 2);
		else
			return this->confirmari[indexAdresa];
	}

	friend void operator<<(ostream& out, Email& e);
};

void operator<<(ostream& out, Email& e) {
	out << endl << "------------------";
	out << endl << "From: " << e.from;
	out << endl << "Subject: " << e.subject;
	out << endl << "To: ";

	for (int i = 0; i < e.nrDestinatari; i++) {
		string confirmare =
			e.confirmari[i] == true ? " (*)" : "";
		out << e.to[i] << confirmare << ";";
	}

	if (e.continut != NULL) {
		out << endl << e.continut;
	}
	else
		out << endl << "Fara continut";
}

int main() {
	//int vb= 0;
	//char buffer[1000];

	//cout << endl << "Valoare: ";
	//cin >> vb;
	//cout << endl << "Nume:";
	//cin.get();
	//cin.getline(buffer, 1000);

	//cout << endl << vb << " - " << buffer;

	Email email1(1, "Subiecte examen");
	email1 += "ana@email.com";
	email1 += "george@email.com";
	email1.setFrom("eu@email.com");

	email1 << "Salut !\n";
	email1 << "Am facut rost de subiecte. Suna-ma";

	email1["ana@email.com"] = true;

	cout << email1;

}