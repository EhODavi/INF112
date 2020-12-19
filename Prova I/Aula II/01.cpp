// testar entradas com uma letra

#include <iostream>

using namespace std;

#define TAM_NOME 51

struct Pessoa {
    char *nome;
};

char *le_nome() {
    char nome[TAM_NOME];
    cin.getline(nome, TAM_NOME);
    return nome;
}

int main() {
    Pessoa p;
    p.nome = le_nome();
    cout << p.nome << endl;
    return 0;
}
