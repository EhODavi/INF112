#include <iostream>
#include <cstring>
#include "pessoa.h"

using namespace std;

int Pessoa::numInstancias = 0;

void Pessoa::printNumInstancias() {
	cout << numInstancias << endl;
}

Pessoa::Pessoa(char *nome, int idade) {
	this->nome = new char[strlen(nome) + 1];
	strcpy(this->nome, nome);
	this->idade = idade;
	numInstancias++;
}

Pessoa::Pessoa(const Pessoa &pessoa) {
	this->idade = pessoa.idade;
	this->nome = new char[strlen(pessoa.nome) + 1];
	strcpy(this->nome, pessoa.nome);
	numInstancias++;
}

Pessoa::~Pessoa() {
    delete[] this->nome;
}

Pessoa & Pessoa::operator=(const Pessoa &pessoa) {
	if (this == &pessoa) return *this;
	
	this->idade = pessoa.idade;
	
	delete[] this->nome;
	this->nome = new char[strlen(pessoa.nome) + 1];
	strcpy(this->nome, pessoa.nome);
	
	return *this;
}
		
void Pessoa::print() {
	cout << "[nome=\"" << nome << "\" , idade=" << idade << "]" << endl;
}