#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main(int argc, char **argv) {
    char *numBinario;
    unsigned long long int numDecimal = 0;

    if (argc != 2) {
        cerr << "Erro, use:./exercicio01 numBinario" << endl;
        exit(1);
    }

    numBinario = argv[1];

    int potencia = strlen(numBinario) - 1;

    for (int i = 0; i < strlen(numBinario); i++) {
        if (numBinario[i] == '1')
            numDecimal += pow(2, potencia);

        potencia--;
    }

    cout << "O numero digitado é: " << numDecimal << endl;

    return 0;
}