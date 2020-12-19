#include <iostream>
#include <ctime>

using namespace std;

void preencheAleatorios(int *vetor, int n) {
    
    for(int i = 0; i < n; i++) {
        vetor[i] = rand() % 10;
    }
    
}

void imprime(int *vetor, int n) {
    for(int i = 0; i < n; i++) {
        cout << vetor[i] << ", ";
    }

    cout << endl;
} 

void contaParImpar(int *vetorA, int *vetorB, int n, int &par, int &impar) {
    for(int i = 0; i < n; i++) {
        if((vetorA[i] + vetorB[i]) % 2 == 0) {
            par++;
        } else {
            impar++;
        }
    }
}

int main() {
    int n;

    cout << "Digite a quantidade de jogadas a simular: ";
    cin >> n;

    while(n >= 0) {
        int *vetorA = new int[n];
        int *vetorB = new int[n];
        int par = 0, impar = 0;

        srand(time(0));

        preencheAleatorios(vetorA, n);
        preencheAleatorios(vetorB, n);

        imprime(vetorA, n);
        imprime(vetorB, n);

        contaParImpar(vetorA, vetorB, n, par, impar);

        cout << "Par: " << par << endl;
        cout << "Impar: " << impar << endl;

        delete []vetorA;
        delete []vetorB;

        cout << "Digite a quantidade de jogadas a simular: ";
        cin >> n;
    }

    return 0;
}