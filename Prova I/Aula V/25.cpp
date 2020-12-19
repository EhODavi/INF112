#include <iostream>
#include <cstring>

using namespace std;

int bin2dec(char *numero, int tam, int begin = 0) {
    if (begin == tam) return 0;
    return (numero[tam-begin-1] == '1') + 2 * bin2dec(numero,tam,begin+1);
}

int binary_to_decimal(char *num, int n) {
    if (n == 0)
        return (num[0] == '1'? 1: 0);
    return 2 * binary_to_decimal(num, n - 1) + (num[n] == '1'? 1: 0);
}

int main(){
    char v[32];
    cin >> v;
    int n = strlen(v);

    cout << bin2dec(v, n, 0);
    cout << endl;

    cout << binary_to_decimal(v, n - 1);
    cout << endl;

    return 0;
}
