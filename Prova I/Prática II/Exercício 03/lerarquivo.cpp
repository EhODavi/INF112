#include <iostream>

using namespace std;

void escrevercontrario(int *vetor, int contador) {
    for (int i = contador - 2; i >= 0; i--) {
        cout << vetor[i] << " ";
    }

    cout << endl;
    
}

int main() {
    int *vetor, numero, contador = 0;
    
    cin >> numero;
    contador++;

    vetor = (int*) malloc(contador * sizeof(int));

    while(numero != -1) {
        vetor = (int*) realloc(vetor, contador * sizeof(int));
        
        vetor[contador - 1] = numero;
        
        cin >> numero;
        
        contador++;
    }

    escrevercontrario(vetor, contador);

    free(vetor);

    return 0;
}