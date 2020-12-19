#include <iostream>

using namespace std;

void insertionSort(int *v, int n)
{
    for (int i = 1; i < n; i++)
    {
        // o arranjo entre as posicoes [0,i) já está ordenado
        int elemInserir = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > elemInserir)
        {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = elemInserir;
    }
}

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
    if (end - beg > 10)
        return;
    int pos = particiona(v, beg, end, beg);
    quickSort(v, beg, pos);
    quickSort(v, pos + 1, end);
}

void quickSort(int *v, int n)
{
    quickSort(v, 0, n);
    insertionSort(v, n);
}

int main(int argc, char **argv)
{
    srand(time(NULL));

    int N;

    if (argc != 2)
    {
        cerr << "Erro, use:./exercicio03b N " << endl;
        exit(1);
    }

    N = atoi(argv[1]);

    int *vetor = new int[N];

    for (int i = 0; i < N; i++)
    {
        vetor[i] = rand() % 10;
        cout << vetor[i] << " ";
    }

    cout << endl;

    quickSort(vetor, N);

    for (int i = 0; i < N; i++)
    {
        cout << vetor[i] << " ";
    }

    cout << endl;

    delete[] vetor;

    return 0;
}