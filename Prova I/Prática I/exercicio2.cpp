#include <iostream>

using namespace std;

int calculaTamanhoString1(char *a) {
    int quantidade = 0;

    for(int i = 0; a[i] != '\0'; i++) {
        quantidade++;
    }

    return quantidade;
    
}

int calculaTamanhoString2(char *a) {
    int quantidade = 0;

    for(int i = 0; *(a + i) != '\0'; i++) {
        quantidade++;
    }

    return quantidade;
}

int calculaTamanhoString3(char *a) {
    char *posicaoinicial = a;
    char *posicaofinal;

    for(char *ptr = a; *ptr != '\0'; ptr++) {
        posicaofinal = ptr;
    }

    posicaofinal++;

    return ((long)posicaofinal - (long)posicaoinicial) / sizeof(char);
}

int main() {
    char str[51];
    
    cout << "Digite alguma string... (com até 50 caracteres):";
    cin.getline(str, 50);
    
    cout << "Tamanhos calculados:" << endl;
    cout << calculaTamanhoString1(str) << " " << calculaTamanhoString2(str) << " " << calculaTamanhoString3(str) << endl;
   
    return 0;
}