#include <iostream>

using namespace std;

// particiona o subvetor v[beg, ..., end - 1]
int particiona(int *v, int beg, int end, int pivo)
{
    int valorPivo = v[pivo];
    //colocamos o pivo temporariamente na ultima posição
    swap(v[pivo], v[end - 1]);
    // ao acharmos um elemento menor do que o pivo, vamos coloca-lo
    // na posicao "pos"
    int pos = beg;

    for (int i = beg; i < end - 1; i++)
    {
        if (v[i] < valorPivo)
        {
            swap(v[pos], v[i]);
            pos++;
        }
    }
    //coloque o pivo depois do ultimo elemento menor que ele
    swap(v[pos], v[end - 1]);

    return pos;
}

void quickSort(int *v, int beg, int end)
{
    if (beg == end)
        return;
    
    int pos = particiona(v, beg, end, beg);
    quickSort(v, beg, pos);
    quickSort(v, pos + 1, end);

}

void quickSort(int *v, int n)
{
    quickSort(v, 0, n);
}

int main(int argc, char **argv)
{
    srand(time(NULL));

    int N;

    if (argc != 2)
    {
        cerr << "Erro, use:./exercicio04a N " << endl;
        exit(1);
    }

    N = atoi(argv[1]);

    //int *vetorCrescente = new int[N];
    //int *vetorDecrescente = new int[N];
    int *vetorAleatorio = new int[N];

    /*for (int i = 0; i < N; i++)
    {
        vetorCrescente[i] = i;
        cout << vetorCrescente[i] << " ";
    }*/

    
    /*
    int j = 0;

    for (int i = N - 1; i >= 0; i--)
    {
        vetorDecrescente[j] = i;
        cout << vetorDecrescente[j] << " ";
        j++;
    }
    */
    
    for (int i = 0; i < N; i++)
    {
        vetorAleatorio[i] = rand() % 1000000;
        cout << vetorAleatorio[i] << " ";
    }

    cout << endl;

    //quickSort(vetorCrescente, N);
    //quickSort(vetorDecrescente, N);
    quickSort(vetorAleatorio, N);

    /*
    for (int i = 0; i < N; i++)
    {
        cout << vetorCrescente[i] << " ";
    }
    */

    /*
    for (int i = 0; i < N; i++)
    {
        cout << vetorDecrescente[i] << " ";
    }
    */

    
    for (int i = 0; i < N; i++)
    {
        cout << vetorAleatorio[i] << " ";
    }

    cout << endl;

    //delete[] vetorCrescente;
    //delete[] vetorDecrescente;
    delete[] vetorAleatorio;

    return 0;
}