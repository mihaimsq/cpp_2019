#include <iostream>
#include <string>
using namespace std;

class A {
public:
	A() {
		cout << endl << "constr default A";
	}
	A(int vb) {
		cout << endl << "constr parametri A";
	}
};

class B: public A {
public:
	B() {
		cout << endl << "constr default B";
	}
	B(int vb) {
		cout << endl << "constr parametri B";
	}


};

class C: public B {
public:
	C(): B(5) {
		cout << endl << "constr default C";
	}
	C(int vb) {
		cout << endl << "constr parametri C";
	}

	C(const C & copie):B(copie),A(copie) {
		cout << endl << "constr copiere C";

	}
};

int main() {
	C c1;
	cout << endl << "---------------";
	C c2 = c1;
}