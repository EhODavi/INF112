#include <iostream>

using namespace std;

void desalocamatriz(int **M, int m, int n) {
    for (int i = 0; i < m; i++) {
        free(M[i]);
    }
    
    free(M);
}

int main() {
    int m, n;

    cin >> m >> n;

    int **M = (int**) malloc (m * sizeof (int*));
    
    for (int i = 0; i < m; i++) {
        M[i] = (int *) malloc (n * sizeof (int));
    }

    desalocamatriz(M, m, n);

    return 0;
}