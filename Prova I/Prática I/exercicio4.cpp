#include <iostream>

using namespace std;

int main() {
    char str[] = "abc teste";

    char *posicaoinicial = str;
    char *posicaofinal;

    for(char *ptr = str; *ptr != '\0'; ptr++) {
        posicaofinal = ptr;
    }

    for(char *ptr = posicaofinal; ptr != (posicaoinicial - 1); ptr--) {
        cout << "(" << *ptr << ")";
    }

    cout << endl;
    
    return 0;
}