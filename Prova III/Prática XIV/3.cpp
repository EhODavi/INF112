#include <iostream>

using namespace std;

void solve(bool combs[], int begin, int n, int somaParcial, int k, int *numeros, bool melhorSolucao[], int maiorSoma)
{
    if (somaParcial > k)
        return;

    if (begin >= n)
    {
        int soma = somaParcial;
        if ((soma > maiorSoma) && (soma <= k))
        {
            maiorSoma = soma;
            for (int i = 0; i < n; i++)
                melhorSolucao[i] = combs[i];
        }
    }
    else
    {
        combs[begin] = 0;
        solve(combs, begin + 1, n, somaParcial, k, numeros, melhorSolucao, maiorSoma);
        combs[begin] = 1;
        solve(combs, begin + 1, n, somaParcial + numeros[begin], k, numeros, melhorSolucao, maiorSoma);
    }
}
int main()
{
    int n, k;

    cin >> k >> n;

    bool combs[n];
    int *numeros = new int[n];
    bool melhorSolucao[n];

    for (int i = 0; i < n; i++)
        cin >> numeros[i];

    solve(combs, 0, n, 0, k, numeros, melhorSolucao, -1);

    for (int i = 0; i < n; i++)
    {
        if (melhorSolucao[i] == true)
        {
            cout << numeros[i] << " ";
        }
    }

    cout << endl;

    delete[] numeros;
}