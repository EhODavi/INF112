#include <iostream>
#include <cmath>

using namespace std;

void printBinRecursivo(int n) {
    if (n == 0)
        return;
    printBinRecursivo(n / 2);
    cout << n % 2;
}

void printBinRecursivoReverse(int n) {
    if (n == 0)
        return;
    cout << n % 2;
    printBinRecursivo(n / 2);
}

int countBits(int n) {
    if (n < 2)
        return 1;
    return 1 + countBits(n / 2);
}

int countBits2(int n) {
    if (n == 0)
        return 1;
    return (int) log2(n) + 1;
}

int main() {
    int n;
    cin >> n;
    printBinRecursivo(n);
    cout << endl;
    printBinRecursivoReverse(n);
    cout << endl;
    cout << countBits(n);
    cout << endl;
    cout << countBits2(n);
    cout << endl;
    return 0;
}

