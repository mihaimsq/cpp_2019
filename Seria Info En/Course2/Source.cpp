#include <stdio.h>
#include <string.h>
#include <string>

int main() {
	printf("\n Hello");

	int variable = 10;
	char character1 = 'a'; //97
	char character2 = 48; 
	//char character3 = "48";
	char character4[48];		//array
	char character5;
	//strcpy(character5,'48');
	char character6 = '48';	//take only 4

	//strings
	std::string name1;
	char* name2;
	//char name3[];
	char name4[10];

	//init strings
	name1 = "Alice";
	//name2 = "Bob";
	name2 = new char[strlen("Bob")+1];
	strcpy(name2, "Bob");
	//name4 = "Vader";
	//name4[] = "Vader";
	strcpy(name4, "Vader");




	printf("\n The number is %d", variable);
	printf("\n The char is %c", character2);

}