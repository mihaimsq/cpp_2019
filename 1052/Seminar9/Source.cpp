#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ExceptieEmail {
public:
	string mesaj;
	int codEroare;

	ExceptieEmail(string msj, int cod) {
		this->mesaj = msj;
		this->codEroare = cod;
	}
};

class Email {
	const int id;
	string subject = "";
	char from[50] ="";
	string *to = NULL;
	int nrAdrese = 0;
	bool *confirmari = NULL;
	char* continut = nullptr;
public:
	Email(int id, string subiect):id(id) {
		this->subject = subiect;
	}

	void setFrom(const char* adresa) {
		if (adresa != NULL && strlen(adresa) <= 49) {
			strcpy(this->from, adresa);
		}
		else
			//throw "Adresa gresita";
			//throw 10;	//cod eroare
			//throw new ExceptieEmail("Eroare adresa from", 10);
			throw ExceptieEmail("Eroare adresa from", 10);
	}

	void operator+=(string adresa) {
		int indexAt = adresa.find("@");
		int indexPunct = adresa.find(".");

		if (indexAt == -1 || indexPunct == -1) {
			throw ExceptieEmail("Adresa gresita", 5);
		}
		if(indexAt > adresa.find_last_of("."))
			throw ExceptieEmail("Adresa gresita", 5);

		string* newTo = new string[this->nrAdrese + 1];
		bool* newConf = new bool[this->nrAdrese + 1];

		for (int i = 0; i < this->nrAdrese; i++) {
			newTo[i] = this->to[i];
			newConf[i] = this->confirmari[i];
		}

		newTo[this->nrAdrese] = adresa;
		newConf[this->nrAdrese] = false;

		delete[] this->to;
		delete[] this->confirmari;

		this->to = newTo;
		this->confirmari = newConf;

		this->nrAdrese += 1;
	}

	void operator<<(const char* text) {

	}

	bool& operator[](string adresa) {

	}

	friend void operator<<(ostream& out, Email& email);
};

void operator<<(ostream& out, Email& email) {
	out << endl << "-------------------------";
	out << endl << "Id: " << email.id;
	out << endl << "Subject: " << email.subject;
	out << endl << "From: " << email.from;
	out << endl << "To: ";
	for (int i = 0; i < email.nrAdrese; i++) {
		string confirmare = "";
		confirmare = email.confirmari[i] == true ? "(*)" : "";
		out << email.to[i] << confirmare << "; ";
	}
	if (email.continut != NULL) {
		out << email.continut;
	}
	else
		out << endl << "Fara continut";

}

int main() {
	Email email1(1, "Subiecte examen");
	email1.setFrom("eu@email.com");

	try {
		cout << endl << "Incerc sa modific adresa from";
		email1.setFrom(NULL);
		//email1.setFrom("ana@email.com");
		cout << endl << "Am reusit";
	}
	catch (const char* mesaj) {
		cout << endl << "Eroare: " << mesaj;
	}
	catch (int codEroare) {
		cout << endl << "Eroare cu codul: " << codEroare;
	}
	catch (ExceptieEmail* ex) {
		cout << endl << ex->mesaj << " - " << ex->codEroare;
		delete ex;
	}
	catch (...) {
		cout << endl << "O eroare !";
	}

	email1 += "ana@email.com";
	email1 += "george@email.com";

	//email1 << "Salut ! \n";
	//email1 << "Suna-ma. Am subiectele de la examen";

	//email1["ana@email.com"] = true;


	cout << email1;

	string nume;
	string test;
	int vb, vb2;

	cout << endl << "nume: ";
	cin >> nume;
	cout << endl << "test: ";
	cin >> test;
	cout << endl << "vb: ";
	cin >> vb;
	cout << endl << "vb2: ";
	cin >> vb2;

	cout << nume << " - " << test << " - " << vb;

}