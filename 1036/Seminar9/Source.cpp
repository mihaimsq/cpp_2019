#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class ExceptieEmail {
	string mesaj;
	int nivelCritic;

public:
	ExceptieEmail(const char* mesaj, int nivel) {
		this->nivelCritic = nivel;
		this->mesaj = string(mesaj);
	}

	string getMesaj() {
		return this->mesaj;
	}

	int getNivel() {
		return this->nivelCritic;
	}
};

class Email {
	const int id;
	char from[50] = "";
	char* continut = NULL;
	string subject = "";
	string* to = NULL;
	int nrDestinatari = 0;
	bool* confirmariPrimire = NULL; //index-ul este similar cu cel din lista de destinatari
public:
	Email(int id, string subject) :id(id) {
		this->subject = subject;
	}

	void operator+=(const char* adresa) {
		if (adresa == NULL)
			throw new ExceptieEmail("Adresa lipsa", 5);
		string destinatar = string(adresa);
		if (destinatar.find("@") == -1)
			throw new ExceptieEmail("Adresa invalida", 1);
		if (destinatar.find(".") == -1)
			throw new ExceptieEmail("Adresa invalida", 1);
		if (destinatar.find("@") > destinatar.find_last_of("."))
			throw new ExceptieEmail("Adresa invalida", 1);

		string* newTo = new string[this->nrDestinatari + 1];
		bool* newConfirmari = new bool[this->nrDestinatari + 1];

		for (int i = 0; i < this->nrDestinatari; i++) {
			newTo[i] = this->to[i];
			newConfirmari[i] = this->confirmariPrimire[i];
		}

		newTo[this->nrDestinatari] = destinatar;
		newConfirmari[this->nrDestinatari] = false;

		this->nrDestinatari += 1;

		//evitam memory leak-uri
		delete[] this->confirmariPrimire;
		delete[] this->to;

		this->confirmariPrimire = newConfirmari;
		this->to = newTo;
	}

	void editareContinut(const char* continut) {
		if (this->continut != NULL) {
			char* continutNou = new char[strlen(this->continut) +
				strlen(continut) + 1];

			continutNou[0] = '\0';
			strcat(continutNou, this->continut);

			//strcpy(continutNou, this->continut);
			strcat(continutNou, continut);
			delete[] this->continut;
			this->continut = continutNou;
		}
		else
		{
			this->continut = new char[strlen(continut) + 1];
			strcpy(this->continut, continut);
		}
	}

	void setFrom(const char* adresa) {
		strcpy(this->from, adresa);
	}

	bool& operator[](string email) {
		int indexCautat = -1;
		for (int i = 0; i < this->nrDestinatari; i++) {
			if (email == this->to[i]) {
				indexCautat = i;
				break;
			}
		}

		if (indexCautat != -1) {
			return this->confirmariPrimire[indexCautat];
		}
		else 
			throw new ExceptieEmail("Destinatar invalid", 2);
	}


	friend void operator<<(ostream& out, Email& email);
};

void operator<<(ostream& out, Email& email) {
	out << endl << "-------------------";
	out << endl << "From: " << email.from;
	out << endl << "To: ";
	for (int i = 0; i < email.nrDestinatari; i++) {
		string confirmat = 
			email.confirmariPrimire[i] ? "(V)" : "";
		out << email.to[i] << confirmat << " ; ";
	}
	out << endl << "Subject: " << email.subject;
	out << endl << "Email: " << email.continut;

}

int main() {
	Email email1(1,"Subiecte examen");
	try {
		email1 += "gigel@email.com";
		email1 += "ana@gmail.com";
		email1.setFrom("me@email.com");
		email1.editareContinut("Salut, ");
		email1.editareContinut("\n Vezi ca ne da fisiere la examen");

		email1["ana@gmail.com"] = true;


		cout << email1;
	}
	catch (ExceptieEmail* ex) {
		cout << endl << ex->getMesaj() << " cu nivel " << ex->getNivel();
	}
	catch (...) {
		cout << endl << "Exceptie generica";
	}
}