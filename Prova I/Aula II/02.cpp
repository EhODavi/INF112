// testar entradas com uma letra

#include <iostream>

using namespace std;

#define TAM_NOME 51

struct Pessoa {
    char *nome;
};

void faz_nada() {
    int x[100000];
    for (int i = 0; i < 100000; i++)
        x[i] = 0;
}

char *le_nome() {
    char nome[TAM_NOME];
    cin.getline(nome, TAM_NOME);
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
