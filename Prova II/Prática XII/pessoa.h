#ifndef PESSOA_H
#define PESSOA_H

class Pessoa {	
	private:
		static int numInstancias;
		char *nome;
		int idade;

	public:
		Pessoa(char *nome, int idade);
		Pessoa(const Pessoa &);
		~Pessoa();
		Pessoa & operator=(const Pessoa &);
		void print();
		static void printNumInstancias();
};

#endif