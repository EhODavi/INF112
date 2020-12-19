#ifndef VETORINTEIROS_H
#define VETORINTEIROS_H

class VetorInteiros
{
private:
    int *numeros, n;

public:
    VetorInteiros(int n, int valorPadrao);
    VetorInteiros(int n);
    ~VetorInteiros();
    void mudaTamanho(int novoTamanho);
    void insereElementoFinal(int valor);
    int getElemento(int pos) const;
    void setElemento(int pos, int valor);
    int procuraElemento(int valor) const;
    int getTamanho() const;
    void imprime() const;
};

#endif