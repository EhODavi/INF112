#include <iostream>

using namespace std;

void solve(bool combs[], int begin, int n, int somaParcial, int k, int *numeros, bool &possuiSolucao)
{
    if (somaParcial > k || possuiSolucao == true)
        return;

    if (begin >= n)
    {
        if (somaParcial == k) possuiSolucao = true;
    }
    else
    {
        combs[begin] = 0;
        solve(combs, begin + 1, n, somaParcial, k, numeros, possuiSolucao);
        combs[begin] = 1;
        solve(combs, begin + 1, n, somaParcial + numeros[begin], k, numeros, possuiSolucao);
    }
}
int main()
{
    int n, k;

    cin >> k >> n;

    bool combs[n];
    int *numeros = new int[n];
    bool possuiSolucao = false;

    for (int i = 0; i < n; i++)
        cin >> numeros[i];

    solve(combs, 0, n, 0, k, numeros, possuiSolucao);

    if (possuiSolucao == true) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    delete[] numeros;
}