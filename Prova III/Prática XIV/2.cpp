#include <iostream>

using namespace std;

void lsdRadixSort(unsigned int *v, int n)
{
    unsigned int *vaux, *paux, mask;
    int i, pos, flag;
    // vetor auxiliar
    vaux = new unsigned int[n];

    for (mask = 1, flag = 1; mask != (1 << 31); mask <<= 1)
    {
        for (i = pos = 0; i < n; i++)
            if (!(v[i] & mask))
                vaux[pos++] = v[i];
        for (i = 0; pos < n; i++)
            if (v[i] & mask)
                vaux[pos++] = v[i];
        paux = v;
        v = vaux;
        vaux = paux;
        flag = !flag;
    }

    if (!flag)
    {
        for (i = 0; i < n; i++)
            vaux[i] = v[i];
        delete[] v;
        v = vaux;
    }
    else
    {
        delete[] vaux;
    }
}
int main()
{
    int n;
    int i;

    cin >> n;

    unsigned int *x = new unsigned int[n];

    for (i = 0; i < n; i++)
        cin >> x[i];

    lsdRadixSort(x, n);

    for (i = 0; i < n; i++)
        cout << x[i] << endl;

    delete[] x;

    return 0;
}