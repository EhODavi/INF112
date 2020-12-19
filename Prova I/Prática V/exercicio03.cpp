#include <iostream>

using namespace std;

int* SelectionSort(int *v, int n, int k) {
    int *vetorAuxiliar = new int[k];

    for (int i = 0; i < k; i++) {
        // acha a posicao do menor elemento
        // entre as posições (i) e (n-1)
        int posMenor = i;
        for (int j = i+1; j < n; j++)
            if (v[j] < v[posMenor])
                posMenor = j;

        // troca o menor elemento (que está na
        // posicao posMenor) com o elemento (i)
        int aux = v[i];
        v[i] = v[posMenor];
        v[posMenor] = aux;
        
        vetorAuxiliar[i] = v[i];
    }

    return vetorAuxiliar;
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    
    int N, K;

    if (argc != 3) {
        cerr << "Erro, use:./exercicio03 N K" << endl;
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

    vetorAuxiliar = SelectionSort(vetor, N, K);

    for (int i = 0; i < K; i++) {
        cout << vetorAuxiliar[i] << " ";
    }

    cout << endl;

    delete []vetor;
    delete []vetorAuxiliar;

    return 0;
}
