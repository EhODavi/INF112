#include <iostream>

using namespace std;

int main() {
    int **matriz = new int*[100];

    for (int i = 0; i < 100; i++) {
        matriz[i] = new int[100];
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            matriz[i][j] = 0;
        }
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            cout << matriz[i][j] << " ";
        }

        cout << endl;
    }

    int contador = 1;

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            matriz[i][j] = contador;
            contador++;
        }
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            cout << matriz[i][j] << " ";
        }

        cout << endl;
    }

    for (int i = 0; i < 100; i++) {
        delete [] matriz[i];
    }

    delete [] matriz;

    return(0);
}