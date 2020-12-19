#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    srand(time(NULL));
    
    int numTestes, limiteRand;

    if (argc != 3) {
        cerr << "Erro, use:./exercicio numTestes limiteRand" << endl;
        exit(1);
    }

    numTestes = atoi(argv[1]);
    limiteRand = atoi(argv[2]);
    
    int *vetor = new int[limiteRand];
    int *vetorauxiliar = new int[limiteRand];
    
    for (int i = 0; i < limiteRand; i++) {
        vetor[i] = i;
        vetorauxiliar[i] = 0;
    }
    
    for (int i = 0; i < numTestes; i++) {
        vetorauxiliar[rand() % limiteRand]++;
    }
    
    for (int i = 0; i < limiteRand; i++) {
        cout << vetor[i] << " " << vetorauxiliar[i] << "\n";
    }

    delete []vetor;
    delete []vetorauxiliar;

    cout << flush;

    return 0;
}