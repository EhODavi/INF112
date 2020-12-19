#include <iostream>

using namespace std;

void leiaInteiros(int &a, int &b) {
    cin >> a >> b;
}

void leiaInteiros(int *a, int *b) {
    cin >> *a >> *b;
}

int main() {
    int a, b, c, d;

    leiaInteiros(a, b);

    cout << a << " " << b << endl;

    leiaInteiros(&c, &d);

    cout << c << " " << d << endl;

    return 0;
}