#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class EmailException {
	string msg;
	int criticalLevel;
public:
	EmailException(string message, int critical)
		:msg(message), criticalLevel(critical) {

	}

	string getMessage() {
		return this->msg;
	}
	int getCriticalLevel() {
		return this->criticalLevel;
	}
};

class Email {
	const int id;
	string subject = "";
	char from[50] = "";
	char* content = NULL;
	string* to = NULL;
	int noDestinations = 0;
	bool* confirmations = NULL;
public:
	Email(int id, string subject):id(id) {
		this->subject = subject;
	}

	void operator+=(string address) {
		if (address.find("@") == -1)
			throw EmailException("Invalid address", 1);
		if (address.find(".") == -1)
			throw EmailException("Invalid address", 1);
		if(address.find("@") > address.find_last_of("."))
			throw EmailException("Invalid address", 1);

		string* newTo = new string[this->noDestinations + 1];
		bool* newConf = new bool[this->noDestinations + 1];

		for (int i = 0; i < this->noDestinations; i++) {
			newTo[i] = this->to[i];
			newConf[i] = this->confirmations[i];
		}

		newTo[this->noDestinations] = address;
		newConf[this->noDestinations] = false;

		delete[] this->to;
		delete[] this->confirmations;

		this->to = newTo;
		this->confirmations = newConf;

		this->noDestinations += 1;

	}

	void setFrom(const char* address) {
		if (address == NULL)
			throw EmailException("Empty address", 2);
		strcpy(this->from, address);
	}

	void operator<<(const char* text) {
		if (this->content != NULL) {
			char* newContent =
				new char[strlen(this->content) +
				strlen(text) + 1];

			strcpy(newContent, this->content);

			//newContent[0] = '\0';
			//strcat(newContent, this->content);
			strcat(newContent, text);
			delete[] this->content;
			this->content = newContent;
		}
		else
		{
			this->content = new char[strlen(text) + 1];
			strcpy(this->content, text);
		}
	}

	bool& operator[](string address) {
		int addressIndex = -1;
		for (int i = 0; i < this->noDestinations; i++) {
			if (address == this->to[i]) {
				addressIndex = i;
				break;
			}
		}

		if (addressIndex != -1)
			return this->confirmations[addressIndex];
		else
			throw EmailException("Unknown email", 1);
	}

	friend void operator<<(ostream& out, Email& email);
};

void operator<<(ostream& out, Email& email) {
	out << endl << "------------------";
	out << endl << "Email : " << email.id;
	out << endl << "Subject: " << email.subject;
	out << endl << "From: " << email.from;
	out << endl << "To: ";
	for (int i = 0; i < email.noDestinations; i++) {
		string confirmationMark =
			email.confirmations[i] == true ? "(*)" : "";
		out << email.to[i] << " " 
			<< confirmationMark << ";";
	}
	if (email.content != NULL)
		out << endl << email.content;
	else
		out << endl << "Empty content";
}

int main() {
	Email email1(1, "Exam subjects");
	email1.setFrom("me@email.com");
	email1 += "john@email.com";
	email1 += "alice@email.com";
	email1 << "Hello \n";
	email1 << "I have the subjects for the exam. Call me";
	
	email1["alice@email.com"] = true;
	email1["john@email.com"] = true;
	cout << email1;
}