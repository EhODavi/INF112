#include <iostream>

using namespace std;

/*
Rearranja o vetor v[1...m] de modo que o subvetor cuja
raiz eh p seja um heap. Supõe que os filhos de p no vetor
já satisfaçam as condições de heap
*/
void peneira(int *v, int p, int m)
{
    int menorFilho = 2 * p + 1;

    while (menorFilho <= m)
    {
        if (menorFilho < m && v[menorFilho + 1] < v[menorFilho])
            menorFilho++;
        //Ja temos um heap!
        if (v[p] < v[menorFilho])
            return;
        // Vamos trocar p por seu maior filho
        // e continuar o algoritmo
        swap(v[p], v[menorFilho]);
        p = menorFilho;
        menorFilho *= 2 + 1;
    }
}

int* heapSort(int *v, int n, int k)
{
    int *vetorAuxiliar = new int[k];
    //Cria um heap em v
    for (int p = n / 2 - 1; p >= 0; p--)
        peneira(v, p, n);
    
    //Ordena v..
    int contador = 0;

    for (int m = n - 1; m >= 1; m--)
    {
        if (contador == k) break;
        vetorAuxiliar[contador] = v[0];
        swap(v[0], v[m]);
        contador++;
        peneira(v, 0, m - 1);
    }

    if (k == n) {
        vetorAuxiliar[contador] = v[0];
    }

    return vetorAuxiliar;
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    
    int N, K;

    if (argc != 3) {
        cerr << "Erro, use:./exercicio02 N K" << endl;
        exit(1);
    }

    N = atoi(argv[1]);
    K = atoi(argv[2]);
    
    int *vetor = new int[N];
    int *vetorAuxiliar;
    
    for (int i = 0; i < N; i++) {
        vetor[i] = rand() % 100;
        cout << vetor[i] << " ";
    }

    cout << endl;

    vetorAuxiliar = heapSort(vetor, N, K);

    for (int i = 0; i < K; i++) {
        cout << vetorAuxiliar[i] << " ";
    }

    cout << endl;

    delete []vetor;
    delete []vetorAuxiliar;

    return 0;
}