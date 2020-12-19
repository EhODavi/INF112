#include <iostream>

using namespace std;

// está correta
// Veja que (1 << w) é uma máscara para o bit de índice w
int msdRadixPartition(unsigned int *v, int l, int r, int w) {
    int i = l, j = r;
    
    while (j != i) {
        while ((v[i] & (1 << w)) == 0 && (i < j)) i++;
        while ((v[j] & (1 << w)) != 0 && (j > i)) j--;
        
        swap(v[i], v[j]);
    }
    
    if ((v[r] & (1 << w)) == 0) j++;
    
    return j;
}

// Ordena o arranjo v[l], ..., v[r]
// w é o índice do bit sendo analisado
void msdRadixRec(unsigned int *v, int l, int r, int w) {
    if (r <= l || w < 0)
        return;
    
    int pos = msdRadixPartition(v, l, r, w);
    
    msdRadixRec(v, l , pos - 1, w - 1);
    msdRadixRec(v, pos, r, w - 1);
}

void msdRadixSort(unsigned int *v, int n) {
    msdRadixRec(v, 0, n-1, 31);
}

// está correta
int main() {
    int n;
    int i;
    
    cin >> n;
    
    unsigned int *x = new unsigned int[n];
    
    for (i = 0; i < n; i++)
        cin >> x[i];
    
    msdRadixSort(x, n);
    
    for (i = 0; i < n; i++)
        cout << x[i] << endl;
    
    delete []x;
    
    return 0;
}