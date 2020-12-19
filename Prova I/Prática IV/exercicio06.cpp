#include <iostream>

using namespace std;

int f(int *numeros, int n, int a) {
    if (n == 0)
        return numeros[0];

    return a * f(numeros, n - 1, a) + numeros[n];
}

int main()
{
    int n, a;

    cin >> n;

    int *numeros = new int[n + 1];

    for (int i = 0; i < n + 1; i++)
    {
        cin >> numeros[i];
    }

    cin >> a;

    cout << f(numeros, n, a) << endl;

    delete[] numeros;

    return 0;
}