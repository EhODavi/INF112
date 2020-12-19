#include "Teste.h" 

int Teste::ct =0;

int Teste::getNumInstancias() {
	return ct;
}

Teste::Teste() {
	ct++;
}

Teste::~Teste() {
	ct--;
}    

