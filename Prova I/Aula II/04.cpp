#include <iostream>
#include <cstdio>

using namespace std;

#define TAM_NOME 51

struct Pessoa {
    char *nome;
};

void faz_nada() {
    char x[50];
    x[0] = 72;
    x[1] = 97;
    x[2] = 104;
    x[3] = 97;
    x[4] = 33;
    for (int i = 5; i < 50; i++)
        x[i] = 0;
    printf("Endereco que x comeca %p\n", &x[0]);
}

char *le_nome() {
    char nome[TAM_NOME];
    cin.getline(nome, TAM_NOME);
    printf("Endereco que nome comeca %p\n", nome);
    return nome;
}

int main() {
    Pessoa p;
    p.nome = le_nome();
    cout << "Primeira vez: " << p.nome << endl;
    faz_nada();
    cout << "Segunda vez: " << p.nome << endl;
    return 0;
}
