#include <iostream>

using namespace std;

long long int produtorio(int *numeros, int n)
{
    if (n == 0)
        return numeros[0];

    return numeros[n] * produtorio(numeros, n - 1);
}

int main()
{
    int n;

    cin >> n;

    int *numeros = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> numeros[i];
    }

    cout << produtorio(numeros, n - 1) << endl;

    delete[] numeros;

    return 0;
}