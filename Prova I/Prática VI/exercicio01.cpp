#include <iostream>

using namespace std;

/*
Rearranja o vetor v[1...m] de modo que o subvetor cuja
raiz eh p seja um heap. Supõe que os filhos de p no vetor
já satisfaçam as condições de heap
*/
void peneira(int *v, int p, int m)
{
    int maiorFilho = 2 * p + 1;

    while (maiorFilho <= m)
    {
        if (maiorFilho < m && v[maiorFilho + 1] > v[maiorFilho])
            maiorFilho++;
        //Ja temos um heap!
        if (v[p] > v[maiorFilho])
            return;
        // Vamos trocar p por seu maior filho
        // e continuar o algoritmo
        swap(v[p], v[maiorFilho]);
        p = maiorFilho;
        maiorFilho *= 2 + 1;
    }
}

void heapSort(int *v, int n)
{
    //Cria um heap em v
    for (int p = n / 2 - 1; p >= 0; p--)
        peneira(v, p, n);
    
    //Ordena v..
    for (int m = n - 1; m >= 1; m--)
    {
        swap(v[0], v[m]);
        peneira(v, 0, m - 1);
    }
}

int main()
{
    int N;

    cin >> N;

    int *v = new int[N];

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    heapSort(v, N);

    cout << v[0];

    for (int i = 1; i < N; i++)
    {
        cout << " " << v[i];
    }

    cout << endl;

    delete[] v;

    return 0;
}