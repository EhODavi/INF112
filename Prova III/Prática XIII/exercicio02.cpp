#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char **argv) {
    unsigned int numDecimal;

    if (argc != 2) {
        cerr << "Erro, use:./exercicio02 numDecimal" << endl;
        exit(1);
    }

    numDecimal = atoi(argv[1]);

    int acumulador = 0;
    int potencia = 0;
    int contador = 1;
    for (int i = 0; i < 32; i++) {
        if ((numDecimal & (1 << i)) != 0) {
            acumulador += pow(2, potencia);
        }

        if (contador % 8 == 0) {
            cout << "A parte: " << (contador / 8) - 1 << " do numero " << numDecimal << " vale: " << acumulador << endl;
            acumulador = 0;
            potencia = 0;
        } else {
            potencia++;
        }

        contador++;
    }

    return 0;
}