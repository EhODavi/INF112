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
    int* aux = new int[n];
    
    if (n <= 10)
    {
        insertionSort(v, n);
    } else {
        mergeSort(v, 0, n, aux);
    }
        
    delete[] aux;
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    
    int N;

    if (argc != 2) {
        cerr << "Erro, use:./exercicio01 N" << endl;
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