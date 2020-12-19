#include <iostream>

using namespace std;

void printBinary(int x) {
    for (int i = 31; i >= 0; i--) {
        int k = x >> i;

        if (k & 1 == 1) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
}

void printVector(int *v, int n) {
    for (int i = 0; i < n; i++) {
        printBinary(v[i]);
        cout << " -> " << v[i] << endl;
    }
}

void radix(int* v, int n) {
    int* tmp = new int[n];
    int* u = tmp;
    int *w = v;
    
    for (int i = 0; i < 31; i++) {
        int k = 0;
        
        for (int j = 0; j < n; j++) {
            if (!(v[j] & (1 << i))) {
                tmp[k] = v[j];
                k++;
            }
        }

        for (int j = 0; j < n; j++) {
            if ((v[j] & (1 << i))) {
                tmp[k] = v[j];
                k++;
            }
        }

        swap(tmp, v);
    }

    for (int j = 0; j < n; j++) {
        w[j] = v[j];
    }

    delete[] u;
}

int main() {
    int n;

     cin >> n;

    int* v = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << "Vetor Original:" << endl;
    printVector(v, n);

    radix(v, n);

    cout << "Vetor Ordenado:" << endl;
    printVector(v, n);

    delete[] v;

    return 0;
}