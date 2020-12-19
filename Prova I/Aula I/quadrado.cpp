#include <iostream>

using namespace std;

void quadrado(int *x) {
    *x = *x * *x;
}

int main() {
    int x;

    cin >> x;

    quadrado(&x);

    cout << x << endl;

    return 0;
}