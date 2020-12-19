#include <iostream>

using namespace std;

int inversoes(int *v, int n)
{   
    int numInversoes = 0;
    
    for (int i = 1; i < n; i++)
    {
        // o arranjo entre as posicoes [0,i) já está ordenado
        int elemento = v[i];
        int j = i - 1;
        while (j >= 0)
        {
            if (v[j] > elemento)
                numInversoes++;
            j--;
        }
    }

    return numInversoes;
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    
    int N;

    if (argc != 2) {
        cerr << "Erro, use:./exercicio04 N" << endl;
        exit(1);
    }

    N = atoi(argv[1]);
    
    int *vetor = new int[N];
    
    for (int i = 0; i < N; i++) {
        vetor[i] = rand() % 100;
    }

    cout << inversoes(vetor, N) << endl;

    delete []vetor;

    return 0;
}