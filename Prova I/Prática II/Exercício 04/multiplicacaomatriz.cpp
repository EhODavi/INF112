#include <iostream>

using namespace std;

int** alocarMatriz (int m, int n) {
    int **matriz; 

    if (m < 1 || n < 1) { 
        cout << "** Erro: Parametro invalido **\n";
        return NULL;
    }
    
    matriz = new int*[m];

    if (matriz == NULL) {
        cout << "** Erro: Memoria Insuficiente **\n";;
        return NULL;
    }
    
    for (int i = 0; i < m; i++) {
        matriz[i] = new int[n];
    
        if (matriz[i] == NULL) {
            cout << "** Erro: Memoria Insuficiente **\n";

            return (NULL);
        }
    }

    return matriz; 
}

int** desalocarMatriz (int m, int n, int** matriz) {
    if (matriz == NULL) return NULL;
    
    if (m < 1 || n < 1) { 
        cout << "** Erro: Parametro invalido **\n";
        return matriz;
    }

    for (int i = 0; i < m; i++) delete[] matriz[i]; 
    
    delete[] matriz;
    
    return NULL;
}

int** multiplicaMatriz (int** matriz1, int m, int n, int** matriz2, int x, int y) {
    if (n == x && matriz1 != NULL && matriz2 != NULL && m > 1 && n > 1 && x > 1 && y > 1) {

        int** matriz3 = alocarMatriz(m, y);

        if (matriz3 != NULL) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < y; j++) {
                    int somatorio = 0;
                    
                    for (int k = 0; k < n; k++) {
                        somatorio += matriz1[i][k] * matriz2[k][j];
                    }
                    
                    matriz3[i][j] = somatorio; 
                }
                
            }

            return matriz3;
        }

    }

    return NULL;
}

void escreverMatriz (int** matriz, int m, int n) {
    if (matriz != NULL && m > 1 && n > 1) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << matriz[i][j] << " ";
            }

            cout << endl;
        }
    }
}

void lerMatriz (int** matriz, int m, int n) {
    if (matriz != NULL && m > 1 && n > 1) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matriz[i][j];
            }
        }
    }
}

int main() {
    int **matriz1, **matriz2, **matriz3;
    int m, n, x, y;

    cin >> m >> n;

    matriz1 = alocarMatriz(m, n);

    lerMatriz(matriz1, m, n);

    cin >> x >> y;

    matriz2 = alocarMatriz(x, y);

    lerMatriz(matriz2, x, y);

    matriz3 = multiplicaMatriz(matriz1, m, n, matriz2, x, y);

    escreverMatriz(matriz3, m, y);

    desalocarMatriz(m, n, matriz1);
    desalocarMatriz(x, y, matriz2);
    desalocarMatriz(m, y, matriz3);

    return(0);
}