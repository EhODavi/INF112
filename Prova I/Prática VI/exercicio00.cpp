#include <iostream>

using namespace std;

/*
Rearranja o vetor v[1...m] de modo que o subvetor cuja
raiz eh p seja um heap. Supõe que os filhos de p no vetor
já satisfaçam as condições de heap
*/
void peneira(int *v, int p, int m) {
    int maiorFilho = 2 * p;
    
    while (maiorFilho <= m) {
        if (maiorFilho < m && v[maiorFilho + 1] > v[maiorFilho])
            maiorFilho++;
        //Ja temos um heap!
        if (v[p] > v[maiorFilho])
            return;
        // Vamos trocar p por seu maior filho
        // e continuar o algoritmo
        swap(v[p], v[maiorFilho]);
        p = maiorFilho;
        maiorFilho *= 2;
    }
}

void heapSort(int *v, int n) {
    int *vetorAuxiliar = new int[n + 1];

    for(int i = 0; i < n; i++) {
        vetorAuxiliar[i + 1] = v[i];
    }

    //Cria um heap em v
    for (int p = n / 2; p >= 1; p--)
        peneira(vetorAuxiliar, p, n);
    //Ordena v..
    for (int m = n; m >= 2; m--)
    {
        swap(vetorAuxiliar[1], vetorAuxiliar[m]);
        peneira(vetorAuxiliar, 1, m - 1);
    }

    for (int i = 0; i < n; i++) {
        v[i] = vetorAuxiliar[i + 1];
    }

    delete[] vetorAuxiliar;
}

int main() {
    int N;

    cin >> N;

    int* v = new int[N];

    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    heapSort(v, N);

    cout << v[0];
    
    for (int i = 1; i < N; i++) {
        cout << " " << v[i];
    }

    cout << endl;

    delete[] v;

    return 0;
}