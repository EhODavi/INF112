#include <iostream>

using namespace std;

int maiorElemento(int *numeros, int n)
{
    if (n == 0) 
        return 0;
    
    int indiceA = n;
    int maiorA = numeros[indiceA];
    
    int indiceB = maiorElemento(numeros, n - 1);
    int maiorB = numeros[indiceB];
    

    if(maiorA > maiorB) 
        return indiceA;
    
    return indiceB;
    
}

int main()
{
    int n;

    cin >> n;

    int *numeros = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> numeros[i];
    }

    cout << maiorElemento(numeros, n - 1) << endl;

    delete[] numeros;

    return 0;
}