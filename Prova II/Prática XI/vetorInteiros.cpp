#include <iostream>
#include "vetorInteiros.h"

using namespace std;

VetorInteiros::VetorInteiros(int n, int valorPadrao)
{
    numeros = new int[n];

    for (int i = 0; i < n; i++)
    {
        numeros[i] = valorPadrao;
    }

    this->n = n;
}

VetorInteiros::VetorInteiros(int n)
{
    numeros = new int[n];

    for (int i = 0; i < n; i++)
    {
        numeros[i] = 0;
    }

    this->n = n;
}

VetorInteiros::~VetorInteiros()
{
    delete[] numeros;
    n = 0;
}

void VetorInteiros::mudaTamanho(int novoTamanho)
{
    int *novoNumeros = new int[novoTamanho];

    for (int i = 0; i < novoTamanho; i++)
    {
        if (i < getTamanho())
        {
            novoNumeros[i] = numeros[i];
        }
        else
        {
            novoNumeros[i] = 0;
        }
    }

    delete[] numeros;

    numeros = novoNumeros;
    n = novoTamanho;
}

void VetorInteiros::insereElementoFinal(int valor)
{
    mudaTamanho(getTamanho() + 1);
    numeros[getTamanho() - 1] = valor;
}

int VetorInteiros::getElemento(int pos) const
{
    if (pos >= 0 && pos < getTamanho())
    {
        return numeros[pos];
    }

    return -1;
}

void VetorInteiros::setElemento(int pos, int valor)
{
    if (pos >= 0 && pos < getTamanho())
    {
        numeros[pos] = valor;
    }
}

int VetorInteiros::procuraElemento(int valor) const
{
    for (int i = 0; i < getTamanho(); i++)
    {
        if (numeros[i] == valor)
        {
            return i;
        }
    }

    return -1;
}

int VetorInteiros::getTamanho() const
{
    return n;
}

void VetorInteiros::imprime() const
{
    cout << "[" << numeros[0];

    for (int i = 1; i < getTamanho(); i++)
    {
        cout << "," << numeros[i];
    }

    cout << "]" << endl;
}
