#include <iostream>

using namespace std;

void merge(int *v, int p, int q, int r, int *aux)
{
    int tam = r - p;
    int i = p; //cursor 1
    int j = q; //cursor 2
    int k = 0; //cursor para aux
    while (i < q && j < r)
    {
        if (v[i] <= v[j])
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];
    }
    while (i < q)
        aux[k++] = v[i++];
    while (j < r)
        aux[k++] = v[j++];
    for (k = 0; k < tam; k++)
        v[p + k] = aux[k];
}

/* Ordena o vetor v entre as posicoes p e r-1 */
void mergeSort(int *v, int p, int r, int *aux)
{
    // com um elemento, já está ordenado
    if (p < r - 1)
    {
        int meio = (p + r) / 2;
        mergeSort(v, p, meio, aux);
        mergeSort(v, meio, r, aux);
        merge(v, p, meio, r, aux); //intercala
    }
}

void mergeSort(int *v, int n)
{
    int *aux = new int[n];
    mergeSort(v, 0, n, aux);
    delete[] aux;
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    
    int N;

    if (argc != 2) {
        cerr << "Erro, use:./exercicio00 N" << endl;
        exit(1);
    }

    N = atoi(argv[1]);
    
    int *vetor = new int[N];
    
    for (int i = 0; i < N; i++) {
        vetor[i] = rand() % 100;
    }

    mergeSort(vetor, N);

    delete []vetor;

    return 0;
}