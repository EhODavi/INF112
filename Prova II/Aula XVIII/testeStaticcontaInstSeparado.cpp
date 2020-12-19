#include <iostream>
#include "Teste.h"

using namespace std;

int main() {
	cout << Teste::getNumInstancias() << endl;
	Teste t,a;
	cout << Teste::getNumInstancias() << endl;
	{
		Teste x;
		cout << Teste::getNumInstancias() << endl;
	}
	cout << Teste::getNumInstancias() << endl;

	return 0;
}
